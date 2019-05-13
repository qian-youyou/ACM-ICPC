#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int T, n;
    int sum, a, b;
    scanf("%d", &T);
    while(T--){
        sum = 0;
        scanf("%d", &n);
        for(int i = 0; i< n; i++){
            scanf("%d%d", &a, &b);
            sum+=a*b;
        }
        printf("%d\n", sum);
    }
    return 0;
}
