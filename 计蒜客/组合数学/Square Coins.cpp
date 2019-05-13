#include<bits/stdc++.h>
using namespace std;
const int maxn = 301;
int re[18],c[maxn],tmp[maxn],n;
void init(){
    int i,j,k;
    memset(c,0,sizeof(c));
    memset(tmp,0,sizeof(tmp));
    for(i = 0;i<18;i++)
        re[i] = i*i;
    for(i = 0;i<maxn;i++)
        c[i] = 1;
    for(i = 2;i<18;i++){
        for(j = 0;j<maxn;j++){
            if(c[j])
                for(k = 0;j+k<maxn;k+=re[i]){
                    tmp[j+k] += c[j];
                }
        }
        for(j = 0;j<maxn;j++){
            c[j] = tmp[j];
            tmp[j] = 0;
        }
    }
}
int main(){
    init();
    while((~scanf("%d",&n))&&n){
        printf("%d\n",c[n]);
    }
    return 0;
}
