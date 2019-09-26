#include<iostream>
#include<cstdio>
#include<vector>
#define inf 1<<30
#define MAXN 1000
#include<algorithm>

using namespace std;
int ans;
struct Edge
{
	int u , v , w; 
	Edge(int uu , int vv , int ww):u(uu) , v(vv) , w(ww){} 
	Edge(){}
	bool operator < (const  Edge e)
	{
		return w < e.w;
	}
};
vector < Edge > edges; 
int parent[MAXN];
int visited[MAXN][MAXN];

int GetRoot(int a)
{
	return parent[a]==a?a:parent[a]=GetRoot(parent[a]);
}

void Merge(int a , int b)
{
	int p1 = GetRoot(a);
	int p2 = GetRoot(b);
	if(p1 == p2)
		return;
	parent[p2] = p1;
}

void kruskal(int start)
{
	int i , min = inf , max = -1 , u , v , w , done = 0;
	int n = edges.size();
	
	for( i = 0 ; i < n ; i ++)
		parent[i] = i;
//	for( i = 0 ; i < n ; i ++)
//		cout << "parent[i]" << parent[i] << endl;	
//	for( int j = 0 ; j < edges.size() ; j ++ )
//	cout << edges[j].u << edges[j].v << edges[j].w << endl ;
	for( i = start ; i < n ; i ++ )
	{
		u = edges[i].u ;
		v = edges[i].v ;
		w = edges[i].w ;
		if(GetRoot[u] != GetRoot[v])
		{
//			if(w < min) min = w;
//			if(w > max) max = w;
			Merge(u,v);
			done ++ ;
			if(done == n-1 ) break;
		}
		cout << "u " << u << "v " << v << endl;
//		for( int j = 0 ; j < edges.size() ; j ++ )
//			cout << edges[j].u << edges[j].v << edges[j].w << endl ;
		
	}
	if(done!=(n-1)) return ;
	if(ans > edges[i].w-edges[start].w) ans = max - min ;
}
bool work()
{
	
	int i ;
	for( i = 1 ; i < edges.size(); i ++ )
		{
			ans = inf ;
			kruskal(i);
		}
	if(ans == inf) return false;
	return true; 
}
int main()
{
	int i,n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if( n == 0 && m == 0 )
			break;
		Edge temp;
		for(i = 0 ; i < m ; i ++)
		{
			scanf("%d%d%d",&temp.u , &temp.v,&temp.w);
			edges.push_back(temp);
		}
	sort(edges.begin() , edges.end());
	if(!work()) printf("-1\n");
	else printf("%d\n",ans) ;
	}
	return 0;
}
