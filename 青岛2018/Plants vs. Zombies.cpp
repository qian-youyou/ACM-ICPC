#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
typedef long long ll;
ll a[maxn], c[maxn];
int n;
ll m;
bool check(ll high){
    memset(c, 0, sizeof(c));
    ll temp=m;
    if(m==0)return false;
    c[1]=a[1],m--;
    int i=1;
    for(;i<=n;i++)
    {
        if(m<=0)break;
        if(c[i]>=high)
        {
            if(m>0)
            {
            c[i+1]=a[i+1];
            m--;
            continue;
            }else{
                break;
            }
        }
        ll tmp=(ll)ceil((high-c[i])*1.0/a[i]);
        if(m>2*tmp){
            m-=2*tmp+1;
            c[i]+=a[i]*tmp;
            c[i+1]+=a[i+1]*(tmp+1);
            continue;
        }else if(m==2*tmp){
            c[i]+=a[i]*tmp;
            c[i+1]+=a[i+1]*tmp;
            break;
        }else{
            break;
        }
    }
    m=temp;
    for(i=1;i<=n;i++)
    {
        if(c[i]<high)return false;
    }
    return true;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%lld", &n, &m);
        ll L = 0, R = m, M, ans = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            R = max(R, a[i]*m);
        }
        while(L <= R){
            M = (L + R) / 2;
            if(check(M)){
                ans = M;
                L = M + 1;
            }
            else{
                R = M - 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
