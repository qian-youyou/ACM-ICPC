#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    int a[3];
    a[1] =a[2]=100;
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            int tmp = rand()%10;
            while((tmp==1||tmp==2)){
                if(a[tmp]>0)
                    break;
                tmp = rand()%10;
            }
            if(tmp==1)
                printf("@");
            else if(tmp==2)
                printf("#");
            else
                printf("*");
            a[tmp]--;
        }
        printf("\n");
    }
    if(a[1]||a[2])
        printf("cuo\n");
    return 0;
}
