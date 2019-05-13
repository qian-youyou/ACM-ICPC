#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll m,n;
    int t;
    cin >> t;
    while(t--){
        cin>>m>>n;
        if(m*m>2*n*n){
            cout<<"1"<<endl;
        }
        else
            cout<<"2"<<endl;
    }
    return 0;
}
