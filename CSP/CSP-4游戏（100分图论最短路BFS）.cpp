#include<iostream>
#include<cstdio>
#include<queue>
//���Ѿ����������� 
using namespace std ;
//�ؼ��㣺 inQueue����Ķ���ʹ�ô����ù�������Ϊ���� 
struct Vertex
{
	int r ;
	int c ;
	int t ;
	Vertex(int rr , int cc , int tt): r(rr) , c(cc) , t(tt) {}
};

bool inQueue[105][105][305] ; 
//�������ŵ�main�����ڲ����ж���Ͳ��� 
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
//			printf("���ڲ����ĵ�%d %d % d\n",v.r ,v.c , v.t);
			printf("%d" , v.t);
			break ; 
//			Ϊʲô�ҵ��ĵ�һ�������أ� 
//���д�ǰ����������ε��� 
//ʱ���ǰ������������ 
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
//			printf("���ڲ����ĵ�%d %d % d\n",r ,c , t);
//			printf("%d" , v.t);
				}
//				printf("�¼����%d %d %d \n",r,c,t);
				q.push(Vertex(r , c , t)) ;
				inQueue[r][c][t] = true ;
			}
		}
		
	}
	
	return 0 ;
}

