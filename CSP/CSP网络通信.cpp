#include<iostream>> 
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<bitset>
#include<iterator>
//https://www.cnblogs.com/hlhdidi/p/5960018.html
//������������������Խ������ͼ�еĵ���ɴ�������:��:����һ������ͼ��һ�����s,�ش��Ƿ����һ����s�����������v������·��������.

//��n�������һ��dfs����һ����ά�����¼�� ����� ����ϵ�ĵ�
//(Ҳ����dfs���Ե��ĵ�)��
//�������s���յ�e����ϵ(����dfs���Ե����)��
//��ô�յ�e�����s��Ҳ����ϵ(����dfs���Ե����)��
//ֱ�ӱ��connect[s][e] = connect[e][s] = 1�ͺ��ˣ�
//���ԾͲ���������dfs�ˣ�
//���ͳ��һ��ÿ����������ĵ������n��(�����Լ�)��
//��sum++

using namespace std ; 
typedef long long ll ;
const int inf = 0x3f3f3f3f ;
const ll INF = 0x3f3f3f3f3f3f3f3f3f ;
const double PI = acos(-1.0)  ;
const double E = exp(1.0) ;
const int MPD = 1e0+7 ;
const int MAX = 1e3+5 ;
int n , m;

vector <int > g[MAX] ;
int connect[MAX][MAX] ;
int vis[MAX] ;

void dfs( int s, int cur)
{
	vis[cur] = 1 ;
	connect[s][cur] = connect[cur][s] = 1 ;
	for ( int i = 0 ;  i < (int)g[cur].size() ; i ++ )
	{
		if(  !vis[g[cur][i]])
		{
			dfs(s , g[cur][i]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false) ;
	cin.tie(0)  ;
	cout.tie(0) ; 
	
	while( cin >> n >> m )
	{
		memset(connect,0,sizeof(connect)) ; 
		int a , b  ;
		for ( int i = 1 ;  i <= m ; i ++ ) 
		{
			cin  >> a >> b  ;
			g[a].push_back(b) ; 
		}	 
		
		for(int i = 1 ;i <= n; i ++)
		{
			memset(vis , 0  ,sizeof(vis)) ;
			dfs(i ,i);
		}
		
		int sum = 0 ; 
		
		for ( int i = 1  ; i <=n ; i ++ )
		{
			int tmp = 0 ;
			for ( int j = 1 ; j <= n ;j ++)
			{
				if( connect[i][j])
				{
					tmp++ ;
				}
				
			}
			
			if(tmp == n )
			{
				sum++ ;
			}
		}
		cout << sum << endl ;
	} 
	
	return 0 ;
}
