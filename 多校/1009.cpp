#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;
const ll mod = 1e9+7;
ll sum[maxn], n;
ll dp[maxn];
ll jie[maxn];
ll jie2[maxn];
struct Edge
{
    ll v, w;
};
vector<Edge> tree[maxn];
void init(){
    jie[2] = 2;
    for(ll i = 3;i<maxn;i++){
        jie[i] = jie[i-1]*(i-1)%mod;
    }
}
void dfs(ll cur, ll father)
{
    sum[cur] = 1;
    for(ll i = 0; i < tree[cur].size(); i++)
    {
        ll son = tree[cur][i].v;
        ll len = tree[cur][i].w;
        if(father == son)
            continue;
        dfs(son, cur);
        sum[cur] += sum[son]%mod;
        sum[cur]%=mod;
        dp[cur] += (dp[son]%mod + (n-sum[son])%mod*sum[son]%mod * len%mod)%mod;
        dp[cur]%=mod;
    }
}
int main()
{
    init();
    ll u, v, w;
    while(scanf("%lld", &n)!=EOF)
    {
        if(n<=2){
            if(n==1){
                printf("0\n");
                continue;
            }
            scanf("%lld%lld%lld", &u, &v, &w);
            printf("%lld\n", 2*w%mod);
            continue;
        }
        for(ll i = 0; i < n; i++)
            tree[i].clear();
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));
        for(ll i = 0; i < n-1; i++)
        {
            scanf("%lld%lld%lld", &u, &v, &w);
            u--,v--;
            Edge t1, t2;
            t1.v = v;
            t1.w = w;
            t2.v = u;
            t2.w = w;
            tree[u].push_back(t1);
            tree[v].push_back(t2);
        }
        dfs(0, -1);
        printf("%lld\n", (dp[0]%mod)*jie[n]%mod);
    }
    return 0;
}
