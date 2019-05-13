#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL maxn = 1e6+7;
LL a[maxn],b[maxn],cha[maxn],qian[maxn],qian2[maxn], hou[maxn], hou2[maxn];
void init(LL n,LL c){
    hou[n+1] = qian[0] = 0;
    hou2[n] = hou[n] = cha[n];
    qian2[1] = qian[1] = cha[1];
    for(int i = 2;i<=n;i++){
        qian[i] = cha[i]+qian[i-1];
        qian2[i] = min(qian[i],qian2[i-1]);
    }
    LL sum = 0;
    for(int i = n-1;i>0;i--){
        hou[i] = cha[i]+hou[i+1];
        hou2[i] = min(hou[i]-sum,cha[i]);
        if(hou2[i]>=0){
            sum=hou[i];
            hou2[i]=0;
        }
    }
}
int fun(LL n,LL c){
    if(qian[n]+c<0)
        return -1;
    for(int i = 1;i<=n;i++){
        if(cha[i]+c>=0&&cha[i]+c+hou2[i+1]>=0){
            if(hou[i]+c+qian2[i-1]>=0){
                return i;
            }
        }
    }
    return -1;
}
int main(){
    int t;
    LL n,c;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&c);
        for(int i = 1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i = 1;i<=n;i++){
            scanf("%lld",&b[i]);
            cha[i] = a[i] - b[i];
        }
        init(n,c);
        int tmp = fun(n,c);
        printf("%d\n",tmp);
    }
    return 0;
}
