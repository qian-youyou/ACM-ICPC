#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll x;
    ll y;
    double z;
};
int cmp(node a,node b){
    if(a.z==b.z)
        return a.y<b.y;
    return a.z>b.z;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m,nn,cnt = 0;
        vector<node>v;
        v.clear();
        cin>>n>>m;
        for(int i = 0;i < n;i++){
            ll tmp1,tmp2;
            cin>>tmp1>>tmp2;
            node ttmp;
            ttmp.x = tmp1;
            ttmp.y = tmp1+tmp2;
            ttmp.z = 1.0*ttmp.x/ttmp.y;
            v.push_back(ttmp);
        }
        sort(v.begin(),v.end(),cmp);
        vector<node>::iterator it;
        ll ccc = 1;
        ll ddd = 1;
        for(it = v.begin();it!=v.end();it++)
            cout<<(*it).z<<endl;
        for(it = v.begin();it!=v.end();it++){
            ccc*=((*it).y);
            ddd*=((*it).x);
            if(ccc-ddd+1 > m)
                break;
            else{
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
