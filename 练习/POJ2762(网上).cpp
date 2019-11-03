#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
usingnamespace std;

#define maxn 1005
#define maxm 5005

struct Edge
{
    int v, next;
} edge[maxm], opedge[maxm], newedge[maxm];

int n, m, head[maxn], ophead[maxn], ncount, nowtime, pos[maxn *2], sig[maxn], signnum, in[maxn], newhead[maxn];
bool flag[maxn], g[maxn][maxn];

void addedge(int a, int b)
{
    edge[ncount].v = b;
    edge[ncount].next = head[a];
    head[a] = ncount;
    opedge[ncount].v = a;
    opedge[ncount].next = ophead[b];
    ophead[b] = ncount;
    ncount++;
}

void input()
{
    scanf("%d%d", &n, &m);
    for (int i =0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        addedge(a, b);
    }
}

void dfs(int a)
{
    flag[a] =true;
    pos[nowtime] = a;
    nowtime++;
    for (int i = head[a]; i !=-1; i = edge[i].next)
        if (!flag[edge[i].v])
            dfs(edge[i].v);
    pos[nowtime] = a;
    nowtime++;
}

void rdfs(int a)
{
    flag[a] =true;
    sig[a] = signnum;
    for (int i = ophead[a]; i !=-1; i = opedge[i].next)
        if (!flag[opedge[i].v])
            rdfs(opedge[i].v);
}

bool ok()
{
    bool found;
    int a;

    memset(flag, 0, sizeof(flag));
    while (1)
    {
        found =false;
        for (int i =0; i < signnum; i++)
            if (in[i] ==0&&!flag[i])
            {
                if (found)
                    returnfalse;
                found =true;
                flag[i] =true;
                a = i;
            }
        if (!found)
            break;
        for (int i = newhead[a]; i !=-1; i = newedge[i].next)
            in[newedge[i].v]--;
    }
    returntrue;
}

int main()
{
    //freopen("D:\\t.txt", "r", stdin);
int t;
    scanf("%d", &t);
    while (t--)
    {
        ncount =0;
        memset(head, -1, sizeof(head));
        memset(ophead, -1, sizeof(ophead));
        memset(flag, 0, sizeof(flag));
        input();
        nowtime =1;
        for (int i =0; i < n; i++)
            if (!flag[i])
                dfs(i);
        memset(flag, 0, sizeof(flag));
        signnum =0;
        for (int i =2* n; i >0; i--)
            if (!flag[pos[i]])
            {
                rdfs(pos[i]);
                signnum++;
            }
        memset(g, 0, sizeof(g));
        memset(in, 0, sizeof(in));
        memset(newhead, -1, sizeof(newhead));
        ncount =0;
        for (int i =0; i < n; i++)
            for (int j = head[i]; j !=-1; j = edge[j].next)
                if (sig[i] != sig[edge[j].v] &&!g[sig[i]][sig[edge[j].v]])
                {
                    int a = sig[i];
                    int b = sig[edge[j].v];
                    g[a][b] =true;
                    in[b]++;
                    newedge[ncount].v = b;
                    newedge[ncount].next = newhead[a];
                    newhead[a] = ncount;
                    ncount++;
                }
        if (ok())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return0;
}
