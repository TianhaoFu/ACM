#include<stdio.h> 
using namespace std ;

long long int r , y ,g ;
long long int n ;
long long int a[100005][2];
//ºì1ÂÌ3»Æ2
void bianhuan(int start , long long int t)
{
	int period = r + y + g ;
	int i = start ;
	t = t % period ;
	
	if(a[i][0] == 0)
		1+1;
	else if(a[i][1] > t)
		a[i][1] = a[i][1] - t ;
	
	else if( a[i][0] == 1)
	{
		if(a[i][1] < t && a[i][1] +g > t )	
		{
			a[i][0] = 3 ;
			a[i][1] = g+a[i][1] - t ;
		 } 
		else if (a[i][1]+g < t && a[i][1] + g + y > t)
		{
			a[i][0] = 2 ;
			a[i][1] = y + g+a[i][1] - t ;
		}
		else if(a[i][1] + g + y < t)
		{
			a[i][1] = a[i][1]+ period - t ;
		}
	}
	
	else if( a[i][0] == 3)
	{
		if( a[i][1] < t && a[i][1] + y > t)
		{
			a[i][0] = 2 ;
			a[i][1] = y + a[i][1] - t ;
		}
		else if( a[i][1] + y < t && a[i][1] + y + r > t)
		{
			a[i][0] = 1 ;
			a[i][1] = y + r +a[i][1] - t ;
		}
		else if( a[i][1] + y + r < t)
		{
			a[i][1] = a[i][1]+ period - t ;
		}
	}
	else if( a[i][0] == 2)
	{
		if( a[i][1] < t && a[i][1] + r > t)
		{
			a[i][0] = 1 ;
			a[i][1] = r + a[i][1] - t ;
		}
		else if( a[i][1] + r < t && a[i][1] + r + g > t)
		{
			a[i][0] = 3 ;
			a[i][1] = r + g +a[i][1] - t ;
		}
		else if( a[i][1] + r + g < t)
		{
			a[i][1] = a[i][1]+ period - t ;
		}
	}
}

int main()
{	
//	freopen("201812-2.txt","r",stdin) ;
	scanf("%d%d%d" , &r , &y , &g)  ;
	scanf("%d" , &n) ;
	for (int i = 0 ; i  < n ; i ++ )
	{
		scanf("%d%d" , &a[i][0] , &a[i][1]) ;
	}
	long long int ans =0 ;
	for ( int i = 0 ;i < n ; i ++ )
	{
		
		if(a[i][0]==0)
		{	
			ans +=a[i][1] ;
			bianhuan(i+1,ans) ;
		}
		else if(a[i][0] == 1)
		{
			ans += a[i][1];
			bianhuan(i+1,ans) ;
		}
		else if(a[i][0] == 3)
			continue ;
		else if(a[i][0] == 2)
		{
			ans += a[i][1] + r ;
			bianhuan(i+1,ans) ;
		}
	}
	printf("%lld" , ans) ;
}
