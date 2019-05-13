#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int c = n % 50;
        n /= 50;
        if(n > 5|| n == 3 || n==4){
            cout<<c<<endl;
        }
        else{
            if(n<3){
                cout<<n*50+c<<endl;
            }
            else{
                cout<<50+c<<endl;
            }
        }
    }
    return 0;
}
