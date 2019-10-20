#include<queue>
#include<stdio.h>
#include<vector>
#include<string.h>
#define INF 0x3f3f3f3f3f3f3f3f


//����һ��ͼ�����Ӵ�ͼ����һ������ʹ������������С��
//����Ȩ�ض���Ϊ���бߵ�Ȩ��֮�ͣ�ÿ���ߵ�����Ϊ
// �ߵ������������������������н�������
//���е�������������Ϊ����Ȩ�� 
//���ǿ��Ǽ���ʽ���߳��������ڵ��������ĳһ���ڵ�����������һ���ǲ�����ϵ�
//������һ����һֱ��һֱ�ˣ����Ŵ˽ڵ㵽Ŀ��ڵ��·�������ڵ㣩
//�����Ļ�·���ϵ�ÿ���߶�������һ��
//��Ϊ�����ڵ�����һ����·���ϵĽڵ�Ϊ���ڵ��������·��� 
//ÿ���ڵ㶼�����㣬���ܵ�Ȩ��Ҳ���������ˣ���Ϊÿ����ü����������ˡ�
//��Ϊ����Ҫ�������еĽڵ㣬����������֮��Ĳ������ÿ����㵽��ͷ��·������
 
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

