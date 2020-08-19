#include<iostream>
#include<vector>
using namespace std;
struct edge{
	int s,e,w;
	edge(int ss,int ee , int ww) s(ss),e(ee),w(ww) {}
	edge () {}
};
int bellman_ford(int v)
{
	for (int  i = 0 i < n ;i ++ )
	{
		dist [i] = INF ;
	}
	for (int  k =1 ; k < n ; k ++ )
	{
		for( int  i = 1 ; i < = n ;i ++ )
		{
			int s = edge[i].s;
			int e = edge[i].e; 
				if(dist[s]!=INF&&ist[s]+edge[i].w<dist[e])
				{
					dist[e] = dist[s] + edge[i].w;
				}
		}
	}
	for(int i = 0 ; i < n ; i ++ )
	{
		int s = edge[i].s;
		int e = edge[i].e;
		if(dist[e] > dist[s] + edge[i].w)
			return true;
	}
}return false;
