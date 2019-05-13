#include<iostream>
#include<cstdio>
using namespace std;
int T;
int main(){
    scanf("%d", &T);
    while(T--){
        char ch[5][5];
        char win = '.';
        for(int i = 0; i < 3; i++){
            scanf("%s", ch[i]);
        }
        for(int i = 0; i < 3; i++){
            if(ch[i][0]!='.'&&ch[i][0] == ch[i][1]&&ch[i][1] == ch[i][2]){
                win = ch[i][0];
            }
            if(ch[0][i]!='.'&&ch[0][i] == ch[1][i]&&ch[1][i] == ch[2][i]){
                win = ch[0][i];
            }
        }
        if(ch[0][0]!='.'&&ch[0][0]==ch[1][1]&&ch[1][1]==ch[2][2]){
            win = ch[0][0];
        }
        if(ch[2][0]!='.'&&ch[2][0] == ch[1][1]&&ch[1][1] == ch[0][2]){
            win = ch[0][2];
        }
        if(win=='C'||win=='T'||win=='Z'){
            printf("%c\n", win);
        }
        else{
            printf("ongoing\n");
        }
    }

    return 0;
}
