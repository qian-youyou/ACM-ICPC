#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
char s[N], t[N], ans[N];
int main() {
    while(scanf("%s%s", s, t) != EOF) {
        int len = strlen(s);
        int cur = 0;
        int flag = 0;
        for(cur = 0; cur < len; cur++){
            if(s[cur] > t[cur]){
                flag = 1;
            }
            else if(s[cur] < t[cur]){
                flag = 2;
            }
            if(flag){
                break;
            }
        }
        if(flag){
            if(abs(s[cur] - t[cur]) > 1){
                if(flag == 1){
                    t[cur]++;
                    printf("%s\n", t);
                }
                else{
                    s[cur]++;
                    printf("%s\n", s);
                }
            }
            else{
                while(s[cur]==t[cur]){
                    cur++;
                }
                int cnt = 0;
                if(flag == 1){
                    for(int j = cur+1; j < len; j++){
                        if(s[j] != 'A'){
                            cnt++;
                        }
                    }
                    if(cnt){
                        for(int j = cur+1; j < len; j++){
                            s[j] = 'A';
                        }
                        printf("%s\n", s);
                    }
                    else{
                        for(int j = cur+1; j < len; j++){
                            t[j] = 'Z';
                        }
                        printf("%s\n", t);
                    }
                }
                else{
                    for(int j = cur+1; j < len; j++){
                        if(t[j]!='A'){
                            cnt++;
                        }
                    }
                    if(cnt){
                        for(int j = cur+1; j < len; j++){
                            t[j] = 'A';
                        }
                        printf("%s\n", t);
                    }
                    else{
                        for(int j = cur+1; j < len; j++){
                            s[j] = 'Z';
                        }
                        printf("%s\n", s);
                    }
                }
            }
        }
    }
    return 0;
}
