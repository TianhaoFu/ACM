#include<stdio.h> 
#include<string.h> 
int main()
{
	char a[13] ;
	scanf("%s" , &a);
	char answer ;
	int ans = 0 ;
	int count = 1 ;
	for ( int i = 0 ; i < 13 ; i ++ )
	{
		if( i == 1 || i == 5 || i == 11 || i == 12)
		 continue ; 
		else
		{
			ans = ans + (a[i]-'0') * count ;
			count++;
		}
		
	}
	ans = ans % 11 ;
	if ( ans == 10)
		answer = 'X' ;
	else 
		answer = ans + '0' ;
	if ( answer == a[12])
	{
		printf("Right") ;
	}
	else 
	{
		for ( int i = 0 ; i < 12 ; i ++ )
		{
			printf("%c" , a[i]) ;
		}
		printf("%c" , answer) ;
	}
	
	return 0 ;
}
