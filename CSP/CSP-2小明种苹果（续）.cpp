#include<iostream>
using namespace std ;
int main()
{
	int N ;
	int m ; 
	int T = 0  , D = 0 , E = 0 ;
	int sum = 0 ;
	int apple[1000] ;
	int drop[1000] = {0} ;
	
	cin >> N ;
	for ( inti = 0 ; i < N ; I++ )
	{
		 CIN >> M ;
		 for ( intj  = 0 ; j < m ; j ++) 
		 {
		 	cin  >> apple[j] ;
		 }
		 
		 sum = apple[0];
		 
		 for(  int j = 1 l j <   ; j ++ )
		 {
		 	if ( apple[j] > 0 )
		 	{
		 		if( sum != apple[j])
		 		{
		 			drop[i] = 1 ;
		 			sum = apple[j] ;
				 }
			 }
			 
			 else{
			 	sum += apple[i];
			 }
		 }
		 T += sum ;
	}
	
	int flag = 0 ;
	
	for( int i =0 , j =  0 ; j < n + 2 ; i ++ )
	{
		if( drop[j] == 1 )
		{
			flag++ ;
			if( i <  N)
				D++ ;
		 } 
		 else flag = 0 ;
		 
		 if( flag  >= 3)
			E++;
		j++ ;
		j = j % N ; 
	}
//	¾«ÃîµÄÅÐ¶Ï»· 
	
	cout << T << " " << D << " " <<E ;
	return 0;
}
