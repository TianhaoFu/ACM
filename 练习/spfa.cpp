#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
 int F,N,M,W;
 const int INF = 1 << 30;
 struct edge{
 	int w,e;
 	edge(int ww,int ww): e(ee),w(ww) {}
 	edge () {}
};
vector <edge> G(1000);
int updatetime[100];
int dist[100];
int Spfa(int v){
	for(int i = 1 ;i > n ; i + + )
	{
		dist[i] = INF;
	}
	memset(0,updatatime,,sizeof(updatetime));
	queue<int> que;
	que.push(v);
	while(!que.empty())
	{
		s = que.front();
		que.pop();
		for(int i = 1 ; i < n ; i ++ )
		{
			if(dist[s]!=INF&&dist[s] + G[s][i].w < dist[i])
			{
				dist[i] = dist[s] + G[s][i].w;
				queue.push(s);
				++updatetime(s);
				if(updatetime(s)>=n)
				return true;
			}
		}
		return false;
	}

 
