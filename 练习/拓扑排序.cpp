#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool Topsort(vector<vector<int> > &G,int n,vector<int> &inDegree){
	int num = 0;
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (inDegree[i] == 0)
			q.push(i);
	while(!q.empty())  {
		int u = q.front();
		cout << u << " ";
		q.pop();
		for( int i = 0 ; i < G[u].size() ; i++)
		{
			int v = G[u][i];
			inDegree[v]--;
			if ( inDegree[v] == 0)
				q.push(v);
		}
		G[u].clear();
		num++;
	}
	if ( num == n)
		return true;
	else 
		return false;
}
int main()
{
	int n , m;
	cin >> n >> m;
	vector< vector<int> > G(n);
	for ( int i = 0; i < m; i++)
	{
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	vector<int> inDegree(n);
	for ( auto x:G){
		for (auto y : x)
			inDegree[y]++;
	}
	bool res = Topsort(G ,n , inDegree);
	
	return 0;
}
