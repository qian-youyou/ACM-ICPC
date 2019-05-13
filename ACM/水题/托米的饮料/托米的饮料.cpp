#include<bits/stdc++.h>
using namespace std;
int vis[1010]={0},a[1010],b[1010];
int main(){
    int n;
    cin>>n;
    int cnt = n;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>b[i];
        vis[a[i]]++;
    }
    for(int i = 1;i<=n;i++){
        if(vis[b[i]]){
            cnt-=vis[b[i]];
            vis[b[i]]=0;
            if(a[i]==b[i]){
                cnt++;
                vis[b[i]]=1;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
