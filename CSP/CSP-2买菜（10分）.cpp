#include<iostream> 
using namespace std ;
int main()
{
	int n ;
	int a[2001][2] , b[2001][2] ; 
	int sum =0 ;
	scanf("%d" , &n);
	
	for ( int i = 0  ; i < n ; i ++ )
	{
		scanf("%d%d" , &a[i][0], &a[i][1]);
	}
	for ( int i = 0  ; i < n ; i ++ )
	{
		scanf("%d%d" , &b[i][0], &b[i][1]);
	}
	
	
//	for ( int  i = 0 ; i <  n ; i++)
//		printf("%d ,%d \n" ,a[i][0], a[i][1]) ;
//	for ( int  i = 0 ; i <  n ; i++)
//		printf("%d ,%d \n" ,b[i][0], b[i][1]) ;
	//等号取得有问题  13 14 14 15 
	for ( int i = 0 ; i < n ; i ++ )
	{
		for( int j = 0 ;j < n ; j ++ )
		{
			if(a[i][0]<=b[j][0] && a[i][1] >=b[j][1])
				{
//					printf("+++%d% d,%d %d+++" , a[i][0] , a[i][1] , b[i][0] , b[i][1]);
					sum += b[j][1] - b[j][0] ;
//					printf("-1-sum:%d-1-\n",sum);
				}
			else if( a[i][0] >=b[j][0] && a[i][1]<=b[j][1])
				{
//					printf("+++%d% d,%d %d+++" , a[i][0] , a[i][1] , b[i][0] , b[i][1]);
					sum += a[i][1] - a[i][0] ;
//					printf("-2-sum:%d-2-\n",sum);
				}
			else if(a[i][0]  <b[j][0] && a[i][1]  <b[j][1] && a[i][1] > b[j][0] || a[i][0]  ==b[j][0] && a[i][1]  <b[j][1] && a[i][1] > b[j][0]||a[i][0]  <b[j][0] && a[i][1]  ==b[j][1] && a[i][1] > b[j][0])
				{
//					printf("+++%d% d,%d %d+++" , a[i][0] , a[i][1] , b[i][0] , b[i][1]);
					sum += a[i][1] - b[j][0];
//					printf("-3-sum:%d-3-\n",sum);
				}
			else if(a[i][0] > b[j][0] && a[i][1] > b[j][1] && a[i][0] < b[j][1]||a[i][0] == b[j][0] && a[i][1] > b[j][1] && a[i][0] < b[j][1]||a[i][0] > b[j][0] && a[i][1] == b[j][1] && a[i][0] < b[j][1]) 
				{	
//					printf("+++%d% d,%d %d+++" , a[i][0] , a[i][1] , b[i][0] , b[i][1]);
					sum += b[j][1] = a[i][0] ; 
//					printf("-4-sum:%d-4-\n",sum);
				}
			else continue ;
		}
	}
	
	printf("%d" , sum);
	return 0;
 } 
