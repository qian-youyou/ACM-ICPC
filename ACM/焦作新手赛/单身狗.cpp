#include<bits/stdc++.h>
using namespace std;
int n, tmp, ans, flag;
void init(){
    ans = 0;
    flag = -1;
}
int read(){
    if(flag==-1){
        scanf("%d",&flag);
        return 1;
    }
    else
        scanf("%d",&tmp);
    return 0;
}
int main(){
    while(~scanf("%d",&n)){
        init();
        for(int i = 0; i<n; i++){
            if(!read()){
                if((tmp+flag)&1){
                    ++ans;
                    flag = -1;
                }
                else{
                    flag = tmp;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
