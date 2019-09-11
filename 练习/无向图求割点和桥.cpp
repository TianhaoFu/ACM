#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define MyMax 200
typedef vector<int> Edge;
vector<Edge> G(MyMax);
bool Visited[MyMax];
int dfn[MyMax];
int low[MyMax];
int Father[MyMax];
bool bIsCutVetex[MyMax];
int nTime;
int n,m;

void Tarjan(int u , int father)
{
	Father[u] = father;
	int i ,  j , k;
	low[u] = dfn[u] = nTime ++ ;
	for( i = 0 ; i < G[u].size() ; i ++)
	{
		int v  =  G[u][i];
		if(!dfn[v]){
			Tarjan(v,u);
			low[u] = min(low[u],low[v]);
		}
		else if( father != v)
			low[u] = min(low[u] , dfn[v]);
	}
 } 
 
 void Count()
 {
 	int i ,nRootSons = 0;
 	Tarjan(1,0);
 	for( i = 2; i <= n ;i ++ )
 	{
 		int v = Father[i];
 		if(v == 1)
 			nRootSons ++ ;
 		else if( dfn[v] <= low[i])
 			{
			bIsCutVetex[v] = true;
 		    }
	 }
	if( nRootSons > 1)
		bIsCutVetex[1]  =true;
	for( i =1 ; i <= n ; i++ )
		if( bIsCutVetex[i])
			cout<< i << endl;
	for( i = 1 ; i <= n ; i ++ )
	{
		int v = Father[i];
		if( v > 0 && dfn[v] < low[i])
			cout << v << "," << i << endl; 
	}
}
 
int main()
{
	int u,v;
	int i;
	
	nTime = 1;
	cin >> n >> m;
	for( i = 1; i <= m  ; i ++ )
	{
		cin >> u >>v;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	memset( dfn , 0  ,sizeof(dfn));
	memset( Father , 0  ,sizeof(Father));
	memset( bIsCutVetex , 0 ,sizeof(bIsCutVetex));
	Count();
	return 0;
 } 
