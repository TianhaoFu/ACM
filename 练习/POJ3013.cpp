#include<queue>
#include<stdio.h>
#include<vector>
#include<string.h>
#define INF 0x3f3f3f3f3f3f3f3f


//给定一张图，欲从此图生成一棵树，使得树的质量最小，
//树的权重定义为所有边的权重之和，每个边的重量为
// 边的重量乘其子树所包含的所有结点的重量
//所有的重量加起来及为树的权重 
//我们考虑计算式，边乘其子树节点的重量，某一个节点所属的子树一定是层层向上的
//所以它一定会一直乘一直乘（沿着此节点到目标节点的路径子树节点）
//这样的话路径上的每条边都被成了一遍
//因为他属于的子树一定是路径上的节点为根节点依次往下分配 
//每个节点都这样算，则总的权重也都计算完了，因为每条变得计算量都完了。
//因为树需要包含所有的节点，所以树与树之间的差别在于每条结点到尽头的路径长度
 
using namespace std;
const int maxn = 50005;
int vv[maxn];
int pos[maxn*2] , vis[maxn] , num ;
long long dis[maxn] , ans ;
struct node1
{
	int en , val , next ;
}a[maxn*2];

struct node
{
	int id , val ;
	node(int idd = 0, int vall = 0):id(idd) , val(val){}
	friend bool operator <(node x,node y)
	{
		return x.val > y.val;
	}
};

void add( int st , int en , int val)
{
	a[num].en = en ;
	a[num].val = val ;
	a[num].next = pos[st] ;
	pos[st] = num++ ;
}

void dij()
{
	dis[1] = 0;
	priority_queue<node> q ;
	q.push(node(1,dis[1]));
	while(!q.empty() )
	{
		node now = q.top();
		q.pop()	;
		if(vis[now.id]) continue;
		
		vis[now.id] = 1 ;
		for( int i = pos[now.id] ; i != -1 ; i = a[i].next)
		{
			if(!vis[a[i].en] && dis[a[i].en] > dis[now.id]+a[i].val)
			{
				dis[a[i].en] = dis[now.id] + a[i].val;
				q.push(node(a[i].en , dis[a[i].en]));
			}
		}
	}
}

void init()
{
	ans = 0;
	num = 0;
	memset(vis , 0 , sizeof(vis)) ;
	memset(dis , 0x3f , sizeof(dis));
	memset(pos , -1 , sizeof(pos));
}
int main()
{
	int t ;
	int v , e ;
	int x , y , z ;
	scanf("%d" , &t) ;
	while(t--)
	{
		init() ; 
		scanf("%d%d" , &v , &e);
		
		for( int i = 1 ; i <= v ; i ++ )
		{
			scanf("%d" , &vv[i]) ;
		}
		
		while(e--)
		{
			scanf("%d%d%d" , &x , &y , &z);
			add( x , y , z ) ;
			add( y , x , z ) ;
		}
		
		dij() ; 
		
		int flag = 1 ; 
		
		
		for( int i =1 ; i <= v ; i ++ )
		{
			if ( dis[i] == INF )
			{
				flag = 0 ; 
				break ;
			}
			ans += dis[i] * vv[i] ;
		 } 
		 
		 if (flag)
		 	printf("%lld\n" , ans);
		else 
			printf("No Answer\n") ; 
	}
	
	return 0 ;
}

