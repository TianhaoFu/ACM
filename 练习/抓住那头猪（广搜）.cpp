#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std; 
const int MAXN = 1000;
int visited[MAXN+10];
struct step{
	int x;
	int steps;
	step(int xx ,int s): x(xx),steps(s){}
};
queue<step> q;
int main()
{
	int N ,K ;
	cin >> N>>K;
	memset(visited,0,sizeof(visited));
	q.push(step(N,0));
	visited[N] = 1;
	while(!q.empty())
	{
		
		step s = q.front();
		if( s.x == K)
		{
			cout << s.steps<<endl;
			return 0;
		}
		
		else 
		{
		if( s.x - 1 >= 0 && !visited[s.x - 1]){
			q.push(step(s.x-1,s.steps+1));
			visited[s.x-1] = 1;
	     }
		 if( s.x * s.x >= 0 && !visited[s.x * s.x])
		{
			q.push(step( s.x*s.x,s.steps+1));
			visited[s.x*s.x] = 1;
		}
		q.pop();
	}
	
}
return 0;
}
