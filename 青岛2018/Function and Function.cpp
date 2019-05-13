#include<bits/stdc++.h>
using namespace std;
int T, x, k;
int a[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &x, &k);
        int cur;
        for(cur = 0; cur < k; cur++){
            if(!x){
                break;
            }
            int ans = 0;
            while(x){
                ans += a[x%10];
                x /= 10;
            }
            x = ans;
        }
        if(cur < k){
            int ans = (k - cur)%2 ? 1 : 0;
            printf("%d\n", ans);
        }
        else{
            printf("%d\n", x);
        }
    }
    return 0;
}
