#include<bits/stdc++.h>
using namespace std;
int A, B, C;
bool dp[21];
bool vis[21][21][21];
void dfs(int a, int b, int c){
    if(vis[a][b][c]){
        return;
    }
    vis[a][b][c] = true;
    if(a == 0){
        dp[c] = true;
    }
    if(a){
        if(B-b) dfs(a-min(B-b,a), b+min(B-b,a), c);
        if(C-c) dfs(a-min(C-c,a), b, c+min(C-c,a));
    }
    if(b){
        if(A-a) dfs(a+min(A-a,b), b-min(A-a,b), c);
        if(C-c) dfs(a, b-min(C-c,b), c+min(C-c,b));
    }
    if(c){
        if(A-a) dfs(a+min(A-a,c), b, c-min(A-a,c));
        if(B-b) dfs(a, b+min(B-b,c), c-min(B-b,c));
    }
}
int main(){
    scanf("%d%d%d", &A, &B, &C);
    memset(dp, false, sizeof(dp));
    memset(vis, false, sizeof(vis));
    dfs(0, 0, C);
    for(int i = 0; i < C; i++){
        if(dp[i]){
            printf("%d ", i);
        }
    }
    printf("%d\n", C);
    return 0;
}
