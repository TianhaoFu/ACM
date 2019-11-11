#include<iostream>
using namespace std; 
int getwei(int i)
{
	int x ;
	while(i/10!=0)
	{
		i = i%10 ;
		x = i;
	}
	return x ;
}
int main()
{
	int x  =13234 ;
	printf("%d" , getwei(x));
	return 0;
}

