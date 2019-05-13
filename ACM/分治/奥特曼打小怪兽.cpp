#include<bits/stdc++.h>
using namespace std;
const int maxn = 50007;
int n,k;
int a[10],b[10],vis[10];
int main(){
    cin>>n>>k;
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < n;i++)
        cin>>a[i]>>b[i];
    for(int t = 0;flag;t++){
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                int hurt = a[i]+b[i]*t;

            }
        }
    }
    return 0;
}
