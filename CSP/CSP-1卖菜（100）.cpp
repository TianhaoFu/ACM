#include<iostream>
using namespace std ;

//ȡ������ 
//1.�򵥴ֱ���ֱ��ת��
//float f = 1.5; int a; a = (int)f; NSLog("a = %d",a);
//��������1����int����ǿ������ת����������������С�����֡�
//2.��˹����������ȡ��
//float f = 1.6; int a; a = floor(f); NSLog("a = %d",a);
//��������1��floor()����������ȡ������������ѧ�еĸ�˹���� [].
//ȡ�ò����ڸ��������������������������˵���������������֣����ڸ�����˵���������������ֺ��ټ�1.
//3.ceil����������ȡ����
//float f = 1.5; int a; a = ceil(f); NSLog("a = %d",a);
//��������2��ceil()����������ȡ����
//ȡ�ò�С�ڸ���������С����������������˵���������������ֲ���1�����ڸ�����˵������������������.
//4.ͨ��ǿ������ת���������롣
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
//	��������ʽ¼��ʱ���� 
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
 
