#include<stdio.h>
#include<string.h>
using namespace std ;
int main()
{
	char a[500] ;
	int n ; 
	int ans[1000] ;
	int count = 0  ;
	scanf("%d" , &n)  ;
	for ( int i = 0 ; i < n ; i ++ )
	{
		scanf("%s",&a) ; 
		count = 0 ;
		for ( int j = 0 ; j < strlen(a) ;j ++ )
		{
			if( a[j] >= '0' && a[j] <= '9' )
			{
				count ++ ;
			}
		}
		ans[i] = count ;
	 } 
	 for ( int i = 0 ; i < n ; i ++)
	 {
	 	printf("%d\n" , ans[i]) ;
	 }
	 
	 return 0 ;
}
