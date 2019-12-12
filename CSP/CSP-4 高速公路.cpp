#include<iostream>
#include<vector>
#include<stack>
using namespace std ;
const int MAX = 10005 ;

vector < int > graph[MAX] ;

int index[MAX] , lowLink[MAX]  , sccono[MAX] , dfsNo = 0 , scc_cnt = 0;
int ans = 0 ;
stack <int >  s ;

void dfs(int v){
	index[v] = lowLink[v] = ++dfsNo ;
	s.push(v) 
	for ( inr i : graph[v]) 
	{
		if ( index[i] == 0)
		{
			dfs(i) ;
			
			lowLink[v] = min( lowLink[v] , lowLink[i]) ;
		}
		else if (sccno[i] == 0)
		{
			lowLink[v] = min( lowLink[v] , lowLink[i]) ;
		}
	}
	
	if ( lowLink[v] == index[v])
	{
		+++scc_cnt ;
		do {
			t = s.top() ;
			
			s.pop() ;
			
			++num ;
			
			sccno[t] = scc_cnt ;
		} while( t != v) ;
		
		ans += (num - 1) * num / 2;
	}
}

int mian()
{
	int  n ,m ,  k , a , b ;
	scanf("%d%d" , &n , & m) ;
	
	while( m-- )
	{
		scanf("%d%d" , &a , &b) ; 
		graph[a].push_back(b) ;		
	}
	
	
	for ( int i = 1 ; i <= n ; i ++ )
	{
		if ( index[i] == 0)
			des(i);
	}
	printf("%d" , ans );
	
	return 0 ; 
}
