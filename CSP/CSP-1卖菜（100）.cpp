#include<iostream>
using namespace std ;

//取整方法 
//1.简单粗暴，直接转化
//float f = 1.5; int a; a = (int)f; NSLog("a = %d",a);
//输出结果是1。（int）是强制类型转化，丢弃浮点数的小数部分。
//2.高斯函数，向下取整
//float f = 1.6; int a; a = floor(f); NSLog("a = %d",a);
//输出结果是1。floor()方法是向下取整，类似于数学中的高斯函数 [].
//取得不大于浮点数的最大整数，对于正数来说是舍弃浮点数部分，对于复数来说，舍弃浮点数部分后再减1.
//3.ceil函数，向上取整。
//float f = 1.5; int a; a = ceil(f); NSLog("a = %d",a);
//输出结果是2。ceil()方法是向上取整，
//取得不小于浮点数的最小整数，对于正数来说是舍弃浮点数部分并加1，对于复数来说就是舍弃浮点数部分.
//4.通过强制类型转换四舍五入。
//float f = 1.5; int a; a = (int)(f+0.5); NSLog("a = %d",a);

int main()
{
	double a[10001] ;
	int b[10001];
	int n ; 
	scanf("%d" , &n);
	for ( int  i = 0 ; i < n ; i ++ ) {
		scanf("%lf" , &a[i]);
	}
//	以整数形式录入时出错 
//	for ( int i = 0 ; i < n ; i++ )
//	{
//		printf("%d " , a[i]);
//	}
	double temp ;
	for ( int i = 0 ; i < n  ; i ++ )
	{
		if( i == 0)
		{
//			printf("%lf %lf %lf",a[i] , a[i+1] , ((a[i]+a[i+1])/2));
//			printf("--%lf-- \n" , x);
			temp  =(a[i] +  a[i+1]) /2 ;
//			printf("%lf" , temp);
//			printf("++%d++ \n",temp);
			b[i] = (int)temp ;
//			printf("%d ",b[i]);
		}
		else if( i == n-1)
		{
			b[i] = (int)((a[i] + a[i-1]) /2 );
//			printf("%d ",b[i]);
		}
		else 
		{
			b[i] =(int)(( a[i-1] +  a[i] +a[i+1]) / 3 );
//			printf("%d ",b[i]);
		}
	}
	for ( int i = 0 ; i < n ; i ++ )
	{
		printf("%d " , b[i]);
	}
	
	return 0;
}
 
