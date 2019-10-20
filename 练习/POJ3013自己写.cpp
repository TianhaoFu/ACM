#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define MAXN 50001;
using namespace std ;
struct node
{
	int val ; 
	int dist ; 
	bool operator < (const node n)
	{
		return dist > n.dist;
	}
}

vector <vector<node>> G ;
priority_queue<node> pq;
node temp;
vector<int> ans;

int n ;
int vis[MAXN];
int wei[MAXN];
int v_num;
int e_num;
int a , b , c ;
int dis[MAXN];
int val;
int dist;
int answ ;

 void init()
 {
 	
 	memset(0,sizeof(vis),vis);
 	memset(0,sizeof(wei),wei);
 	memset(0,sizeof(dis),dis);
 	
}

void dij()
{
	temp.val = 1 ;
	temp.dist = 0 ;
	pq.push(temp) ;
	while(!pq.empty()) 
	{
		temp = pq.top();
		pq.pop();
		val = temp.val;
		dist = temp.dist;
		if (vis[val])
		continue ; 
		else 
		{
			vis[val]  = 1;
			dist[val] = dist;
			for( int i = 0 ; i < G[val].size() ; i ++ )
			{
				k = G[val][i].val ;
				w = G[val][i].dist;
				if(vis[k])
				 continue;
				if(dist + w < G[val][i].dist)
				{
					temp.val = k
					temp.dist = dist + w;
					pq.push(temp) ;
				}
				
			}
		}
	}
	for(int i = 0 ; i < v_num ; i ++ )
	{
		answ += wei[i] * dist[i] ;
		ans.push_back(answ);
	}
	
 } 

int main()
{
	cin >> n ;
	for(int i = 0  ; i < n ; i ++ )
	{
		init();
		cin >> v_num >>e_num ; 
		for( int j = 0 ;  j <  v_num ; j++)
			cin>>wei[j];
		for(int j = 0 ; j < e_num ; j ++ )
		{
			cin >> a >> b >> c ;
			temp.val = b ;
			temp.dist = c ;
			G[a].push_back(temp); 
		}
		ans.push_back(dij()) ;
	 } 
	for (int i= 0 ; i  < ans.size() ;  i++ )
	{
		if (ans[i]!= -1)
		cout << ans[i] << endl;
		else 
		cout << "No Answer" <<endl ;
	}
	
	return 0 ;
	
}
