#include<iostream>
#include<vector>

using namespace std ;

int  n ,  m , a , b , c ;
const int inf  = 1 << 30 ;

struct Edge{
	int a , b , c ;
	Edge( int aa , int bb , int cc): a(aa) , b(bb) , c(cc){}
	Edge(){}
};

vector<Edge> edges ;
int dist[1000];

int Bellman_ford( int v)
{
	for( int i = 1 ; i <= n ; i ++ )
			dist[i] = inf;
	dist[v] =  0;
	
	for ( int k = 1 ; k < m ; k ++ )
	{
		for ( int i = 0 ; i < edges.size() ;  i ++) 
		{
			int a = edges[i].a ; 
			int b = edges[i].b ;
			if(dist[a] != inf && dist[a] + edges[i].c < dist[b])
				dist[b] = dist[a]+ edges[i].c ;
		}
	}
	return dist[n]  ; 
}

int main()
{
	cin >> n  >> m ;
	for ( int i = 0 ; i < n ; i ++ ) 
	{	
	 	cin >>a >> b >> c;
	 	edges.push_back(Edge(a,b,c));
	 	edges.push_back(Edge(b,a,c));
	}
	
	cout <<Bellman_ford(1) ;
	
	return 0 ;	
}
