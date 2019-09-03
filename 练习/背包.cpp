#include<iostream>
using namespace std;
int wei[1000];
int val[1000];
int main()
{
	int N,M;
	cin>>N>>M;
	for(int i = 0;i < N ; i++)
	cin>>wei[i]>>val[j];
	for(int i=0;i<N;i++)
	{
		for(int j = M;j >=wei[i];j--)
		{
			dp[j] = max(dp[j],dp[j-wei[j]]+a[j]);
		}
	}
	cout<<dp[M];
}
