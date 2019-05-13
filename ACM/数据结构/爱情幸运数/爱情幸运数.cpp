#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int fort = 1314;
ll coeff[6];
int cmp(ll a,ll b){
    return a > b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>coeff[0]>>coeff[1]>>coeff[2];
        coeff[3] = 5;
        coeff[4] = 2;
        coeff[5] = 0;
        sort(coeff,  coeff + 6, cmp);
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        set<ll>s;
        set<ll>ans;
        pq.push(1);
        s.insert(1);
        for(int i = 0;;i++){
            ll x = pq.top();
            pq.pop();
            if(i){
                for(int k = 3;k < 6;k++){
                    ans.insert(x - coeff[k]);
                    if(ans.size()==fort)
                        break;
                }
                if(ans.size()==fort){
                    /*int ttt = 1;
                    for(set<ll>::iterator it = ans.begin();it!=ans.end();it++)
                        cout<<ttt++<<' '<<*it<<endl;*/
                    set<ll>::reverse_iterator it = ans.rbegin();
                    cout<<*it<<endl;
                    break;
                }
            }
            for(int j = 0;j<3;j++){
                ll x2=x*coeff[j];
                if(!s.count(x2)){
                    s.insert(x2);
                    pq.push(x2);
                }
            }
        }
    }
    return 0;
}
