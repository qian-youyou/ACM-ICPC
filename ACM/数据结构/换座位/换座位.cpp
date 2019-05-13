#include<bits/stdc++.h>
using namespace std;
const int maxn = 10007;
int main(){
    int n, a[maxn];
    while(cin >> n){
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            for(int j = 0; j < i; j++){
                if(a[j] > a[i]){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
