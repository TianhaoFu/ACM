#include<stdio.h>
#include<algorithm> 
using namespace std ;
int main()
{
	int a[100] ;
	int num ; 
	int i = 0 ;
	int n ;
	while(1)
	{
		scanf("%d" , &n) ;
		if ( n==0)	
			break ;
			
		while(scanf("%d" , &num) != EOF)
		{
			if ( num <0 )
			num = 0-num ;
			a[i] = num ;
		}
		
		sort(a,a+n) ;
		for ( int i = 0 ;i < n ; i ++)
		printf("%d ") ;
	}
	
	return  0 ; 
}
