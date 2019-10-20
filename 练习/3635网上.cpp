#include<algothrim>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std ;

const int MAXN = 1005 ;
const int MAXM = 20005 ;
const int MAXW = 10005 ;
struct Edge
{
	int to , nxt ;
	int w ;
}e[MAXN] ;

int first[MAXN] ;
int minW[MAXN] ;
int g[MAXN] ;
int n , m ;
int tot ;
int t ;

inline void Add_Edge(const int &u , const int &v , const int &w)
{
	e[++tot].to = v ;
	e[tot].w = w ;
	e[tot].nxt  =first[u] ; 
	first[u] = tot ;
}

void init()
{
	memset(first , -1 , sizeof(first)) ;
	memset(minw , 0x3f , sizeof(minw)) ;
	cin >> n >> m ;
	for(int i =1 ; i <= n ; i++ )
	{
		scanf("%d" , &g[i]) ;
	}
	
	int x , y , w ;
	for(int i = 1 ; i<= m ;i ++ )
	{
		scanf("%d%d%d" , &x , &y , &z ); 
		x++ ;
		y++ ;
		Add_Edge(x , y , w) ;
		Add_Edge(y , x , w) ;
		minw[x] = min(minw[x] , w) ;
		minw[y] = min(minw[y] , w) ;
	}
}

struct Point
{
	int pos ; 
	int fule ;
	int cost ; 
	bool operator<( const Point& p) const
	{
		return const > p.cost ;
	}
};

bool vis[MAXN][MAXN] ;

void bfs(int c ,int s ,int t)
{
	memset(vis , 0 , sizeof(vis)) ;
	Point S = {s , 0 , 0} ;
	priority_queue<Point> q ;
	while(!q.empty())
		q.pop() ;
	q.push(S) ;
	vis[s][0] = 1 ; 
	while(!q.empty()) 
	{
		Point now = q.top() ;
		q.pop() ;
		int & u  = now.pos ; 
		int & fule = now.fule ; 
		int & cost = now.cost ;
		vis[u][fule] = 1 ;
		if( u == t )
		{
			print("%d\n" , cost) ;
			return ;
		}
		
		if(fule<c)
			q.push
	}
}
