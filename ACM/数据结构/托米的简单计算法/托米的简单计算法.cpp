#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 200010;
char str[maxn*2];
ll high[maxn],wed[maxn],area[maxn],minu[maxn],mystack[maxn];
ll fun(){
    int cnt = 1,head = 1,tail = 1,len = strlen(str);
    memset(high,0,sizeof(high));
    memset(wed,0,sizeof(wed));
    memset(minu,0,sizeof(minu));
    memset(mystack,0,sizeof(mystack));
    for(int i = 0;i < len;i++){
        if(str[i] == '('){
            mystack[tail++]=cnt++;
            high[mystack[tail - 1]]++;
            wed[mystack[tail - 1]] = 1;
            if(high[mystack[tail - 2]] <= high[mystack[tail - 1]])
                high[mystack[tail - 2]] = high[mystack[tail - 1]] + 1;
        }
        else if(str[i] == ')'){
            if(tail > 1){
                if(high[mystack[tail-2]] <= high[mystack[tail-1]])
                    high[mystack[tail-2]] = high[mystack[tail-1]] + 1;
                tail--;
                wed[mystack[tail - 1]] += wed[mystack[tail]] + 1;
                area[mystack[tail]] = wed[mystack[tail]] * high[mystack[tail]] - minu[mystack[tail]];
                minu[mystack[tail - 1]] += area[mystack[tail]];
            }
        }
    }
    return minu[0];
}
int main(){
    int T;
    cin >> T;
    while(T--){
        scanf("%s",str);
        cout << fun() << endl;
    }
    return 0;
}
