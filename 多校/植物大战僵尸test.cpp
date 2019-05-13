#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int vis[maxn][maxn];
int main(){
    srand(time(0));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i<m*n;i++){
        memset(vis,0,sizeof(vis));
        cout<<rand()%(10001)-rand()%10001<<' ';
        int tmp = rand()%(n*m+1);
        cout<<tmp<<' ';
        for(int i = 0;i<tmp;i++){
            int x = rand()%n+1;
            int y = rand()%m+1;
            while(vis[x][y]){
                x = rand()%n+1;
                y = rand()%m+1;
            }
            vis[x][y]=1;
            cout<<x<<' '<<y<<' ';
        }
        cout<<endl;
    }
    return 0;
}
