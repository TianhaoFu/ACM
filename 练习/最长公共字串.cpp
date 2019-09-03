#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 10; 
char a[MAX],b[MAX];
//动规 所有的状态都已知
int max(int x,int y)
{
	return x>y?x:y;
 } 
int main()
{
	cin>>a;
	cin>>b;
	int ans[MAX][MAX];
	memset(ans,0,sizeof(int));
	for(int i=1;i<=MAX;i++)
	{
		for(int j=1;j<=MAX;j++)
		{
			if(a[i-1]==b[j-1]) ans[i][j]=ans[i-1][j-1]+1;
			else ans = max(ans[i-1][j],ans[i][j-1]);
		}
	 }
	 cout<<ans[10][10]<<endl;
	 return 0; 
}
