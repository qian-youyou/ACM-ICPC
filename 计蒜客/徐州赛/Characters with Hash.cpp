#include<bits/stdc++.h>
using namespace std;
char str[1000007],ch[2];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%s%s",&n,ch,str);
        int ans = 2*n;
        for(int i = 0; i<n; i++){
            if(str[i]==ch[0])
                ans-=2;
            else{
                if(abs(str[i]-ch[0])<10)
                    ans-=1;
                break;
            }
        }
        if(ans==0)
            ans++;
        printf("%d\n",ans);
    }
    return 0;
}
