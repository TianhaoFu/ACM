#include<iostream>
using namespace std ;
//C语言范围 
//比如说在win32下，int的范围是 -2^31 ~ 2^31 - 1;
//也就是：[ -2147483648, 2147483647];
//写成16进制：[80 00 00 00, 7F FF FF FF];

int main()
{
	int n;
	int r , y ,  g;
	int a[101][2];
	scanf("%d%d%d" , &r , &y , &g); 
	scanf("%d" , &n);
	int color , time ;
	int sum =  0;
	for ( int  i = 0 ; i <  n ; i ++ )
	{
		scanf("%d%d" ,&color , &time ) ;
		if(color == 0)
			sum += time ;
		else if( color == 3) 
			sum += 0 ;
		else if ( color == 2)
			sum += time + r;
		else if( color == 1)
			sum += time ;
	}
	printf("%d" , sum);
	return 0 ;
 } 
