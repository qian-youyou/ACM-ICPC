#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    int cnt=0;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        for(int j = 0;j<i;j++){
            if(a[j]>a[i]){
                cnt++;
                cnt%=2;
            }
        }
    }
    if(cnt==1)
        cout<<"Petr"<<endl;
    else
        cout<<"Permutations"<<endl;
    return 0;
}
