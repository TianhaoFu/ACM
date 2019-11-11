#include<bits/stdc++.h> 
using namespace std ;
int main()
{
	int N , K ;
	scanf("%d%d" , &N , &K);
	queue<int> q ;
	
	for ( int i = 1 ; i <= N ; i++ )
	{ 
		q.push(i) ;
	}
	
	int num = 1 ;
	
	while(q.size() > 1 )
	{
		int t = q.front() ;
		
		q.pop();
		
		if( !(num%K==0||num%10==K))
			q.push(t);
		++num ;
	}
	printf("%d" , q.front());
}
