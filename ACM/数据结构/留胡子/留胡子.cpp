#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int n,p,q,m;
unsigned int SA,SB,SC;
stack<int>st;
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
void gen(){
    ans = 0;
    while(!st.empty())
        st.pop();
    scanf("%d%d%d%d%u%u%u",&n, &p, &q, &m, &SA, &SB, &SC);
    for(int i = 1; i <= n;i++){
        if(rng61() % (p + q) < p){
            int tmp = rng61() % m + 1;
            if(st.empty())
                st.push(tmp);
            else
                st.push(max(st.top(),tmp));
            ans^=i*st.top();
        }
        else{
            if(!st.empty()){
                st.pop();
                if(!st.empty())
                    ans^=i*st.top();
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        gen();
        cout<<ans<<endl;
    }
    return 0;
}
