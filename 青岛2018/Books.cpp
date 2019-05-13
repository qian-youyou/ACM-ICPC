#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;
const ll inf = 0x3f3f3f3f3f;
int n, m;
ll a[maxn];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        ll ans = 0;
        int cnt = 0;
        scanf("%d%d", &n, &m);
        ll minX = inf;
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
            if(!a[i]){
                cnt++;
            }
            else{
                minX = min(minX, a[i]);
            }
        }
        if(n == m){
            printf("Richman\n");
        }
        else if(cnt > m){
            printf("Impossible\n");
        }
        else{
            m -= cnt;
            if(!m){
                printf("%lld\n", minX - 1);
                continue;
            }
            int cur = 0, i;
            for(i = 0; i < n && cur < m; i++){
                if(a[i]){
                    ans += a[i];
                    cur++;
                }
            }
            minX = inf;
            for(; i < n; i++){
                if(a[i]){
                    minX = min(minX, a[i]);
                }
            }
            if(minX == inf){
                minX = 1;
            }
            printf("%lld\n", ans+minX-1);
        }
    }
    return 0;
}
