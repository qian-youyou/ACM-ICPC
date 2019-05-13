#include<bits/stdc++.h>
using namespace std;
double a[3]={1,-2,0.5};
int ans = 0,n;
double aa[1000];
void dfs(int cus,double res){
    aa[cus]=res;
    if(cus==n){
        if(res==1){
            ans++;
            for(int i = 1;i<=cus;i++){
                printf("%lf ",aa[i]);
            }
            cout<<endl;
            return;
        }
        else{
            return;
        }
    }
    for(int i = 0;i<3;i++){
        double aaa=res;
        aaa*=a[i];
        dfs(cus+1,aaa);
    }
}
int main(){
    while(cin>>n){
        ans=0;
        dfs(1,1);
        cout<<ans<<endl;
    }
    return 0;
}
