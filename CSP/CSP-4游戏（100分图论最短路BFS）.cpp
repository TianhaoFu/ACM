#include<iostream>
#include<cstdio>
#include<queue>
//广搜就是这样做的 
using namespace std ;
//关键点： inQueue数组的定义使得此题用广搜做成为可能 
struct Vertex
{
	int r ;
	int c ;
	int t ;
	Vertex(int rr , int cc , int tt): r(rr) , c(cc) , t(tt) {}
};

bool inQueue[105][105][305] ; 
//若把它放到main函数内部进行定义就不行 
int main()
{
	int n , m , t;
//	cin >> n  >> m >> t ;
//	printf("--1--");
	
	int directions[4][2] = {{1,0} , {0,1} , {-1,0} , {0,-1}} ;	
	
	scanf("%d%d%d" , &n  ,&m  ,&t) ;
//	printf("--2--"); 
	
	queue<Vertex> q ;
	q.push(Vertex(1,1,0)) ;
	int r , c , a , b ;
	while(t--)
	{
		scanf("%d%d%d%d" , &r , &c , &a  ,&b) ;
		for ( int i = a  ; i <= b ; i ++ )
			{
				inQueue[r][c][i] = true ;
			}
	}
	
	while(!q.empty())
	{
		Vertex v = q.front();
		q.pop() ; 
		
		if(v.r ==  n && v.c == m)
		{
//			printf("正在操作的点%d %d % d\n",v.r ,v.c , v.t);
			printf("%d" , v.t);
			break ; 
//			为什么找到的第一个就是呢？ 
//队列从前往后深度依次递增 
//时间从前往后依次增加 
		}
		 
		int r = v.r ;
		int c = v.c ;
		int t = v.t ;
		for ( int i = 0 ; i < 4 ; i ++)
		{
			
			r = v.r + directions[i][0] ;
			c = v.c + directions[i][1] ;
			t = v.t + 1 ;
			if( r > 0 && r <= n && c > 0 && c <= m &&!inQueue[r][c][t])
			{
				if(r ==  n && c == m)
				{
//			printf("正在操作的点%d %d % d\n",r ,c , t);
//			printf("%d" , v.t);
				}
//				printf("新加入点%d %d %d \n",r,c,t);
				q.push(Vertex(r , c , t)) ;
				inQueue[r][c][t] = true ;
			}
		}
		
	}
	
	return 0 ;
}

