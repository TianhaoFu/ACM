#include<iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int a[41];
	int ways[41][41];
	for ( int i = 1 ;i <40;i++)
	{
		cin>>a[i];
		ways[0][i] = 0;
	 } 
	 ways[0][0] = 0;
	 for (int w = 1;w < 41;w++)
	 {
	 	for (int k = 1;k < 41;k ++)
	 	{
	 		ways[w][k] = ways[w][k-1];
	 		if(w-a[k]>0)
	 		{
	 			ways[w][k] += ways[w-a[k]][k-1];
			 }
		 }
	 }
	 cout<<ways[40][N];
	 return 0;
 } 
