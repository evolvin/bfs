#include<bits/stdc++.h>
using namespace std;
int bfs(int step[],bool vis[],int n,int m)
{
	queue<int>q;
	q.push(n);
	vis[n]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x==m)
		return step[x]; //checking of required number and returning answer
        int z=x/1000;  // checking prime with change of 1st digit
        for(int i=1;i<10;i++)
        {
        	int l=x-z*1000+i*1000;
        	if(vis[l]==false)
        	{
        		q.push(l);
        		vis[l]=true;
        		step[l]=step[x]+1;
			}
		}
		z=(x/100)%10;  // checking prime number with change of 2nd digit
		for(int i=0;i<10;i++)
		{
			int l=x-z*100+i*100;
			if(vis[l]==false)
			{
				q.push(l);
				vis[l]=true;
				step[l]=step[x]+1;
			}
		}
		z=(x/10)%10;  // checking prime number with change of 3rd digit
		for(int i=0;i<10;i++)
		{
			int l=x-z*10+i*10;
			if(vis[l]==false)
			{
				q.push(l);
				vis[l]=true;
				step[l]=step[x]+1;
			}
		}
		z=x%10; // checking prime with change of 4th digit
		for(int i=0;i<10;i++)
		{
			int l=x-z+i;
			if(vis[l]==false)
			{
				q.push(l);
				vis[l]=true;
				step[l]=step[x]+1;
			}
		}
	}
}
int main()
{
	int t,n,m;
	cin>>t;
	int step[10000];
	bool vis[10000];
	while(t--)
	{
		cin>>n>>m;
		memset(step,0,sizeof(step));// initializing step array with 0 step
		for(int i=0;i<1000;i++)
		  vis[i]=true;
		for(int i=1000;i<=9999;i++)// storing of prime number of 4 digits
		{
			int flag=0;
			for(int j=2;j<=sqrt(i);j++)
			{
				if(i%j==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			 vis[i]=false;
			else
			 vis[i]=true;
		}
		int x=bfs(step,vis,n,m);
		cout<<x<<endl;
	}
}
