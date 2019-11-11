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
	int a[1001] ;
	int n ;
	int k ;
	int num = 0 ;
	int lef ;
	scanf("%d %d" , &n , &k) ;
	
	memset(a , 1  ,sizeof(a));
	
	lef = n;
	int i ;
	while(lef>1)
	{
//		printf("\nµÚ%dÂÖ£º\n",n-lef);
		while(a[i]== 0)
			{//ËÀÑ­»· 
//				printf("%d\n" , i) ;
				if(i >= n-1)
					i = 0 ;
				i++ ;
				if(a[i] == 1)
					break ;
			}

		num++ ;
//		printf("%dºÅ±¨Êý£º%d " , i,num);
		if(num %k == 0 || getwei(num) == k)
			{
//				printf("++%d++",getwei(num));
//				printf(" %dºÅÐ¡ÅóÓÑÌÔÌ­ ",i) ;
				a[i] = 0 ;
				lef-- ;
			 }
		i++ ; 
		if(i > n-1)
			i = 0 ;
	}
	
	int ans  ;
	for(int i = 0 ; i < n ; i ++)
		if(a[i]!=0)
			ans = i +1 ;
	printf("%d" , ans);
	return  0;
}
