#include<bits/stdc++.h>
using namespace std;
int tmp, n;
int main(){
    while(~scanf("%d", &n)){
        set<int>s;
        for(int i = 0; i < n; i++){
            scanf("%d", &tmp);
            set<int>::iterator it = s.lower_bound(tmp);
            if(it!=s.end()){
                s.erase(it);
            }
            s.insert(tmp);
        }
        printf("%d\n", s.size());
    }
    return 0;
}
