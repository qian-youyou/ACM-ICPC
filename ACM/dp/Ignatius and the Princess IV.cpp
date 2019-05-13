#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(~scanf("%d", &n)){
        map<int, int>p;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int tmp;
            scanf("%d", &tmp);
            p[tmp]++;
            if(p[tmp]>n/2){
                ans = tmp;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
