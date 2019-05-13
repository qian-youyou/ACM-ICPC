#include<bits/stdc++.h>
using namespace std;
int n, x;
int main(){
    cin>>n>>x;
    int cnt = 0, res = 1, re = 1;
    int tmp = n;
    if(x){
        while(tmp){
            int mod = tmp%10;
            cnt+=(res-re)/10*mod;
            if(mod>x)
                cnt+=re;
            else if(mod==x)
                cnt+=n%re+1;
            re*=10;
            res*=10;
            res+=re;
            tmp/=10;
        }
    }
    else{
        for(int i = 1;i<=n;i++)
            for(int j=i;j;j/=10)
                if(j%10==x)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
