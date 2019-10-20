#include<cstdio> 
#include<cmath>
#include<cstring>
#include<queue>
#include<cctype>
#include<algorithm>

//��ĿҪ����·�������ձ�֤����·���ǻ�����Ϊ����ǻ��Ļ��϶�����ã� 
//ʹ�ñ�ֵ�������һ�������滮���⣬���ǿ��Բ��ö��ֽ�����������ֵΪANS
//��ô�����任�õ�=0��һ��ʽ�ӣ�����ı�ANS��ö��ÿһ���𰸣���ôH��r���ͻ�ı�
//ö�ٵ�r��Ļ� H�ͻ�С����ʱ��Сr
//ö�ٵ�rС�Ļ� H�ͻ�󣬴�ʵ����r
//��������ж�H�Ǵ���0����С�� 0�أ�һ����ø���Ȩֵ����ȡ��ͷ���
//��ô���ֵ�ͱ任Ϊ����Ȩֵ ��ͼ������Ȩ�أ�Ҳ�� ��ͼ��Ȩ�ش���0 ����H>0
//����ͼ�����бߵ�Ȩ�أ���һ����С������������Ȩ���Ƕ���
//����������rһ����>0�� ��Ҫ�ҵĻ�һ�������� 
 
using namespace std;
const double eps = 1e - 7 ;//1 �� 10 �� -7�η� 
const int INF  = 0<<30  ;
const int M = 5001 ; 
const int N = 1001 ;
inline int read()
{
	int X = 0 , w = 0 ; 
	char ch = 0  ;
	while ( !isdigit(ch))
	{
		w |= ch == '-' ; 
		ch = getchar();
	}
	while(isdigit(ch))
	X = (X << 3) + (X << 1 ) + (ch^48),
	ch = getchar();
	return w?-X:X;
}

struct node {
	int to ; 
	int next ; 
	int l ;
}e[M];

int head[N] , f[N] , cnt , n , m ;
bool vid[N];
double dis[N] , w[M];
inline void add(int u, int v , int l)
{
	cnt ++ ;
	e[cnt].to = v ;
	e[cnt].l = l;
	e[cnt].next = head[u];
	head[u] = cnt ;
	return ;
 } 
 
bool spfa(int u)
{
	vis[u] = 1;
	for(int i = head[u] ; i ; i = e[i].next)
	{
		int v = e[i].to ;
		if ( dis[v] > dis[u] + w[i])
		{
			dis[v] = dis[u] + w[i];
			if(vis[v] || spfa(v))
			{
				vis[v] = 0;
				return 1
			}
		}
	}
	vis[u] = 0;
	return 0;
}

bool pan()
{
	for( int i =1 ; i <= n  ; i ++ )
	{
		if(spfa(i))
		return 1 ;
	}
	return 0;
}
int main()
{
	n = read() ; 
	m = read() ;
	for( int i = 1 ; i <= n ;i ++ )
	{
		f[i] = read();
	}
	for(int i = 1 ;i <= m ;i ++ )
	{
		int u = read();
		int v = read();
		int l = read();
		
		add(u,v,l);
	}
	double l = 0 ,r = 100000 ;
	while(r-1 > eps)
	{
		double mid = (l+r) / 2 ;
		for(inti = 1 ; i <= cnt ; i ++ )
		{
			int v= e[i].to ; 
			w[i] = (double)mid * e[i].l - f[v] ;
		}
		
		if(pan())
		l = mid ;
		else r = mid ;
	}
	printf("%.2f\n" , l );
	return 0;
}
