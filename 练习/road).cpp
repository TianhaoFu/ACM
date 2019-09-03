#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
struct road{
	int d;
	int l;
	int t;
};
int K,M,N;
vector<vector<road> > cityMap(110);
int midL[110][100];
int min_len;
int total_len;
int total_cost;
int visited[110][110];

void dfs(int s)
{
	if( s == N ) {
		min_len = min(min_len,total_len);
		return; 
	}
	for( int i = 0 ;i < cityMap[s].size() ; ++i)
	{
		int d = cityMap[s][i].d;
		if(!visited[s][d])
		{
			int cost = total_cost + cityMap[s][i].t;
			if( cost > K)
			continue;
			if(total_len + cityMap[s][i].l >= min_len)
			continue;
			total_len+=cityMap[s][i].l;
			total_cost+= cityMap[s][i].t;
			minL[d][cost] = total_len;
			visited[d] = 1;
			dfs(d);
			
			visited[d] = 0;
			total_cost -= cityMap[s][i].t;
			total_len -= cityMap[s][i].l;
		}
	}
}
int main()
{
	cin >> K >> N >> R:
	for(int i = 0 ;i< R ; ++ i){
		int s;
		road r;
		cin >> s >> r.d >> r.l >> r.t;
		if( s != r.d)
		
			cityMap[s].push_back(r);
		 } 
		for( int i = 0 ;i < 110 ; ++i)
		{
			for( int j = 0 ;j < 10100 ; ++j)
			{
				minL[i][j] = 1 << 30;
			 } 
		}
		memset(visited,0,sizeof(visited));
		tottal_len = 0;
		total_cost = 0;
		vivited[1] = 1;
		minLen = 1 << 30;
		dfs(1)
		if( min_len < (1<<30))
		cout<<min_len<<endl;
		else
		cout<< "-1" <<endl; 
	}
 } 




