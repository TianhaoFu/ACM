#include<cstdio> 
#include<cmath>
#include<cstring>
#include<queue>
#include<cctype>
#include<algorithm>

//题目要求条路径（最终被证明是路径是环，因为如果是环的话肯定解最好） 
//使得比值最大，这是一个分数规划问题，我们可以采用二分解决，设其最大值为ANS
//那么经过变换得到=0的一个式子，如果改变ANS，枚举每一个答案，那么H（r）就会改变
//枚举的r大的话 H就会小，此时减小r
//枚举的r小的话 H就会大，此实增大r
//我们如何判断H是大于0还是小于 0呢，一般采用更换权值，提取求和符号
//那么这个值就变换为环的权值 即图的所有权重，也即 若图的权重大于0 则是H>0
//代替图中所有边的权重，求一个最小环，看环的总权重是多少
//满足条件的r一定是>0的 即要找的环一定是正环 
 
using namespace std;
const double eps = 1e - 7 ;//1 乘 10 的 -7次方 
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
