#include<cstdio>
#include<cstring>
#include<queue>
using namespace std ;

#define MAXN 110  
#define INF 0x3f3f3f3f 

int n ; 
int map[MAXN][MAXN] ; 
int low[MAXN] ;
int dfn[MAXN] ;
int stack[MAXN] ,head ;
int instack[MAXN] ;
int belong[MAXN] ;
int in[MAXN] ;
int out[MAXN] ;
int index , cnt ;

int min(int a , int b ) 
{
	return a < b ? a : b ;
}

int max( int a , int b )
{
	return a > b ? a : b ;
}

void init()
{
	int temp ; 
	memset(map , 0 , sizeof(map)) ; 
	memset(dfn , -1 , sizeof(instack)) ; 
	index = cnt = 1 ;
	head = 0  ;
	for( int i =1 ; i <= n ; i ++ )
	{
		while ( scanf("%d" , temp) && temp )
		{
			map[i][temp] = 1 ;
		}
	 } 
}

void tarjan(int x )
{
	low[x] = dfn[x] = index ; 
	index ++ ;
	instack[++head] = x ;
	for( int i = 1 ; i <= n ; i ++ )
	{
		if(!map[x][i])
			continue ;
		if(dfn[i] == -1)
		{
			tarjan(i) ;
			low[x] = min(low[x] , low[i]) ;
		}
		else if(instack[i])
		//һ��Ҫ�ж�
		//��Ȼ���ܾͻᷢ��PPT��d��e�����
		//Ȼ��e�Ѿ���Ϊһ����ͨ����������
		//����Ҫ��δ�����ĵ����ͨ�����ſ� 
		{
			low[x] = min(low[x] , dfn[i]) ;
		}
	}
	
	if(low[x] == dfn[x])
	{
		int temp ;
		while(1)
		{
			temp = stack[head--] ;
			belong[temp] = cnt ; //Ϊ�˷�����㣬��ǿ��ͨ�������б��
			instack[temp] = 0 ; //��ջ�ڱ����Ϊ0 
			if(temp == x) //һֱ����x����Ϊֹ
				break ;
		}
		
		cnt++ ;//�����µ���ͨ�������λ 
	}
}

void solve()
{
	int t1 , t2 ;  
	while(scanf("%d" , &n) != EOF)
	{
		init() ;
		for(int  i = 1 ; i <= n ;i ++ )
		{
			if(dfn[i] == -1 )
				tarjan(i) ; 
		}
		// tarjan�ĳɹ��ǵõ���һ��belong���飬��¼ÿ���ڵ�ֱ������ĸ�ǿ��ͨ����
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j =1 ; j <= n ; j ++ )
			{
				if(map[i][j] && belong[i] !=belong[j])//����֮���бߣ�����������һ��ǿ��ͨ�����ı�
				{
					out[belong[i]]++ ; //�����ĵ����+1 
					in[belong[j]]++ ; // �����ĵ����+1
				}
			}
		}
		
		t1 = 0 ;
		t2 = 0 ;
		
		for(int i =1 ; i < cnt ; i ++ )
		{
			if(in[i] == 0)
				t1++ ;
			if(out[i] == 0)
				t2++ ;
		}
		
		if(cnt == 2)
			printf("1\n0\n") ;
		else 
			printf("%d\n%d\n" , t1 , max(t1,t1));
	}
}

int main()
{

#ifdef LOCAL
	freopen("poj1236.txt", "r", stdin);
	// freopen(".txt", "w", stdout);
#endif
	solve();

}
