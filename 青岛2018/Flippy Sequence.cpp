#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
char str1[maxn], str2[maxn];
int a[maxn];
int main(){
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        scanf("%s", str1);
        scanf("%s", str2);
        for(int i = 0; i < n; i++){
            int a1 = str1[i]-'0';
            int a2 = str2[i]-'0';
            a[i] = a1^a2;
        }
        int flag = 0;
        ll ans = 0, lcnt0 = 0, rcnt0 = 0, cnt1 = 0;
        for(int i = 0; i < n; i++){
            if(!i){
                if(a[i]){
                    flag++;
                    cnt1++;
                    continue;
                }
                else{
                    lcnt0++;
                    continue;
                }
            }
            else{
                if(a[i]==a[i-1]){
                    if(a[i]){
                        if(flag == 1){
                            cnt1++;
                        }
                    }
                    else{
                        if(flag == 1){
                            rcnt0++;
                        }
                        else if(flag == 0){
                            lcnt0++;
                        }
                    }
                }
                else{
                    if(a[i]){
                        flag++;
                        if(flag==1){
                            cnt1++;
                        }
                    }
                    else{
                        if(flag == 1){
                            rcnt0++;
                        }
                    }
                }
            }
        }
        if(flag == 0){
            ans = n*(n+1)/2;
        }
        else if(flag == 1){
            ans = (cnt1-1+rcnt0+lcnt0)*2;  //2*((cnt1 -1)+(rcnt0+lcnt0))
        }
        else if(flag == 2){
            ans = 6;
        }
        else{
            ans = 0;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
