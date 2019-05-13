#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;
int re[3] = {1,2,5};
int num[3];
int c[maxn],tmp[maxn];
int solve(){
    int i,j,k;
    memset(c,0,sizeof(c));
    memset(tmp,0,sizeof(tmp));
    for(i = 0;i<3;i++){
        if(num[i]){
            for(j = 0;re[i]*j<maxn&&j<=num[i];j++){
                c[re[i]*j] = 1;
            }
            break;
        }
    }
    for(i = i+1;i<3;i++){
        if(num[i]){
            for(j = 0;j<maxn;j++){
                if(c[j])
                    for(k = 0;k<=num[i];k++){
                        tmp[j+re[i]*k]+=c[j];
                    }
            }
            for(j = 0;j<maxn;j++){
                c[j] = tmp[j];
                tmp[j] = 0;
            }
        }
    }
    for(i = 1;i<maxn;i++){
        if(!c[i])
            return i;
    }
    return 0;
}
int  main(){
    while(~scanf("%d%d%d",&num[0],&num[1],&num[2])){
        if(num[0]+num[1]+num[2]==0)
            break;
        printf("%d\n",solve());
    }
    return 0;
}
