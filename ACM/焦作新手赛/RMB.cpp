#include<bits/stdc++.h>
using namespace std;
const int maxn = 25007;
int reff[maxn], a[maxn], t, n, k;
bool cmp(int a,int b){
    return a > b;
}
void init(){
    reff[0] = 0;
    for(int i = 1; i<maxn; i++){
        reff[i] = reff[i-1] + i;
    }
}
void read(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i<n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n, cmp);
}
int solve(){
    int i;
    for(i = 1;i<n;i++){
        if(k<=reff[i])
            break;
    }
    return i;
}
int main(){
    init();
    scanf("%d",&t);
    while(t--){
        read();
        int i = solve();
        printf("%d\n", a[i]);
    }
    return 0;
}
