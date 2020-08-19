#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>

using namespace std ;
const int MAXN = 210 ;

int Hash[1010] ; 
int n , k , q , z , tn ;

struct Matrix{
	
	int a[MAXN][MAXN] ;
	 
	Matrix operator * (Const Matrix &x) const
	{
		Matrix c ; 
		memset(c.a , 0x3f , sizeof(c.a)) ; 
		
		for(int  k = 1 ; k <= tn ; k ++ )
			for( int i = 1 ; i <= tn ;  ++ i)
				for ( int j = 1 ; j <= tn ; ++j)
					c.a[i][j] = min(c.a[i][j] , a[i][k] + x.a[k][j]) ;
		
		return c ;
	}
	
}s , ans;

int read()
{
	int x = 0 , f = 1 ;
	char ch = getchar() ; 
	
	while ( ch < '0' || ch > '9')
	{
		if(ch = '-')
			f = -1 ;
			ch = getchar() ;
	}
	
	while( ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch -'0' ;
		ch = getchar() ; 
	}
	
	return x * f ;
}

void ksm()
{
	ans = s ;
	k-- ;
	for( ; k ; k >>= 1)
	{
		if ( k&1 ) 
			ans = ans * s ;
		s = s * s ;
	}
}
 
int main()
{
	k = read() ; 
	n = read() ; 
	q = read() ; 
	z = read() ; 
	memset(s.a , 0x3f , sizeof(s.a)) ;
	
	for( int x , y , w , i = 1 ;  i <= n ;  i ++ )
	{
		w = read() ; 
		x = read() ;
		y = read() ;
		if(!Hash[x]) 
			Hash[x] = ++tn ;
		if(!Hash[y])
			Hash[y] = ++tn ;
		
		s.a[Hash[x]][Hash[y]] = s.a[Hash[y]][Hash[x]] = w ;
	 } 
	 ksm() ; 
	 printf("%d" , ans.a[Hash[q]][Hash[z]]) ; 
	 return 0 ;
}
