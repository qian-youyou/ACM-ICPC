#include<bits/stdc++.h>
#define ll long long
using namespace std;
int m,n;
int a[100010], cnt;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int t,x,y;
    cnt=0;
    while(m--){
        cin>>t;
        if(t==3){
            cin>>x;
            cout<<a[x]+cnt<<endl;
        }
        else if(t==2){
            cin>>x;
            cnt+=x;
        }
        else if(t==1){
            cin>>x>>y;
            a[x]=y;
            a[x]-=cnt;
        }
    }
    return 0;
}
