#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
 
#define ll long long
#define ull unsigned long long
 
using namespace std;

int n;
int w[101000];
int dep[101000];
int fa[101000][20];
int h[101000],nx[202000],to[202000],cnt;

inline void add(int f,int t) {
    nx[++cnt] = h[f]; h[f] = cnt; to[cnt] = t;
    nx[++cnt] = h[t]; h[t] = cnt; to[cnt] = f;
}

inline void dfs(int x) {
    for(int i = h[x]; i; i = nx[i])
        if(to[i] != fa[x][0]) {
            fa[to[i]][0] = x;
            dep[to[i]] = dep[x] + 1;
            dfs(to[i]);
        }
}

inline int LCA(int x,int y) {
    if(dep[x] < dep[y]) swap(x,y);
    for(int i = 19; i >= 0; i--)
        if(dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
    if(x == y) return x;
    for(int i = 19; i >= 0; i--)
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    return fa[x][0];
}

inline int deal(int x) {
    int now = w[x];
    for(int i = h[x]; i; i = nx[i])
        if(to[i] != fa[x][0]) {
            now += deal(to[i]);
        }
    w[x] = now;
    return now;
}

int main() {
    scanf("%d",&n);
    int a,b;
    for(int i = 1; i < n; i++) {
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    dep[1] = 1;
    dfs(1);
    for(int i = 1; i <= 19; i++)
        for(int j = 1; j <= n; j++)
            fa[j][i] = fa[fa[j][i-1]][i-1];
    for(int i = 1; i <= n; i++)
        for(int j = 2; i * j <= n; j++) {
            int lca = LCA(i,j*i);
            w[lca]++;
        }
    deal(1);
    for(int i = 1; i <= n; i++)
        printf("%d\n",w[i]);
}