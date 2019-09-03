#include<iostream>
#include<string.h>
#include<cstdio> 
#define MAX 1000
using namespace std;
int minstr[MAX][MAX];
const int INF = 99999999;
//全部结束后无限循环了 
int minstring(int m,int n)
{
	cout<<n<<" "<<m<<endl;
	if(n<m) return INF;
	else if(m==0)
	{
		cout<<"jieshu";
	return minstr[0][n];
	}
	else
	{
		int temp=INF;
		for(int i=m;i<=n-1;i++)//为什么i要大于M 因为在此此题里还有m个加号 相当与剪枝了 
			{
			temp =  minstring(temp,minstring(m-1,i)+minstr[i][n]);
			cout<<"biazhi"<<temp;
			}
		cout<<"jieshu";	 
		return temp;
	}
}
int main()
{
	int n;
	int m;
//	char s[MAX];
	char s[MAX] = {'1','2','3','4','5','6'};
	int res;
//	cin>>s;
	n=strlen(s);
//	cout<<n;
//	cin>>m;
	m = 4;
	int j = 0;
	for(int i=0;i<n;i++)
	{
		minstr[i][i] = s[i]-48;
		for(j=i;j<n-1;j++)
		{
			minstr[i][j+1]=minstr[i][j]*10+s[j+1]-48;
		}
	}
//	cout<<minstring(n,m);
	if (res = minstring(m,n)!=-1000)
		cout<<res<<endl;
}

