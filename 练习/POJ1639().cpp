#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 22 ;
struct Edge {
	int u , v , d ;
	Edge(){}
	Edge(int a , int b , int  c) : u(a) , d(c) {}
	bool operator < (const Edge &e) const{
	return d < e.d;}
};
int n , m , k ;
int cnt ;
int ans ;
int parent[MAXN];
map <string,int> nodes;
vector < Edge > edges;
int g[MAXN][MAXN] ;
bool tree[MAXN][MAXN];
int minEdge[MAXN];

int find (  int p )
{
	if ( p == parent[a]) 
	return parent[p];
	return parent[p] = find(parent[p]);
}

void un(int p , int q)
{
	parent[find(p)] = find (q);
}

void kruskal()
{
	
	sort(edges.begin(),edges.end());
	
	for( int i = 0 ; i < edges.size() ; i ++ )
	{
		int p = edges[i].u ;
		int q = edges[i].v ;
		if(p == 1 || q == 1)
		continue;
		if(find(p) != find(q))
		{
			un(p,q) ;
			tree[p][q] = tree[q][p] = 1;
			ans += edges[i].d ;
		}
	}
}

void dfs( int cur ; int pre)
{
	for( int i = 0 ; i <= cnt ; i ++ )
	{
		if(i == pre || !tree[cur][i])
			continue;
		if(dp[i].d == -1)
		{
			if(dp[cur].d > g[cur][i])
				dp[i] = dp[cur];
			else 
			{
				dp[i].u = cur ;
				dp[i].v = i;
				dp[i].d = g[cur][i];
			}
		}
		dfs(i,cur);
	}
}

void slove()
{
	int keyPoint[MAXN];
	memset(keyPoint , 0 , sizeof(keyPoint));
	
	for(int i = 0 ; i <= cnt ; i ++ )
	{
		if(g[1][i] != INF)
		{
			int color = find(i);
			if(minEdge[color] > g[1][i])
			{
				minEdge[color] = g[1][i];
				keyPoint[color] = i;//每一棵生成树中距离1点最近的点 
			}
		}
	}
	
	for ( int i = 1 ; i <= cnt ; i ++ )
	{
		if(minEdge[i] != INF)
		{
			m++ ;
			tree[1][keyPoint[i]]=tree[keyPoint[i]][1] = 1;
			ans += g[1][keyPoint[i]];
		}
	}
	//加入每一棵生成树中距离1点最近的点 
	for( int i = m+1 ; i <= k ; i ++ )
	{
		memset(dp , -1 , sizeof(dp));
		dp[1].d = -INF ;
		//加入每一棵子生成树中能够到达v0的非树枝边 
//		必然会形成环 
//		去掉此生成树中的可到达v0路径中的权值最大的边
//	   （去掉环中全职最大的边） 
		for( int j = 2 ; j <= cnt ; j++ )
		{
			if(tree[1][j])
				dp[j].d = -INF ; 
			dfs(1,-1);
			int idx , minnum = INF ;
			for( int j = 2 ; j <= cnt ; j ++ )
			{
				if( minnum > g[1][j] - dp[j].d)
				{
					minnum = g[1][j] - dp[j].d ; 
					idx = j;
				}
			}
			
			if(minnum >=0)
				break; 
			tree[1][idx] = tree[idx][1] = 1;
			tree[dp[idx].u][dp[idx.v]] = tree[dp[idx].v][dp[idx].u] = 1 ;
			ans += minnum;
		}
	}
}

void init()
{
	memset(g , INF, sizeof(g));
	memset(tree , 0 , sizeof(tree));
	memset(minEdge , INF , sizeof(minEdge));
	m = 0 ; 
	cnt = 1 ;
	ans = 0 ;
	nodes["Park"] = 1;
	for (int i = 0 ; i < MAXN ; i++ )
	parent[i] = i; 
}

int main()
{
	scanf("%d" , &n) ; 
	string s1 , s2 ; 
	int d ; 
	init() ; 
	for( int i = 1 ; i <= n ; i++ )
	{
		cin >> s1 >> s2 >> d ;
		if( !nodes[s1])
			nodes[s1] = ++cnt ; 
		if( !nodes[s2])
			nodes[s2] = ++cnt ; 
		int u = nodes[s1] ; 
		int v =nodes[s2] ;
		edges.push_back(Edge(u,v,d)) ; 
		g[u][v] = g[v][u] = min(g[u][v] , d);//存储图 
	}
	
	scanf("%d" , &k);
	kruskal();
	solve();
	print("Total miles driven: %d\n" , ans) ;
	return 0;
	
}
