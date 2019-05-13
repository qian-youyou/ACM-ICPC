#include<stdio.h>
int main(){
    int n = 0x11223344;
    char *p1 = (char *)&n;
    int *p2 = &n;
    *p1 = 0x55;
    *p2 = 0;
    printf("%s",p1);
    printf("%d",*p2);
    return 0;
}
