#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std ;

struct cnode {
	int k ;	
	int w ;
}; 

bool operator < ( const cnode &d1 , const cnode & d2 )
{
	return d1.w > d2 .w ;
}

priority_queue<cnode >pq ;
bool bused[100001] = {0};

vector < vector <cnode > > v ;
const unsigned int inf = 1 <<30 ;
int main()
{
	int  n , m , a ,  b ,c ;
	cnode p ;
	cin >> n >>  m ;
	v.clear() ;
	v.resize(n+1) ;
	
	memset(bused , 0 , sizeof(bused)) ;
	
	for  ( int i = 1 ; i <= m ; i ++ )
	{
		cin  >>a >> b >> c ;
		p.k = b ;
		p.w = c ;
		v[a].push_back(p);
	}
	
	p.k = 1 ;
	p.w = 0 ;
	pq.push(p) ;
	
	while(!pq.empty())
	{
		p = pq.top() ;
		
		pq.pop() ;
		if( bused[p.k])
			continue ;
		
		bused[p.k] = true ;
		
		if(p.k == n)
			break ;
		
		
		for( int i = 0 ,  j = v[p.k].size() ; i < j ;i ++ )
		{
			cnode q ;
			q.k = v[p.k][i].k ;
			if(bused[q.k])
				continue ;
			q.w = p.w + v[p.k][i].w ;
			pq.push(q) ;
		}
	}
	
	printf("%d" , p.w) ;
	return  0;
}
