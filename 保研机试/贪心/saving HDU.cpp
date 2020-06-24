#include<stdio.h>
#include<algorithm>
using namespace std ;
struct baobei
{
	int p ,v ;
 } a[100] ;
bool cmp(baobei a,baobei b)
{
	if(a.p == b.p)
		return a.v > b.v ;
	else 
		return a.p > b.p ;
}
int main()
{
	int v,n;
	scanf("%d%d",&v,&n);
	int volume ;
	int ans ;
	while(v!=0)
	{ 
		ans = 0 ;
		volume = 0 ; 
		for ( int i = 0 ; i < n ; i ++ )
		{
			scanf("%d%d" , &a[i].p,&a[i].v);
		}
		sort(a,a+n,cmp) ;
		int i = 0;
		while(volume <= v)
		{
			volume += a[i].v ;
			if(volume > v)
				break ;
			ans += a[i].v * a[i].p;
			i++;
		}
		if(volume > v)
			ans += (a[i].v- (volume  - v) )* a[i].p ;  
		printf("%d\n",ans) ;
		scanf("%d%d" , &v , &n) ;
	}
	return  0;	
 } 
