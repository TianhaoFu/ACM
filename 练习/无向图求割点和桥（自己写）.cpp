#include<iotream>
#include<vector>
#include<cstring>
using namespace std;

void Tarjan(int u, int father)
{
	int i,nTimes = 0;
	Father[u]  = father;
	low[u] = dnf[u] = ++nTimes;
	for(int i ; i < G[u].size; i ++ )
	{
		v = G[u][i];
		if(!dnf(v))
		{
			Tarjan(v,u);
			low[u] = min(low[u],low[v])
		}
		else if(father(v)!=u)
		{
			low[u] = min(low[u],dnf(v));
		}
	}
}
void count()
{
	int j,nRootSon = 0;
	for(int i = 2 ; i < G.size ; i ++ )
	{
		u = father[i];
		if( u == 1)
		nRootSon ++ ;
		else if (dnf[u] <= low[i]);
			bIsCutVetex[u] = True;
	}
	if ( nRootSons > 1)
		bIsCutVetex[1] = True;
	for( i = 1 ; i <= n ; i ++)
		if(bIsCusVetex[i])
		cout<<i<<endl;
	
}
