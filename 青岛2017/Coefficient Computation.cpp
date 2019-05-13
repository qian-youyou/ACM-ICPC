#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 307;
ll C[maxn][maxn];
void init(){
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for(int i = 1; i < maxn; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            cout<<C[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main(){
    init();
    return 0;
}
