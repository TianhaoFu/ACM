#include<iostream>
#include<cstring>
using namespace std;
int getwei(int i)
{
	int x ;
	while(i/10!=0)
	{
		i = i%10 ;
		x = i;
	}
	return x ;
}

int main()
{
	long long int a[1001] ;
	int n ;
	int k ;
	int num = 0 ;
	int lef ;
	scanf("%d %d" , &n , &k) ;
	
//	memset(a , 1  ,sizeof(a));
	for ( int i = 0 ; i < n ; i ++ )
		a[i] = 1 ;
	
	lef = n;
	int i = 0;
//	未给初始值 
	while(lef>1)
	{
//		printf("\n第%d轮：\n",n-lef);
		while(a[i]== 0)
			{//死循环 
//				printf("%d\n" , i) ;
				if(i > n)
					i = 1 ;
				i++ ;
				if(a[i] == 1)
					break ;
			}

		num++ ;
//		printf("%d号报数：%d " , i,num);
		if(num %k == 0 || getwei(num) == k)
			{
//				printf("++%d++",getwei(num));
//				printf(" %d号小朋友淘汰 ",i) ;
				a[i] = 0 ;
				lef-- ;
			 }
		i++ ; 
		if(i > n)
			i = 1 ;
	}
	
	long long int ans  ;
	for(int i = 1 ; i <= n ; i ++)
		if(a[i]!=0)
			ans = i + 1 ;
	printf("%lld" , ans);
	return  0;
}
