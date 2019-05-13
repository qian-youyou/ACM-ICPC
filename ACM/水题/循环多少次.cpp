#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define mod 1007
int C[2050][2050];
void init()
{
    for(int i=1;i<=2000;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
}
int main()
{
    int T,n,m;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&m,&n);
        printf("%d\n",C[n][m]);
    }
    return 0;
}
