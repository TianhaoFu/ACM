#include<cstdio>
#include<cstring> 
using namespace std;
int a[8]={-2,-1, 1,2 ,2,1,-1,-2};
int b[8]={-1,-2,-2,-1,1,2, 2, 1};
int count = 0;
int c[100][100] = {0};
int m,n,x,y,total;
void dfs(int x,int y,int t)
{
	if(t == total ){
		count++;
		return ;
	} 
	for(int i = 0 ;i < 8 ; ++ i )
	{
		int x1 = x + a[i];
		int y1 = y + b[i];
		if(x1 >= 0 && x1 < n && y1>=0 && y1 < m&& c[x1][y1] == 0)
		{
			c[x1][y1] = t + 1;
			dfs(x1,y1,t+1);
			c[x1][y1] = 0;
		}
	}
}
int main()
{
	scanf("%d",&n);	
    while(n--)
	{
		    memset(c,0,sizeof(c));
			scanf("%d%d%d%d",&m,&n,&x,&y);
			c[x][y] = 1;
			total = m*n;
			dfs(x,y,1);
			printf("%d\n",count); 
	}
	
	return 0;
}
