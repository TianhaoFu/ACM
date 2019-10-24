#include<iosteam>
#include<queue>
#include<vector>
#define MAXN 10000
#define INF 1<<30
using namespace std;
struct node{
	int x ; 
	int w ;
};
vector<vector<node> > G ;
int dis[MAXN][MAXN] ;
int dis_ter[MAXN] ;
int vis[MAXN] ; 
priority_queue<node> pre ; 
node temp ; 
void dij()
{
	for ( int i = 0 ;  i < n ; i ++ )	
	{
		temp = pre.top() ; 
		pre.top() ; 
		if ( vis[temp.x])
			continue ; 
		
		for(int j = 0 ; j < vector[temp.x].size() ; j ++ )
		{
			if(temp.x + dis[temp.x][vector[temp.x][j]] < dis_ter[j])
				{
					dis_ter = temp.x + dis[temp.x][vector[temp.x][j]] ; 
					
				}
				
		}
	}
}
