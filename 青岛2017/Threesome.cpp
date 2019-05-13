#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int edge[307][307];
int main(){
    int T, n;
    scanf("%d", &T);
    while(T--){
        int u, v, w;
        scanf("%d", &n);
        memset(edge, 0, sizeof(edge));
        for(int i = 0; i < n * (n - 1) / 2; i++){
            scanf("%d%d%d", &u, &v, &w);
            edge[v][u] = edge[u][v] = w;
        }
        int maxd = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                for(int k = j + 1; k <= n; k++){
                    maxd = max(maxd, edge[i][j] + edge[i][k] + edge[j][k]);
                }
            }
        }
        printf("%d\n", maxd);
    }
    return 0;
}
