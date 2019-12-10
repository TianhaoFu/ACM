#include<cstdio>
using namespace std ;
int main()
{
	int n ;
	int num[100] ;
	int seat[20];
	int j = 0 ;
	int flag = 0 ;
	 
	scanf("%d" , &n) ;
	for( int i = 0 ; i< n ; i ++) 
	{
		scanf("%d" , &num[j++]) ;
	}
	
	for ( int i = 0 ;i  < 20  ; i ++ )
		seat[i] = 5 ;
//	求结果 
	for ( int i = 0 ;i < n ; i ++ )
	{
		flag  = 0 ;
		for (  j = 0 ; j <  20 ; j ++ )
		{
			if(seat[j] >= num[i])
				{		
//					printf("第%d排\n" , j );
					for ( int k = 1 ; k <= num[i] ; k++)
						printf("%d " , j * 5 + 5 - seat[j]+ k );
					seat[j] -= num[i] ;
					flag = 1 ;
					break;
				}
		}
		if ( flag != 1 )
		{
			j = 0 ;
			while(seat[j] == 0 )
				j ++ ;
//			printf("第%d排\n" , j );
			for ( int k = num[i] ; k > 0 ; k -- )
			{
				printf("%d " , j*5 + 5 - k ) ;
			 } 
		}		
		
		printf("\n") ;
	 } 
	 
	 return  0 ;
 } 
