#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct NODE{
    string str;
    int d;
    int c;
}node[20];
struct DP{
    int pre;
    int sc;
    int tim;
    int id;
}dp[1<<16];
int n;
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> node[i].str >> node[i].d >> node[i].c;
        }
        for(int i = 1; i < 1<<n; i++){
            dp[i].sc = inf;
            for(int j = 0; j < n; j++){
                if(i&(1<<j)){
                    int pre = i - (1<<j);
                    int sc = dp[pre].tim + (node[j].c - node[j].d);
                    if(sc < 0){
                        sc = 0;
                    }
                    if(sc+dp[pre].sc <= dp[i].sc){
                        dp[i].pre = pre;
                        dp[i].sc = sc + dp[pre].sc;
                        dp[i].id = j;
                        dp[i].tim = dp[pre].tim + node[j].c;
                    }
                }
            }
        }
        cout << dp[(1<<n)-1].sc <<endl;
        int ans[20], num = 0, cnt = (1<<n)-1;
        while(cnt){
            ans[num++] = dp[cnt].id;
            cnt = dp[cnt].pre;
        }
        for(int i = num-1; i >= 0; i --){
            cout<< node[ans[i]].str <<endl;
        }
    }
    return 0;
}
