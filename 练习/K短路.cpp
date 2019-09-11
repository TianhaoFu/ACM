#include<iostream>
#include<queue>
#include<cstring>
#incldue<cstdio>
#include<vector>
#defing MAXN 1001
using namespace std;
int N,M;
int S,T,K;
bool used[MAXN];
int times[MAXN];
struct node
{
	int k,g,h;
	bool operator<(node e)
	return g+h>e.g+e.h;
}
priority_queue<node> pq;
bool used[MAXN]={0}; 
vector < vector < node> > G;
int dist[MAXN];
void djistra()
{
	int i,j,k,p;
	pq.push_back(T);
	while(!pq.empty())
	{
		p = pq.top();
		dist[p.k] = p.w;
		pq.pop();
		if(used[p.k])
			continue;
		used[p.k] = =True;
		for( i = 0 ; i <G[p.k].size() ; i ++ )
		{
			node q;
			q.k = G[p.k][i].k
			if(used[q.k])
				continue
			q.w = p.w + v[p.k][i].w ;
			pq.push(q);
		}
	}
}

int Astar()
{
	noden,temp;
	while(!pq.empty()) pq.pop();
	n.k = S;
	n.g = n.h = 0;
	pq.push(n);
	while(!pq.empty())
	{
		n = pq.top();
		pq.pop();
		times[n.k]++;
		if(times[n.k] == K && n.k == T)
			return n.h + n.g;
		if(times[n.k] > K)
			continue;
		for(int j = 0 ; j < G[n.k].size() ;j ++)
		{
			u = G[n.k][j].k;
			temp.h = n.h + 
		}
		
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0 i < N ; i ++ )
	
	
}
