#include<stdio.h> 
#include<math.h> 
using namespace std ;
int func(int x)
{
	return (x * x + x + 41);
}

bool sushu(int x)
{
	int y = sqrt(double(x)) ;
	int i ;
	for(i = 2 ; i <= y ; i ++)
	{
		if(x%i == 0) 
		break;
	}
	if( i <= y)
	{
		return false ;
	 } 
	 else return true ;
}
int main()
{
	int x , y ;
	scanf("%d%d",&x,&y)  ;
	int i ;
	int interm ,panding; 
	while(1)
	{
		if( x==0 && y==0)
			break;
		for ( i = x ; i <= y  ; i ++)
		{
			interm = func(i);
			panding = sushu(interm) ;
			printf("dsfdsfdsf");
			if ( panding )
				break ;
		}
		
		if (i <= y)
			printf("%s","Sorry");
		else printf("%s","OK");
		scanf("&d&d" , &x , &y) ;
	}
	
	return  0;
}
