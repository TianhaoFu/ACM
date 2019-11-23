#include<iostream>
using namespace std ;
bool isyeap(int x )
{
	if( x %4 ==0 && x %100 != 0 || x % 400 == 0)
	return true ;
	else 
		return false ;
}

int mon1[12] = {31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31} ;
int mon2[12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31} ;

int main()
{
	int y ,d ;
	cin >> y >> d ;
	
	int ans1 , ans2; 
	int sum = 0 ;
	int i ;
	if ( isyeap(y))	
	{
		for ( i = 0 ; i < 12 ; i ++ )
		{
			sum += mon1[i];
			if( sum >= d)
				break ; 
			}	
			
		ans1 = i + 1;
		ans2 = d - (sum-mon1[i]); 
	}
	
	else 
	{
		for ( i = 0 ; i < 12 ; i ++ )
		{
			sum += mon2[i];
			if( sum >= d )
				break ;
		}
		
		ans1 = i + 1;
		ans2 = d - (sum-mon1[i]);
	}
	cout << ans1 << endl << ans2 ;
	
	return 0 ;
}

