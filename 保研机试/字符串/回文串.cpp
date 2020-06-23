#include<stdio.h>
#include<string.h> 
int main()
{
	char a[500] ;
	int start =0 ;
	int end;
	int i ;
	int count = 1 ;
	while(scanf("%s",&a)!= EOF)
	{
		
		start = 0 ;
		end = strlen(a)-1 ;
		for (i = 0 ;i < strlen(a) /2 ; i++ )
		{
			if( a[start] == a[end])
			{
				start ++ ;
				end-- ;
			}
			else
				break ;
		}
		printf("%s%d:","case",count);
		if( i < strlen(a)/2 )
			printf("%s\n","no") ;
		else
			printf("%s\n","yes") ;
		count ++ ;
	}
	
	return 0 ;
}
