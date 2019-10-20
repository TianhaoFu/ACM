#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;

const int NN=1005;
const int MM=10010;
const double INF=1e20;
const double eps=1e-5;  //网上有ac代码卡精度为0.001的

int n,m,S;
double w[NN];

struct Edge{
    int v,next;
    double d;      //用int存d时,时间消耗大(int 813ms,double 750ms)，不同类型间的运算时间比同一类型间的慢
}edge[MM];
int ecnt,head[NN];
void addedge(int u,int v,double d)
{
    edge[ecnt].v=v;
    edge[ecnt].d=d;
    edge[ecnt].next=head[u];
    head[u]=ecnt++;
}

double dis[NN];
bool inq[NN];
int cou[NN];
bool spfa(double ave)
{
    for (int i=1; i<=n; i++)
    {
        inq[i]=false;
        dis[i]=INF;
        cou[i]=0;
    }
    dis[S]=0.0;
    queue<int> que;
    que.push(S);
    while (!que.empty())
    {
        int u=que.front();
        que.pop();
        inq[u]=false;
        for (int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].v;
            if (dis[v]>dis[u]+ave*edge[i].d-w[u])
            {
                dis[v]=dis[u]+ave*edge[i].d-w[u];
                if (!inq[v])
                {
                    que.push(v);
                    inq[v]=true;
                }
                if (++cou[v]>n) return true;
            }
        }
    }
    return false;
}

void solve()
{
    double l=0.0;
    double r=1e8;
    double mid;
    while (r-l>=eps)
    {
        mid=(l+r)*0.5;    //若考虑精度，乘法比除法精度保持好一点，有乘有除时也应先乘后除，这里不需要。。。
        if (spfa(mid)) l=mid;
        else           r=mid;
    }
    printf("%.2f\n",mid+eps);  //也是看了别人这么加了eps,也有没加的,加了是考虑到小数类于0.999...的情况的。。。
}

int main()
{
    ecnt=0;
    mem(head,-1);
    scanf("%d%d",&n,&m);
    S=0;
    w[S]=0;
    for (int i=1; i<=n; i++)
    {
        addedge(S,i,0);
        scanf("%lf",&w[i]);
    }
    int x,y,z;
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z*1.0);
    }
    solve();
    return 0;
}
