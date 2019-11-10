#include<bits/stdc++.h> 
using namespace std ;
int main()
{
	int  N , L , T ;
	scanf("%d%d%d" , &N , &L, &T);
	
	pair<int , int > ball[N+1] ;
	int line[L+1] = {0}  ;
	
	for (int i = 1 ; i <=N  ; i++ )
	{
		scanf("%d" , &ball[i].first);
		ball[i].second = 1 ;
		line[ball[i].first]  =i ;
	} 
	
	 while( T-- )
	 {
	 	for ( int i = 1 ; i <= N ; ++i  )
	 	{
	 		line[ball[i].first] = 0 ;
	 		ball[i].first = ball[i].first  +  ball[i].second ; 
	 		if(line[ball[i].first] != 0)
		 	{
		 		ball[i].second = -ball[i].second ;
		 		ball[line[ball[i].first]].second = -ball[line[ball[i].first]].second ;
		 	}
		 	
		 	else if(ball[i].first == 0 || ball[i].first == L )
		 	{
		 		ball[i].second = -ball[i].second ;
		 		line[ball[i].first] = i;
			}
			
		 }
		 
	 }
	 
	 for ( int i = 1 ; i<= N ;  ++i)
	 {
        printf("%d ",ball[i].first);
	 }
	 
	 return 0;
}
