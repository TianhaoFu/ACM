#include<iostream>
#include<cstdio> 
#define M 5
#define N 10 
//¶¯Ì¬Êý×éC++£¿ 
using namespace std;
int a[M][N];
int ans[N];
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cin>>a[i][j];
		}
	 } 
	int *ans=a[M-1];
	for(int i=M-2;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			a[i][j]=max(a[i+1][j],a[i+1][j+1])+a[i][j];
			//cout<<a[i][j]<<endl;
		}
	}
	cout<<a[0][0];
	return 0;
} 
