#include<bits/stdc++.h>
using namespace std;
const int maxn = 500;
int t, c, d, n, cyc, cnt;
int a[maxn], vis[maxn];
int init(){
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    a[1] = c;
    a[2] = d;
    cnt = 2;
    while(!vis[a[cnt-1]*10+a[cnt-0]]){
        vis[a[cnt-1]*10+a[cnt]] = cnt;
        int tmp = a[cnt-1] + a[cnt];
        if(tmp<10)
            a[++cnt]=tmp;
        else{
            a[++cnt]=tmp/10;
            a[++cnt]=tmp%10;
        }
    }
    return vis[a[cnt-1]*10+a[cnt]];
}
int main(){
    cin>>t;
    for(int i = 1;i<=t;i++){
        cin >> c >> d >> n;
        int res = init();
        cout<<"Case #"<<i<<": ";
        if(cnt>=n)
            cout<<a[n]<<endl;
        else
            cout<<a[res+(n-res)%(cnt-res)]<<endl;
    }
    return 0;
}
