#include<bits/stdc++.h>
using namespace std;
void bfs(int f,int s,int g,int u,int d)
{
   	int step[1000000];
	memset(step,0,sizeof(step));
	queue<int>q;
    q.push(s);
	step[s]=1;
	while(!q.empty())
	{
	  int x=q.front();
	  q.pop();
	  if(x==g)
	  {
	   cout<<step[x]-1<<endl;
	   return;
      }
	  if(x+u<=f && step[x+u]==0)
	  {
	  	q.push(x+u);
	  	step[x+u]=step[x]+1;
	  }
	  if(x-d>=0 && step[x-d]==0)
	  {
	    q.push(x-d);
		step[x-d]=step[x]+1;	
	  }	
	}
	if(step[g]==0)
	cout<<"use the stairs"<<endl;
}
int main()
{
	int f,s,g,u,d;
	cin>>f>>s>>g>>u>>d;
	bfs(f-1,s-1,g-1,u,d);  //subtracting 1 to start with 0 in step array
}
