#include<stdio.h> 
using namespace std ;
int a[51];
int main()
{
	a[1] = 1 ;
	a[2] = 2 ;
	a[3] = 3 ;
	for ( int i = 4 ; i <= 50 ; i ++ )
	{
		if ( i % 3 == 1)
		{
			a[i] = a[i-1] ;
		}
		else if ( i % 3 == 2)
		{
			a[i] = a[i-2] * 2 ;
		}
		else if ( i % 3 == 0)
		{
			a[i] = a[i-3] * 3 ;
		}
			
	}
	
	int x ;
	
	while( scanf("%d" , &x)!= EOF)
	{
		printf("%d",a[x]) ;
	}
	return 0 ;
}
