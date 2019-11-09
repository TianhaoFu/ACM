#include<bits/stdc++.h> 
using namespace std ;
int main()
{
	int n ; 
	string s ;
	cin >>  n ;
	queue<int > num ;
	queue<char> op ;
	while(n--)
	{
		cin >> s ;
		s.push_back('+') ;
		for ( int i = 1 ; i < s.size() ;  i += 2)
		{
			int t = s[i-1] - '0' ;
			for( ; i < s.size() && s[i] == '/' ; i += 2)
				t = (s[i] == 'x') ? t * (s[i+1] - '0') : t/(s[i+1] - '0')  ;
		}
		
		num.push(t) ;
		op.push(s[i]) ;
	
	
	num.push(0) ;
	
	int t = num.front() ;
	num.pop() ;
	
	while( !op.empty())
	{
		char c = op.front() ;
		op.pop() ;
		t = (c=='+')  ?  t+num.front()  :  t -num. front  ;
		
		num.pop();
	}
	
	puts( t == 24  ?  "Yes"  :  "No");
	}
	
	return 0 ;


}

