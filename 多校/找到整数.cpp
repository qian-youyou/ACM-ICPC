#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll b,c;
}aa[40007];
void init(){
    memset(aa,0,sizeof(aa));
    for(ll i = 3;i<=40000;i++){
        for(ll j = 1;j<i;j++){
            if(i*i%j==0){
                ll x = j;
                ll y = i*i/j;
                if((x+y)%2==0){
                    aa[i].c=(x+y)/2;
                    aa[i].b=(y-x)/2;
                    break;
                }
            }
        }
    }
}
int main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b,c,n;
        scanf("%lld%lld",&n,&a);
        if(n>2||n==0){
            printf("-1 -1\n");
            continue;
        }
        else if(n==1){
            printf("1 %lld\n",a+1);
            continue;
        }
        else{
            if(aa[a].b){
                printf("%lld %lld\n",aa[a].b,aa[a].c);
            }
            else
                printf("-1 -1\n");
        }

    }
    return 0;
}
