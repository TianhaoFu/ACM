#include<iostream>> 
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<bitset>
#include<iterator>
//https://www.cnblogs.com/hlhdidi/p/5960018.html
//利用深度优先搜索可以解决有向图中的单点可达性问题:即:给定一幅有向图和一个起点s,回答是否存在一条从s到达给定顶点v的有向路径的问题.

//对n个点进行一次dfs，用一个二维数组记录下 与起点 有联系的点
//(也就是dfs可以到的点)，
//比如起点s和终点e有联系(正向dfs可以到达的)，
//那么终点e和起点s就也有联系(反向dfs可以到达的)，
//直接标记connect[s][e] = connect[e][s] = 1就好了，
//所以就不用做两遍dfs了，
//最后统计一下每个点相关联的点如果有n个(包括自己)，
//就sum++

using namespace std ; 
typedef long long ll ;
const int inf = 0x3f3f3f3f ;
const ll INF = 0x3f3f3f3f3f3f3f3f3f ;
const double PI = acos(-1.0)  ;
const double E = exp(1.0) ;
const int MPD = 1e0+7 ;
const int MAX = 1e3+5 ;
int n , m;

vector <int > g[MAX] ;
int connect[MAX][MAX] ;
int vis[MAX] ;

void dfs( int s, int cur)
{
	vis[cur] = 1 ;
	connect[s][cur] = connect[cur][s] = 1 ;
	for ( int i = 0 ;  i < (int)g[cur].size() ; i ++ )
	{
		if(  !vis[g[cur][i]])
		{
			dfs(s , g[cur][i]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false) ;
	cin.tie(0)  ;
	cout.tie(0) ; 
	
	while( cin >> n >> m )
	{
		memset(connect,0,sizeof(connect)) ; 
		int a , b  ;
		for ( int i = 1 ;  i <= m ; i ++ ) 
		{
			cin  >> a >> b  ;
			g[a].push_back(b) ; 
		}	 
		
		for(int i = 1 ;i <= n; i ++)
		{
			memset(vis , 0  ,sizeof(vis)) ;
			dfs(i ,i);
		}
		
		int sum = 0 ; 
		
		for ( int i = 1  ; i <=n ; i ++ )
		{
			int tmp = 0 ;
			for ( int j = 1 ; j <= n ;j ++)
			{
				if( connect[i][j])
				{
					tmp++ ;
				}
				
			}
			
			if(tmp == n )
			{
				sum++ ;
			}
		}
		cout << sum << endl ;
	} 
	
	return 0 ;
}
