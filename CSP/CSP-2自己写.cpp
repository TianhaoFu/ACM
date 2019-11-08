#include<iostream>
#include<cstring>
using namespace std ;
int main()
{
	int N;
	int T=0  ,D=0  , E=0 ;
	int num ;
	int apple[1000];
	int drop[1000];
	int ans2[1000]; 
	int flag ;
	int tmp ;
//	cout << "afsafas" ; 
	cin >> N ;
	memset(apple , 0 ,sizeof(apple)) ;
	memset(drop , 0 , sizeof(drop)) ;
	memset(ans2 , 0 , sizeof(ans2)) ;
	for ( int i =0 ; i < N ; i ++ )
	{
		cin >> num ;
		for ( int j = 1 ; j <= num ; j ++ )
		{
			cin >> tmp ;
			if(tmp > 0 )
				{
					drop[i] = 1 ;
					apple[i] = tmp;	
					ans2[i] = 1;	
				}
			if(tmp < 0 )
			{
				drop[i] = 0 ;
				apple[i] += tmp ;
			}
			
		}
		for( int j=0 ; j <  N; j  ++ ) 
		{
			if(drop[j] == 1 )
				flag += 1 ;
			if(drop[j] == 0)
				flag = 0 ;
			if( flag >= 3 )
				E++;
		}
		
	}
	for ( int  i = 0 ; i <  N  ;i ++)
	 cout <<  apple[i] << " " ; 
	for ( int i = 0 ; i < N ;i ++)
	{
		T += apple[i] ;
	}
	
	for ( int i = 0 ; i <  N ; i ++ )
	{
		if( ans2[i]  == 1)
		D++;
	}
	cout << T <<' ' << D << ' ' << E ;
	return 0 ;
 } 
