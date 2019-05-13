#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e5+7;
int num[maxn], top, cnt, flag, cur;
int n;
void init(){
    cnt = 0;
    top = 0;
    flag = 0;
    cur = 0;
}
int Top(){
    return top?num[top - 1]:0;
}
void Push(int x){
    num[top++] = x;
    ++cnt;
}
void Pop(){
    cnt--;
    top--;
}
bool Empty(){
    return cnt?false:true;
}
int main(){
    int T, tmp;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        init();
        for(int i = 0; i < n; i++){
            scanf("%d", &tmp);
            if(cur){
                if(tmp < cur){
                    cur = tmp;
                }
                else{
                    cur = 0;
                    if(Empty()||tmp >= Top()){
                        Push(tmp);
                    }
                    else{
                        Pop();
                        cur = tmp;
                    }
                }
            }
            else{
                if(Empty()){
                    Push(tmp);
                }
                else if(tmp >= Top()){
                    Push(tmp);
                }
                else{
                    Pop();
                    cur = tmp;
                }
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < top; i++){
            printf("%d ", num[i]);
        }
        printf("\n");
    }
    return 0;
}
