//#define LOCAL
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
 
#define MAXN 110
#define INF 0x3f3f3f3f
int n;
int map[MAXN][MAXN];
int low[MAXN];
int dfn[MAXN];
int stack[MAXN], head;
int instack[MAXN];
int belong[MAXN];
int in[MAXN];
int out[MAXN];
int index, cnt;
 
int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
 
void init()
{
	int i, j;
	int temp;
	memset(map, 0, sizeof(map));
	memset(dfn, -1, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, 0, sizeof(instack));
	index = cnt = 1;
	head = 0;
	for(i= 1; i <= n; i++)
	{
		while(scanf("%d", &temp) && temp)
		{
			map[i][temp] = 1;
		}
	}
} 
void tarjan(int x)
{
	int i, a;
	low[x] = dfn[x] = index; // ���ѵ�һ���ڵ�ʱlow = dfn
	index++;
	stack[++head] = x; // ���ýڵ���ջ 
	instack[x] = 1; // ����ջ�������Ϊ1
	for(i = 1; i <= n; i++) // ������ջ�ڵ�ı�
	{
		if(!map[x][i]) // �������֮��û�б�
			continue; // ���ù���
		if(dfn[i] == -1) // ������������Ľڵ��Ǵ�δ��������
		{
			tarjan(i); // ����Ȼ�͵���������ڵ�
			low[x] = min(low[x], low[i]); // ���ݵ�ʱ��ı䵱ǰ�ڵ��lowֵ 
		}
		else if(instack[i]) // ������������Ľڵ��Ѿ�������������������ջ�� 
		{
			low[x] = min(low[x], dfn[i]); // ���µ�ǰ�ڵ��lowֵ���������˼�������ڵ�֮����һ���ɴ�ߣ���ǰ�� 
		} 								  // ��ǰ��ڵ��Ѿ���ջ�У���ô����Ľڵ�Ϳ��ܺ�ǰ��Ľڵ���һ����ͨ������ 
	} 
	
	if(low[x] == dfn[x]) // �����˻�����ʱ�� low == dfn �� û�нڵ��ܽ����ڵ���£��� 
	{					// low == dfn �Ľڵ��Ȼ���Ǹ��ڵ�
		int temp; 
		while(1) // һֱ��ջ���˽ڵ㣬 ��ЩԪ����һ��ǿ��ͨ���� 
		{
			temp = stack[head--]; // ����ջԪ�� 
			belong[temp] = cnt; // Ϊ�˷�����㣬��ǿ��ͨ�������б��
		 	instack[temp] = 0; // ��ջ�ڱ����Ϊ0 
		 	if(temp == x)     // һֱ����x����Ϊֹ 
		 		break;
		}
		cnt++;
	} 
}						
 
void solve()
{
	int i, j;
	int t1, t2;
	while(scanf("%d", &n) != EOF) //
	{
		init(); // ��ʼ�� 
		for(i = 1; i <= n; i++) //  
			if(dfn[i] == -1) // ���ĳ��û�����ʹ�����������tarjan 
				tarjan(i);			// tarjan�ĳɹ��ǵõ���һ��belong���飬��¼ÿ���ڵ�ֱ������ĸ�ǿ��ͨ���� 
		for(i = 1; i <= n; i++) // ����ÿ���ߣ��ҵ�����֮��ı� 
		{
			for(j = 1;j <= n; j++)
			{
				if(map[i][j] && belong[i] != belong[j]) // ����֮���бߣ�����������һ��ǿ��ͨ�����ı�
				{
					out[belong[i]]++; // �����ĵ����+1 
					in[belong[j]]++;// �����ĵ����+1 
				} 
			}		
		}
		
		t1 = 0, t2 = 0;
		
		for(i = 1; i < cnt; i++)
		{
			if(in[i] == 0)
				t1++;
			if(out[i] == 0)
				t2++;
		}
		if(cnt == 2)
			printf("1\n0\n");
		else
			printf("%d\n%d\n", t1, max(t1, t2));
	}
}
int main()
{
#ifdef LOCAL
	freopen("poj1236.txt", "r", stdin);
	// freopen(".txt", "w", stdout);
#endif
	solve();
	return 0;
}
