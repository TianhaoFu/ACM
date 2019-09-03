#include<iostream> 
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct Edge{
	int v;
	int w;
	Edge(int v_ = 0, int w_ = 1<<30): v(v_),w(w_){
	}
	bool operator<(const Edge &e) const
	{
		return w>e.w;
	 } 
};
vector<vector<Edge > > G(110);

int HeapPrim(const vector<vector<Edge > > &G , int n)
{
	int i ,j, k;
	Edge xDist(0,0);
	priority_queue<Edge> pq;
	vector<int> vDist(n);
	vector<int> vUsed(n);
	int nDonenum = 0;
	
}
