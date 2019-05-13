#include<bits/stdc++.h>
using namespace std;
int a[107][107];
int main(){
    memset(a,0,sizeof(a));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i<m;i++){
        int x = rand()%n+1;
        int y = rand()%n+1;
        while(a[x][y]||x==y){
            x = rand()%n+1;
            y = rand()%n+1;
        }
        a[x][y] = 1;
        a[y][x] = 1;
        int w = rand()%100+1;
        int r = rand()%100+1;
        int l = rand()%10;
        while(l>=r){
            r = rand()%100+1;
            l = rand()%10;
        }
        printf("%d %d %d %d %d\n",x,y,w,l,r);
    }
    return 0;

}
