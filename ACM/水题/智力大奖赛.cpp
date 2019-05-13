#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, cnt, ans;
    while(~scanf("%d", &n)){
        cnt = n * n;
        ans = 2 * n + n * (n + 1) / 2 + n * (n - 1);
        printf("%d\n%d\n", cnt, ans);
    }
    return 0;
}
