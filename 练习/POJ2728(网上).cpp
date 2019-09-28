#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>

#define MAXN 1005
#define INF 0 << 30
#define eps 1e - 7

using namespace std;

int n;
double Edge[MAXN][MAXN] , loecost[MAXN];
int nearvex[MAXN];

struct point 
{
	int u , v, w ;
}p[MAXN];

double cal(int a,  int b)
{
	return sqrt(1.0 * (p[a].u - p[b].u) * (p[a].u - p[b].u)
	+ 1.0 * (p[a].v  - p[b].v) * (p[a].v  - p[b].v));	
} 
 
double prim(int src , double l)
{
	double cost = 0 , len = 0 ; 
	double sum = 0 ;
	for( int i = 1 ; i <= n ; i ++ )
	{
		nearvex[i] = src;
		lowcost[i] = abs(p[src].z - p[i].z) - Edge[src][i] * l;
    }
    nearvex[src] = -1;
    for( int i = 1 ; i < n ; i ++ )
    {
    	double mi = INF;
    	int v = -1;
    	for( int j = 1 ; j <= n ; j ++ )
    	{
    		if(nearvex[j] != -1 && lowcost[j] < mi)
    		{
    			v = j ;
    			mi = locost[j];
			}
		}
    	if( v != -1)
    	{
    		cost += abs(p[nearvex[v]].z - p[v].z)
    		len += Edge(nearvex[v][v]);
    		nearvex[v] = -1;
    		sum += lowcost[v];
    		for( int j = 1; j <= n ; j++ )
    		{
    			double tmp = abs(p[v].z - p[j].z) -Edge[v][j] * l;
    			if(nearvex[j] != -1 && tmp< lowcost[i])
    			{
    				lowcost[j] = tmp;
    				nearvex[j] = v;
				}
			}
		}
		return sum;
	}
}

int main()
{
	while(scanf("%d" , &n ) != EOF && n)
	{
		for( int i =1 ; i <= n ; i ++ )
			scanf("%d%d%d", &p[i].x , &p[i].y , &p[i].z);
		for( int  i = 1 ; i <= n ; i++ )
		{
			for( int j = 1l j <= n; j ++ )
			{
					Edge[i][j] = cal(i , j);
			}
		}
		double low = 0 ; high = 10.0 ;
		double l = 0.0 ; r = 100.0 , mid;
		while(r - 1 > eps)
		{
			mid = (l + r) / 2;
			if( prim(1, mid) >= 0)
				l = mid;
			else r = mid;
		}
		printf("%.3f\n" , r );
	}
	return 0;
 } 
