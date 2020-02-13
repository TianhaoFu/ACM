#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std ;
struct stu 
{
	char name[101] ;
	int age ;
	int score ;
	
	bool operator < (const stu &b) const
	{
		if ( score != b.score)
			return score < b.score ;
		
		int tmp = strcmp(name , b.name);
		
		if ( tmp != 0 )
			return tmp < 0 ;
		
		else return age < b.age ;
	}

}buf[1000];

int main()
{
	int n ;
	while(scanf("%d" , &n) != EOF)
	{
		for (int i = 0 ; i < n ;i ++ )
		{
			scanf("%s %d %d" , &buf[i].name , &buf[i].age , &buf[i].score) ;
		}
		
		sort( buf , buf + n) ;
		
		for ( int i = 0 ; i < n ; i ++ )
		{
			printf("%s %d %d\n" , buf[i].name , buf[i].age , buf[i].score) ;
		}
	}
	return 0 ;
}
