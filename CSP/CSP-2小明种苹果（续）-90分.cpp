#include<iostream>
#include<cstring>
using namespace std ;
int main()
{
	int N;
	int T=0  ,D=0  , E=0 ;
	int num_frequency ;
	int num_apple;
	int apple[1000];
	int drop[1000];
	int ans2[1000]; 
	int flag = 0 ;
	int tmp ;
//	cout << "afsafas" ; 
	cin >> N ;
	memset(apple , 0 ,sizeof(apple)) ;
	memset(drop , 0 , sizeof(drop)) ;
	memset(ans2 , 0 , sizeof(ans2)) ;
	for ( int i =0 ; i < N ; i ++ )
	{
		cin >> num_frequency ;
		cin >> apple[i];
		for ( int j = 1 ; j < num_frequency ; j ++ )
		{
			cin >> tmp ;
			if(tmp > 0 )
				{
					if (apple[i]>tmp) 
						drop[i] = 1 ;
					apple[i] = tmp;		
				}
			if(tmp < 0 || tmp == 0)
			{
				apple[i] += tmp ;
			}
//			printf("--num:%d--",apple[i]) ;
			
		}
		
		
		
	}
	
//	for ( int  i = 0 ; i <  N  ;i ++)
//	 cout <<  apple[i] << " " ; 
	for ( int i = 0 ; i < N ;i ++)
	{
		T += apple[i] ;
	}
	
	for ( int i = 0 ; i <  N ; i ++ )
	{
//		printf("--%d,%d--",i,drop[i]);
		if( drop[i]  == 1)
		D++;
	}
	
	
	
	for( int j=0 ; j <=  N+2; j  ++ ) 
		//达到计算环的目的 
//		for( int j=0 ; j <  N; j  ++ ) 
		{
			if(drop[j%N] == 1 )
				{
					flag += 1 ;
//					printf("\n++%d++\n",j)  ; 
//					printf("\n-+-+-+%d--\n",flag) ;
				}
			if(drop[j%N] == 0)
				flag = 0 ;
			if( flag > 3 || flag == 3 )
			{
//				printf("\n++%d++\n",j)  ;
				E++;
			} 
		}
	cout << T <<' ' << D << ' ' << E ;
	return 0 ;
 } 
