#include<bits/stdc++.h>
using namespace std;
const int N = 107;
int res[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int n,m;
struct node{
    int x,y;
}S,T;
char Map[N][N];
int vis[N][N];
int dfs(int x, int y){
    if(x==T.x&&y==T.y)
        return 1;
    else if(Map[x][y]=='B')
        return 1;
    else if(Map[x][y]=='#')
        return 0;
    for(int i = 0;i<4;i++){
        if(!vis[x+res[i][1]][y+res[i][2]]){
            vis[x+res[i][1]][y+res[i][2]] = 1;
            int tmp = dfs(x+res[i][1],y+res[i][2]);
            if(tmp)
                return 1;
        }
    }
    return 0;
}
int bfs(){
    return 1;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n+m==0)
            break;
        for(int i = 0;i<n;i++){
            scanf("%s",Map[i]);
            for(int j = 0;j<m;j++)
                if(Map[i][j]=='S')
                    S.x = i,S.y = j;
                else if(Map[i][j]=='T')
                    T.x = i,T.y = j;
        }
        if(dfs(S.x,S.y)==0){
            printf("-1\n");
            continue;
        }
        else{
            int ans = bfs();
            printf("%d\n",ans);
        }
    }
    return 0;
}
