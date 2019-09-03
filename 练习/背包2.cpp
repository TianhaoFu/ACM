#include<iostream>
using namespace std;
int main()
{
	int N,W,V;
	cin>>N>>V;
	int a[100];
	for (int i = 0 ; i< N;i++)
	cin>>a[i];
	memset(a,sizeof(a),0);
	for (int k = 0; k  < N;k ++)
	{
		for (int w = 0; w < V ; w++)
		{
			dp[k][w] = dp[k-1][w];
			if(W-a[k]>0)
			dp[k][w] += dp[k-1][w-a[k]];
		}
	}
 } 
