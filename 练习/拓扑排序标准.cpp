
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
bool TopSort(vector<vector<int> > &G, int n, vector<int> &inDegree) {
	/*
	*	param
	*	G��	�ڽӱ�
	*	n��	������
	*	InDegree��	��¼��������	
	*/
	int num = 0;				//��¼������������Ķ�����
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (inDegree[i] == 0)
			q.push(i);		//���������Ϊ0�Ķ������
	while (!q.empty()) {
		int u = q.front();		//ȡ���׶���u
		cout << u << " ";		
		q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];		//u�ĺ�̽ڵ�
			inDegree[v]--;			//v����ȼ�1
			if (inDegree[v] == 0)		//����v����ȼ�Ϊ0�����
				q.push(v);
		}
		G[u].clear();			//��ն���u�����г���
		num++;
	}
	if (num == n)				//�����������еĶ�����Ϊn��˵����������ɹ�������ʧ��
		return true;
	else
		return false;
}
 
int main() {
	int n, m;
	cout << "�����붥�����ͱ���:";
	cin >> n >> m;
	vector<vector<int> > G(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cout << "�������" << i+1 << "���ߵĶ���:";
		cin >> x >> y;
		G[x].push_back(y);
	}
	cout << "��������Ϊ:";
	vector<int> inDegree(n);
	for ( int i = 0 ; i< n ; i++ )
	{
		for ( int j = 0 ; j < G[i].size() ; j ++ )
		{
			inDegree[G[i][j]]++;
		}
	 } 
//	for (auto x : G) {
//		for (auto y : x)
//			inDegree[y]++;
//	}
	bool res = TopSort(G,n,inDegree);
 
	return 0;
	
}
