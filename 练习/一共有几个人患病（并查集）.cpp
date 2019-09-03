#include<iostream>
#include<cstdio>
using namespace std;
int parent[30000];
int team[501];
int getroot(int x)
{
	if(parent[x]!=x)
	parent[x]=getroot(x);
	return parent[x];
}
void merge(int a,int b)
{
	parent[a]=getroot(b);
}
int count[100];
int k=0;
int main()
{
	int n,m,team_num,x_temp;
	int x;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&team_num);
		scanf("%d",&x_temp);
		parent[x_temp]=x_temp;
		for(int j=1;j<team_num;j++)
		{
			scanf("%d",&x);
			parent[x]=x_temp;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(getroot(i)==getroot(0)) merge(0,i);
	}
	for(int i=0;i<n;i++)
	{
		if(getroot(i)==getroot(0))
		count[k]++;
	}
	k++;
}
	for(int i=0;i<k;i++)
	printf("%d ",count[i]);
	return 0;
}
