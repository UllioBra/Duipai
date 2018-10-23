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

const int inf = 1e9+1;
const int mod = 998244353;
int n,m;
int mx_le = 0;
ll mx_ans = 0;
bool st = 0;
bool vis[1010];
ll mp[1010][1010];
ll h[1010];

void dfs(int x,int le,ll sum) {
    if(le > mx_le) mx_ans = sum, mx_le = le;
    for(int i = 1; i <= n && !st; i++)
        if(mp[x][i] < inf)
            if(vis[i]) {
                st = 1;
                return;
            } else {
                vis[i] = 1;
                dfs(i,le+1,(sum + mp[x][i]*h[le]) % mod);
                vis[i] = 0;
            }
}

int main() {
    scanf("%d%d",&n,&m);
    ll a,b,c;
    memset(mp,0x3f,sizeof mp);
    h[0] = 1;
    for(int i = 1; i <= 1000; i++) {
        h[i] = (h[i-1] * 29) % mod;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld",&a,&b,&c);
        mp[a][b] = min(mp[a][b],c);
    }
    for(int i = 1; i <= n; i++) {
        mx_le = 0;
        mx_ans = 0;
        st = 0;
        vis[i] = 1;
        dfs(i,1,0);
        vis[i] = 0;
        if(st) printf("Infinity\n");
        else printf("%lld\n", mx_ans);
    }
}
