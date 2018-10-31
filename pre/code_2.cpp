#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,ans[maxn],val[maxn];
int head[maxn],to[2*maxn],nex[2*maxn],cnt=0;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
int deep[maxn],find1[maxn][20];
void dfs(int u,int fa)
{
	deep[u]=deep[fa]+1;
	find1[u][0]=fa;
	for(int i=1;(1<<i)<=deep[u];i++)
	{
		find1[u][i]=find1[find1[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=nex[i])
	{
		if(to[i]!=fa) dfs(to[i],u);
	}
}
int LCA(int a,int b)
{
	if(deep[a]>deep[b]) swap(a,b);
	for(int i=19;i>=0;i--)
	{
		if(deep[a]<=deep[b]-(1<<i)) b=find1[b][i];
	}
	if(a==b) return a;
	for(int i=19;i>=0;i--)
	{
		if(find1[a][i]==find1[b][i]) continue;
		a=find1[a][i]; b=find1[b][i];
	}
	return find1[a][0];
}
int getsum(int u,int fa)
{
	find1[u][0]=fa;
	ans[u]=val[u]; 
	for(int i=head[u];i;i=nex[i])
	{
		if(to[i]!=fa)
		{
			ans[u]+=getsum(to[i],u);
		}
	}
	return ans[u];
}
int main()
{
	// freopen("B.in","r",stdin);
	// freopen("B.out","w",stdout);
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<=n-1;i++)
	{
		cin>>u>>v;
		add(u,v); add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n/2;i++)
	for(int j=i*2;j<=n;j+=i)
	{
		if( j%i==0 ) val[LCA(i,j)]++;
	}
	getsum(1,0);
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
}
