#include<bits/stdc++.h>
using namespace std;
const int maxn = 32 + 1;
int dis[maxn][maxn];
int vis[maxn];
void init(){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[32][32] = 0;
    for(int i = 1; i < maxn - 1; i++){
        dis[i][i] = 0;
        dis[i][i + 1] = 1;
        dis[i + 1][i] = 1;
    }
    dis[1][13] = dis[13][1] = 1;
    dis[17][13] = dis[13][17] = 1;
    dis[17][32] = dis[32][17] = 1;
    dis[15][32] = dis[32][15] = 1;
    dis[19][32] = dis[32][19] = 1;
    for(int k = 1; k < maxn; k++){
        for(int i = 1; i < maxn; i++)
            for(int j = 1; j < maxn; j++)
                if(dis[i][j] > dis[i][k]+dis[k][j])
                    dis[i][j] = dis[i][k]+dis[k][j];
    }
}
void dfs(int x){
    vis[x] = 0;
    for(int i = 1; i < maxn; i++){
        if(vis[i]&&dis[x][i]==1)
            dfs(i);
    }
}
int main(){

    init();
    int t;
    cin>>t;
    for(int u = 1;u <= t;u++){
        for(int i = 1;i < maxn; i++)
            cin>>vis[i];
        int ans = 0;
        for(int i = 1; i < maxn; i++){
            if(vis[i]){
                ans++;
                dfs(i);
            }
        }
        cout<<"Case "<<u<<": "<<ans<<endl;
    }
    return 0;
}
