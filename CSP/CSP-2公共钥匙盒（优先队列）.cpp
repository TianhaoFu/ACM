#include<bits/stdc++.h>
using namespace std ;
struct key{
	int num ;
	int time ;
	bool borrow ;
	key( int n , int t,  int b):num(n) , time(t), borrow(b){}
	
	bool operator < (const key a) 
	{
		if ( time > a.time)
			return 1 ;
		else if(borrow == 0&&a.borrow == 1)
			return 1 ;
		else if(num > a.num)
			return 1 ;
	}
};
vector<int> box;
priority_queue<key> lis ;
int main()
{
	int N , K ; 
	int w , s , c;
	scanf("%d%d" , &N , &K) ;
	
	box.resize(N);
	for ( int i = 0 ; i < N ; i ++ )
	{
		scanf("%d%d%d" , &w , &s , &c);
		key k(w , s , c);
		lis.push(k);
	}
	
	int i = 0 ; 
	while (!lis.empty()) 
	{
		key temp = lis.top() ;
		lis.pop() ;
		
		if(temp.borrow == 0)
		{
			while(box[i] != 0)
				++i ; 
			box[i] = temp.num;
		}
		else 
		{
			while(box[i] != temp.num)
				++i ;
			box[i] = 0; 
		}
		i = 0;
	}
	for ( i = 0 ; i < N ; i ++ )
	{
		printf("%d " ,box[i]);
	}
	
	return 0 ; 
}

