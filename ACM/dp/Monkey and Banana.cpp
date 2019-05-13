#include<bits/stdc++.h>
using namespace std;
struct NODE{
    int x;
    int y;
    int h;
    NODE(){};
    NODE(int a, int b, int c):x(a),y(b),h(c){};
}node[2000];
int dp[2000];
int n, cnt;
bool cmp(NODE a, NODE b){
    if(a.x == b.x){
        return a.y > b.y;
    }
    return a.x > b.x;
}
int solve(){
    int ans = 0;
    for(int i = 0; i < cnt; i++){
        dp[i] = node[i].h;
        for(int j = 0; j < i; j++){
            if(node[j].x > node[i].x && node[j].y > node[i].y){
                dp[i] = max(dp[i], dp[j] + node[i].h);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main(){
    int cas = 0;
    while(~scanf("%d", &n)&&n){
        int a[3];
        cnt = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &a[0], &a[1], &a[2]);
            sort(a, a+3);
            node[cnt++] = NODE(a[2], a[1], a[0]);
            node[cnt++] = NODE(a[2], a[0], a[1]);
            node[cnt++] = NODE(a[1], a[0], a[2]);
        }
        sort(node, node + cnt, cmp);
        memset(dp, 0, sizeof(dp));
        printf("Case %d: maximum height = %d\n", ++cas, solve());
    }
    return 0;
}
