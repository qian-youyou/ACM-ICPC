#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 100010;
int m,n;
ll a[maxn],b[maxn],ans;
ll book(ll x){
    ll res = abs(x);
    for(int i = 0;i<m;i++){
        res += abs(a[i]+x);
    }
    for(int i = 0;i<n;i++){
        res += abs(b[i]-x);
    }
    return res;
}
int main(){
    cin >> m >> n;
    ans = 0;
    for(int i = 0;i < m;i++){
        cin>>a[i];
        ans += abs(a[i]);
    }
    for(int i = 0;i<n;i++){
        cin>>b[i];
        ans += abs(b[i]);
    }
    ll l = -1e9, r = 1e9;
    while(l <= r){
        ll mid = (l + r) / 2;
        ll res1 = book(mid);
        ll res2 = book(mid + 1);
        if(res1 < ans)
            ans = res1;
        if(res2 < ans)
            ans = res2;
        if(res1 <= res2)
            r = mid - 1;
        else if(res1 > res2)
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
