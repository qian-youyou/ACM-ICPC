#include<bits/stdc++.h>
using namespace std;
const int maxn = 51;
const int maxx = 250007;
int c[maxx],tmp[maxx];
struct node{
    int v,m;
}inf[maxn];
int n,sum;
int cmp(node a,node b){
    return a.v<b.v;
}
void read(){
    sum = 0;
    for(int i = 0;i<n;i++){
        scanf("%d%d",&inf[i].v,&inf[i].m);
        sum+=inf[i].v*inf[i].m;
    }
}
int solve(){
    int i,j,k;
    memset(tmp,0,sizeof(tmp));
    memset(c,0,sizeof(c));
    sort(inf,inf+n,cmp);
    for(i = 0;i<=inf[0].m;i++)
        c[i*inf[0].v] = 1;
    for(i = 1;i<n;i++){
        for(j = 0;j<=sum;j++){
            if(c[j]){
                for(k = 0;(k<=inf[i].m)&&(j+k*inf[i].v<=sum);k++)
                    tmp[j+k*inf[i].v] += c[j];
            }
        }
        for(j = 0;j<=sum;j++){
            c[j] = tmp[j];
            tmp[j] = 0;
        }
    }
    for(i = sum/2;i>=0;i--){
        if(c[i])
            return sum - i;
    }
    return 0;
}
int main(){
    while((~scanf("%d",&n))&&n>0){
        read();
        int ans = solve();
        printf("%d %d\n",ans,sum-ans);
    }
    return 0;
}
