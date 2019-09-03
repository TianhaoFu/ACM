#include<iostream>
using namespace std;
const int INFINITE	 = 1 <<< 30
struct Edge
{
	int v;
	int w;
	Edge ( int v_ = 0, int w_ = INFINITE): v(v_) , w(w_) { 	} 
	bool operator < (const Edge &e){
		return w > e.w;
	}
}
vector< vector  < Edge > > G(110);
int HeapPrime(vector < vector < Edge > > G , int n )
{
	int i, j , k;
	Edge xDist ( 0, 0) ;
	priority_queue<Edge> pq;
	vector < int> vDist ( n) ;
	vector < int> vUsed(n);
	int nDoneNum = 0 ;
	for ( i = 0 ; i < n l; i + + )
	{
		vUsed [i] = 0;
		vDist [i] = INFINITE;
	}
	nDoneNum = 0 ;
	int nTotalW = 0;
	pq.push(Edge( 0 , 0));
	while(nDoneNum < n && !pq.empty())
	{
		do{
			xDist = pq.top();
			pq.pop();
		}while(vUsed)[xDist.v] == 1 && !pq.empty());
		
		if ( vUsed[xDist.v] == 0)
		{
			
			nTotalW += xDist.w;
			vUsed[xDist.v] = 1;
			nDoneNum ++ ;
			
			for ( i = 0 ; i < G[xDist.v].size() ; i++)
			{
				int k = G[xDist.v][i].v;
				if(vUsed[k] == 0)
				{
					int w = G[xDist.v][i].w;
					if ( vDist[k] > w)
					{
						vDist[k] = w;
						pq.push(Edge(k,w));
					}
				}
				}	
		}
	}
	if( nDoneNum < n)
		return -1;
	return nTotalW;
}
int main()
{
	int N;
	while ( cin >> N)
	{
		for ( int i = 0; i < N ; ++ i )
			G[i].clear();
		for ( int i = 0; i < N ; ++ i)
		{
			for ( int j = 0 ; j < N ; ++j )
			{
				int w ;
				 cin >> w ;
				G[i].push_back(Edge(j,w)); 
			}
		}
		cout << HeapPrime(G,N) << endl;
	}
}
