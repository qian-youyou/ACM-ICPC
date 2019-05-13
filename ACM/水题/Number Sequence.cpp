#include<stdio.h>
int A, B, n;
const int mod = 7;
typedef struct{
    int a[2][2];
}matrix;
matrix multiply(matrix a1, matrix a2){
    matrix a3 = {0, 0, 0, 0};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                a3.a[i][j] += a1.a[i][k] * a2.a[k][j];
                a3.a[i][j] %= mod;
            }
        }
    }
    return a3;
}
matrix quick_pow(){
    matrix res = {A%mod, B%mod, 1, 0};
    matrix ans = {1, 0, 0, 1};
    while(n){
        if(n&1){
            ans = multiply(ans, res);
        }
        res = multiply(res, res);
        n >>= 1;
    }
    return ans;
}
int main(){
    while(~scanf("%d%d%d", &A, &B, &n) && A+B+n){
        if(n<3){
            printf("1\n");
            continue;
        }
        n-=2;
        matrix ans = quick_pow();
        matrix res = {1, 0, 1, 0};
        ans = multiply(ans, res);
        printf("%d\n", ans.a[0][0]);
    }
    return 0;
}
