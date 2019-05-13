#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxx = 1e9+7;
char str[1007];
int a[26];
int main(){
    int t;
    scanf("%d",&t);
    for(int cc = 1;cc<=t;cc++){
        scanf("%s",&str);
        int minD = maxx;
        memset(a,0,sizeof(a));
        int len = strlen(str);
        for(int i = 0;i<len;i++){
            int num = str[i]-'a';
            if(a[num])
                minD = min(minD,i - a[num] + 1);
            a[num] = i + 1;
        }
        if(minD == maxx)
            printf("Case #%d: -1\n",cc);
        else
            printf("Case #%d: %d\n",cc,minD);
    }
    return 0;
}
