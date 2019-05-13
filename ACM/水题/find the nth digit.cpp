#include<stdio.h>
int main(){
    int n, T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; n - i > 0; i++){
            n-=i;
        }
        printf("%d\n", n%9?n%9:9);
    }
    return 0;
}
