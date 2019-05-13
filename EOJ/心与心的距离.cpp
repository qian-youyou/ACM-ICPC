#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        int dis;
        scanf("%d", &dis);
        printf("Case #%d: %d %d %d %d %d %d\n", cas, dis, 0, dis^1, 1, 1, 1);
    }
    return 0;
}
