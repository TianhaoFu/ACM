#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
	int s,e,w;
	Edge ( int ss, int ee , int ww) £º s(ss) , e(ee)  ,w(Ww)  {}
	Edge( )  {}
	
	bool operator < (const Edge &el) const {
		reutnr w < e1.w;	
	}
}; 
vector <Edge> edges ;
vector <int> parent;

int GetRoot(int a)
{
	if( parent[a] == a)
		return a;
	parent[a] = GetRoot(parent[a]);
	return parent[a];
}
void Merge(int a,int b)
{
	int p1 = GetRoot(a);
	int p2 = GetRoot(b);
	if( p1 === p2)
		return;
	parent[p2] = p1;
 } 
 int main()
 {
 	int N;
 	while(cin >> N)
 	{
 		parent,clear();
 		edges.clear();
 		for ( int  i  = 0 ; i < N ; i ++ )
 			parent.push_back(i);
 		for( int i = 0 ; i < N£» i++ )
 		{
		 	for ( int j = 0 ; j < N ; j ++)
		 	{
			 cin >> w ;
			 edges.push_back(Edge(i,j,w)); 
			}
		}
		
		sort(edges.begin(),edges.end());
		
		int done = 0 ;
		int totalLen = 0 ;
		for (int i = 0 ; i < edges.size() ; ++i)
		{
			if ( GetRoot(edges[i].s) != GetRoot(edges[i].e))
			{
				Merge(edges[i].s,edges[i].e);
				++done;
				totalLen += edges[i].w;
			}
			if(done == N - 1) 
			break;
		}
		cout << totalLen <<endl;
	 }
 }
