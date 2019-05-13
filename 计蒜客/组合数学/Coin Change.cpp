#include<bits/stdc++.h>
using namespace std;
const int maxn = 300;
const int lim = 101;
int c[maxn][lim], tmp[maxn][lim],n;
int a[5] = {1,5,10,25,50};
void init(){
    int i,j,k,u;
    memset(c,0,sizeof(c));
    memset(tmp,0,sizeof(tmp));
    for(i=0;i<lim;i++)
        c[i][i] = 1;
    for(i = 1;i < 5; i++){
        for(j = 0;j<maxn;j++){
            for(k=0;k+j<maxn;k+=a[i]){
                for(u = 0;u+k/a[i]<lim;u++)
                    tmp[k+j][u+k/a[i]] += c[j][u];
            }
        }
        for(j = 0;j<maxn;j++){
            for(u = 0;u<lim;u++)
                c[j][u] = tmp[j][u],tmp[j][u] = 0;
        }
    }
}
int main(){
    init();
    while(~scanf("%d",&n)){
        int ans = 0;
        for(int i = 0;i<lim;i++)
            ans+=c[n][i];
        printf("%d\n",ans);
    }
    return 0;
}
