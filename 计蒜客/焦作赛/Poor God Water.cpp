#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
struct matrix{
    ll a[10][10];
};
matrix matrix_mutiply(matrix a, matrix b){
    matrix tmp;
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            tmp.a[i][j] = 0;
            for(int k = 0;k<10;k++){
                tmp.a[i][j] += a.a[i][k] * b.a[k][j];
                tmp.a[i][j]%=mod;
            }
        }
    }
    return tmp;
}
matrix quick_pow(ll n){
    matrix ans,res;
    memset(ans.a,0,sizeof(ans));
    memset(res.a,0,sizeof(res));
    for(int i = 0;i<10;i++){
        ans.a[i][i] = 1;
    }
    res.a[5][0]=res.a[7][0]=1;
    res.a[3][1]=res.a[5][1]=res.a[7][1]=1;
    res.a[4][2]=res.a[6][2]=1;
    res.a[0][3]=res.a[6][3]=1;
    res.a[1][4]=res.a[8][4]=1;
    res.a[1][5]=res.a[2][5]=res.a[7][5]=1;
    res.a[0][6]=res.a[4][6]=1;
    res.a[3][7]=res.a[5][7]=1;
    res.a[1][8]=res.a[2][8]=1;
    while(n){
        if(n&1)
            ans = matrix_mutiply(ans,res);
        n>>=1;
        res = matrix_mutiply(res,res);
    }
    return ans;
}
int main(){
    int t;
    ll n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        if(n==1){
            printf("3\n");
            continue;
        }
        ll pos = 0;
        matrix ans=quick_pow(n-2);
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                pos=(pos+ans.a[i][j])%mod;
        printf("%lld\n",pos);
    }
    return 0;
}
