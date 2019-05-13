#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
        scanf("%d", &n);
        double ans = 0, tmp, tmp1, tmp2;
        for(int i = 0; i <= n; i++){
            cin >> tmp;
            ans += tmp;
        }
        tmp = 0;
        for(int i = 0; i < n; i++){
            cin >> tmp1 >> tmp2;
            tmp = max(tmp, tmp2);
        }
        ans+= tmp;
        printf("Case #%d: %.6lf\n", cas, ans);
    }
    return 0;
}
