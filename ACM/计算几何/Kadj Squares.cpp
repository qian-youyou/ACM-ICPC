#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 55;
const int inf = 0x3f3f3f3f;
int n;
struct NODE{
    int la, ra, len;
}node[maxn];
int main(){
    while(~scanf("%d", &n)&&n){
        scanf("%d", &node[0].len);
        node[0].la = 0;
        node[0].ra = 2 * node[0].len;
        for(int i = 1; i < n; i++){
            node[i].la = -inf;
            scanf("%d", &node[i].len);
            for(int j = 0; j < i; j++){
                node[i].la = max(node[i].la, node[j].ra - abs(node[i].len - node[j].len));
            }
            node[i].ra = node[i].la + 2 * node[i].len;
            for(int j = 0; j < i; j++){
                if(node[j].len>node[i].len){
                    node[i].la = max(node[i].la, node[j].ra);
                }
                else if(node[j].len < node[i].len){
                    node[j].ra = min(node[i].la, node[j].ra);
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(node[i].la<node[i].ra){
                printf("%d ", i+1);
            }
        }
        printf("\n");
    }
    return 0;
}
