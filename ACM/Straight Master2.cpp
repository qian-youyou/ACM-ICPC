#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
ll a[maxn], b[maxn];
int n;
int main(){
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
        int flag = 1;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
        }
        a[n] = 0;
        b[0] = a[0];
        for(int i = 1; i <= n; i++){
            b[i] = a[i]-a[i-1];
        }
        if(b[0]<0||b[1]<0||b[2]<0){
            printf("Case #%d: No\n", cas);
            continue;
        }
        int cur = 0;
        for(int i = 0; i <= n; i++){
            if(b[i]>0){
                for(int j = max(i+3, cur); j <= n; j++){
                    if(b[i]*b[j]<0){
                        cur = j;
                        if(abs(b[i])>abs(b[j])){
                            b[i]+=b[j];
                            b[j] = 0;
                        }
                        else{
                            b[j]+=b[i];
                            b[i] = 0;
                            break;
                        }
                    }
                }
            }
            if(b[i]){
                flag = 0;
                break;
            }
        }
        if(flag){
            printf("Case #%d: Yes\n", cas);
        }
        else{
            printf("Case #%d: No\n", cas);
        }
    }
    return 0;
}
