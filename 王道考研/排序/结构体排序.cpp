#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std ;
struct stu
{
	char name[101];
	int age ;
	int score ;
}; 
bool cmp (stu x , stu y )
{
	if (x.score != y.score)
	{
		return x.score< y.score ;
	}

	
	int tmp = strcmp ( x.name , y.name) ;
	
	if (tmp != 0)
		return tmp < 0	;


	else return x.age < y.age ; 
}

int main()
{
	int n ;
	struct stu buf[1000];
	while(scanf("%d" , &n) != EOF)
	{
		for ( int i = 0 ; i < n ; i ++ )
		{
			scanf("%s %d %d" , &buf[i].name , &buf[i].age , &buf[i].score) ;
		}
		
		sort(buf , buf + n ,cmp );
		
		for ( int i = 0 ; i < n ; i ++ )
		{
			printf("%s %d %d" , buf[i].name , buf[i].age  , buf[i].score) ;
			printf("\n") ;
		}
		
		printf("\n") ;
		
	}
	return  0 ;
 } 
