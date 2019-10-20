#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue> 
using namespace std;
//给定结点权重 边的权重 
//给定数据的最大载油量 起点 终点
//求一个最短路 使得经过所有的城市花费最小  

const int N = 1000 + 100 ,  M = 10000 + 100 , c = 100 + 100 ;
//邻接表 
struct node{
	int to , nxt , w ;
}e[M<<1];
int head[N] , tot ;

void add( int u , int v , int w )
{
	e[++tot] = (node){v , head[u] , w} ;
	head[u] = tot ;
}

int p[N] ;
int fa[N] ; 
//并查集维护连通性 
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

struct poi{
	int vec , fuel , d ;
};

priority_queue<poi> q ;

bool operator < ( const poi& a , const poi& b){
	return a.d > b.d
}

bool vis[C][N] ; 
int dis[C][N] ;
 
void BFS(int s ,int t , int c )
{
	while(q.size()) 
	q.pop() ; 
	
	memset(vis , 0 , sizeof(vis)) ; 
	memset(dis , 0x3f , sizeof(dis)) ; 
	q.push((poi){s , 0 , 0}) ; 
	vis[0][s] = 1 ; 
	vis[0][s] = 0 ;
	
	while(q.size())
	{
		poi tmp = q.top() ; 
		q.pop() ;
		int u = tmp.vec , rest = tmp.fuel , dist = tmp.d ;
		
		if( u == t )
		{
			printf("%d\n" , dist ) ; 
			return ;
		}
		
		vis[rest][u] = 1 ;
		for( int i = head[u] ; i ; i = e[i].nxt)
		{
			int v = e[i].to ; 
			if(rest < c && !vis[rest+1][u] && dis[rest+1][u] > dist+p[u])
			{
				q.push((poi){w,rest+!,dist+p[u]}) ;
			 	dis[rest-e[i].w][v] = dist ;
			}
		}
	}
	printf("impossible\n") ;
}

int main()
{
	int n , m ;
	scanf("%d%d" , &n , &m );
	for(int i = 0 ; i < n ; i ++ )
	{
		scanf("%d" , &p[i]) ;
	}
	
	for( int i = 1 ; i <= n ; i ++ )
	fa[i] = i ;
	for( int i = 1 ; i <= m; i ++ )
	{
		int u ,v ,w ;
		scanf("%d%d%d" , &u , &v , &w) ;
		add(u , v , w) ;
		add(v , u , w) ;
		if(find(u) != find(v))
		fa[find(u)] = find(v) ;
	}
	
	int q ; 
	scanf("%d" , &q) ;
	for(int i =1 ; i <= q ;i ++ )
	{
		int c , x , y ;
		scanf("%d%d%d" , &c , &x , &y) ;
		if(find(x) != find(y))
		{
			printf("impossible\n") ;
			continue ;
		}
		BFS(x ,y , c) ;
	 } 
	 return 0 ;
}
