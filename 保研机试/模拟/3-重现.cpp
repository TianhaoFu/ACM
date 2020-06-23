#include<cstdio>
using namespace std ;
int main()
{
	int a[101] ;
	int n ;
	int ans;
	int j ; 
	
	while( scanf("%d" , &n) != EOF)
	{
		ans = 0 ;
		j = 1 ;
		if (n == 0)
			break ;
		for (int i = 0 ; i < n ; i ++)
		{
			scanf("%d" , &a[j++]);
		}
		a[0] = 0 ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			if( a[i+1] - a[i] > 0)
			{
				ans += 6*(a[i+1] - a[i]) ;
			}
			if( a[i+1] - a[i] < 0)
			{
				ans += 4*(a[i] - a[i+1]) ;
			}
			
			ans += 5;
		 } 
		 printf("%d\n" , ans) ;
	}
 } 
