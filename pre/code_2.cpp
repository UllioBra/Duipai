#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct Edge{int to,next,dis;}edge[1000100];
const int mod=998244353;
struct data{
    int id,dist,str,ran;
    bool operator <(const data &A) const
    {
        if (dist==A.dist)
        {
            if (str==A.str) return ran>A.ran;
            return str>A.str;
        }
        return dist>A.dist;
    }
};
int head[1000100],n,m,in[1000100],num,ans[1000100];
int dis[1000100],pre[1000100],bes[1000100],rn[1000100],cnt;
int read()
{
    int f=1,k=0;char c=getchar();
    while(c<'0'||c>'9') c=='-'&&(f=-1),c=getchar();
    while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
    return k*f;
}
void add(int u,int v,int w)
{
    edge[++num].to=v;
    edge[num].next=head[u];
    edge[num].dis=w;
    head[u]=num;
}
int chen(int x,int y){return 1ll*x*y%mod;}
void topo()
{
    priority_queue<data> q;
    for(int i=1;i<=n;i++) if (!in[i]) {q.push((data){i,0,0,0}); ans[i]=0;}
    while(!q.empty())
    {
        int u=q.top().id; q.pop(); rn[u]=++cnt;
        if (ans[u]==-1) ans[u]=chen(ans[bes[u]]+pre[u],29);
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if ((dis[v]<dis[u]+1)||((dis[v]==dis[u]+1)&&((edge[i].dis<pre[v])||(edge[i].dis==pre[v]&&rn[bes[v]]>rn[u]))))
            {
                dis[v]=dis[u]+1; pre[v]=edge[i].dis; bes[v]=u;
            }
            in[v]--;
            if (!in[v]) q.push((data){v,dis[v],pre[v],rn[bes[v]]});
        }
    }
}
int main()
{
    int x,y,w;
    n=read(); m=read();
    for(int i=1;i<=m;i++){x=read(); y=read(); w=read(); add(y,x,w); in[x]++;}
    memset(ans,-1,sizeof(ans));
    topo();
    for(int i=1;i<=n;i++)
    {
        if (ans[i]==-1) printf("Infinity\n");
        else printf("%d\n",ans[i]);
    }
    return 0;
}
