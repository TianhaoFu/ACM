#include<iostream>
using namespace std;
int a[30];
int ways(int total,int select)
{
	if (total<=0)
	return 0;
	else if (select<=0)
	return 1;
	else 
	{
		return ways(select-1,total) + ways(select-1,total-a[select]);
	}
}
int main()
{
	int N;
	cin>>N; 
	for(int n = 0;n < N ; n++)
	{
		cin>>a[n];
	} 
	cout<<ways(N,40);
	return 0;
}
