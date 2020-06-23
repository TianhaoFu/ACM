#include<stdio.h> 
#include<string.h> 
#include<string>
#include<queue>
#include<stack>
using namespace std ;
int main()
{
	int n ;
	char s[100000] ;
	int temp ;
	char x ;
	int ans ;
	int num ;
	char in[10] ;
	scanf("%d",&num) ;
	char real_ans[100000][2] ;
	int pos = 0 ;
	int real_num = 0 ;
	for ( int j = 0 ;j < num ; j ++)
	{
		scanf("%d" , &n);
		scanf("%s" , s) ;
		if(strcmp(s,"FIFO") == 0)
			{
				queue<int> a ;
				for ( int i = 0 ; i < n ; i ++ )
				{
					scanf("%s" , in) ;
					if (in[0] == 'I')
					{
						scanf("%d" , &temp) ;						
						a.push(temp);
					}
					if(in[0] == 'O')
					{
						real_num++;
						if(!a.empty())
						{
							ans = a.front() ; 
							real_ans[pos][0] = 0 ;
							real_ans[pos++][1] = ans ;
							a.pop() ;
						}
						else 
						{
							real_ans[pos++][0] =1 ;
						
						}
					}
				}
			}
		if(strcmp(s,"FILO") == 0) 
			{
				stack<int> b ;
								
				for ( int i = 0 ; i < n ; i ++)
				{
					scanf("%s" , in) ;
					if (in[0] == 'I')
					{
						scanf("%d" , &temp) ;
						b.push(temp);
					}
					if(in[0] == 'O')
					{
						real_num++;
						if(!b.empty())
						{
							ans = b.top() ;
							real_ans[pos][0] = 0 ;
							real_ans[pos++][1] = ans ;
							b.pop() ;
						}
						else 
							real_ans[pos++][0] =1 ;
					}	
				}
			}
	}
	for(int i = 0 ; i < real_num; i ++ )
			{
				
				if(real_ans[i][0] == 0)
					printf("%d",real_ans[i][1]);
				if(real_ans[i][0] == 1)
					printf("%s","None") ;
				if(i < real_num-1) 
					printf("\n") ;
			}
	return 0 ;
}
