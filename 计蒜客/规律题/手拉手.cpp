#include<bits/stdc++.h>
using namespace std;
#define ld long double
const int maxn = 1e7+7;
ld a[maxn];
void init(){
    a[0] = 0;
    a[1]=1;
    for(int i = 2;i<maxn;i++){
        a[i]=a[i-1]+1.0/(2*i-1);
    }
}
int main(){
    //freopen("head.in","r",stdin);
    //freopen("head.out","w",stdout);
    long long tmp;
    init();
    cin>>tmp;
    if(tmp*1.0>=maxn)
        cout<<log(2*tmp-1) - log(((2*tmp-1)-1)/2)/ 2 + 0.57721566490153286060651209 / 2<<endl;
    else
        cout<<a[tmp]<<endl;
    return 0;
}
