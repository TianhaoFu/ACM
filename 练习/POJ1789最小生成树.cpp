#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm> 
using namespace std;
#define MAXN 100

int parent[MAXN] = {1,2,3,4};
int N;

struct edge{
	int u1;
	int v1;
	string u;
	string v;
	int w;
	edge(string uu,string vv):u(uu),v(vv) {}
	edge () {}
	bool operator<(const edge &e) const//两个const要一起加 
	{
		return w < e.w;
	}
};

int get_length(edge e)
{
	int count = 0 ;
		for(int i = 0 ; i < 7 ; i++ )
		{
			if(e.u[i]!=e.v[i])
				count++;
		}
	return count;
}
vector< edge > G;
priority_queue<edge> pq;

int getroot(int a)
{
	if (parent[a] == a)
	return a;
	parent[a] = getroot(parent[a]);
	return parent[a];
}
void merge(int a,int b)
{
	int p1 = getroot(a);
	int p2 = getroot(b);
	if(p1 == p2)
		return ;
	else 
		parent[p2]= p1;
	
}
int kruskal( )
{
	sort(G.begin(),G.end());
	int done = 0;
	int totalLen = 0;
	for(int i = 0 ; i < G.size() ; i ++ )
	{
		int u = G[i].u1;
		int v = G[i].v1;
		if (getroot(u) != getroot(v))
		{
			merge(u,v);
			done++;
			totalLen += get_length(G[i]);
		}
		if ( done ==N-1 ) 
			break ; 
	} 
	return totalLen;
}

int main()
{
	string node[MAXN] = {"aaaaaaa","baaaaaa","abaaaaa","aabaaaa"};
//	cin >> N;
	N = 4;
	
//	for(int  i  = 0 ; i < N ;i ++ )
//	{
//		cin >> node[i];
//		parent[i] = i;
//	}
//	getchar(); 
	for(int i = 0 ; i < N; i ++ )
	{
		for( int j = i ; j < N ; j ++ )
		{
			if(i==j) continue;
			edge edge1(node[i],node[j]);
			edge1.u1 = parent[i];
			edge1.v1 = parent[j];
			edge1.w = get_length(edge1);
			G.push_back(edge1);
		 }
	 }
	cout << "The highest possible quality is 1/" << kruskal()<<endl;
	return 0 ;
}
