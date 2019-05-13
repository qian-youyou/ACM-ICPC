#include<stdio.h>
using namespace std;
const int maxn=100;
char mp[105][105];
int dis[105][105];
int cnt1=0,cnt2=0;
int F[110];
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    int i,j;
    for(i=0; i<=x; i++)
        for(j=0; j<=x; j++)
        {
            scanf("%c",&mp[i][j]);
            if(mp[i][j]=='.')
                dis[i][j]==1;
            if(mp[i][j]=='W')
                dis[i][j]==0;
            cnt1++;
        }                               //输入，转化 '.'=1；'w'=0
    int a,b;
    for(a=0; a<x; a++)
        for(b=0; b<y; b++)
        {
            if(dis[a][b]!=1&&dis[a-1][b-1]!=1)
                dis[a-1][b-1]=dis[a][b]-11;

            if(dis[a][b]!=1&&dis[a-1][b]!=1)
                dis[a-1][b]=dis[a][b]-1;

            if(dis[a][b]!=1&&dis[a-1][b+1]!=1)
                dis[a-1][b+1]=dis[a][b]-1;


            if(dis[a][b]!=1&&dis[a][b-1]!=1)
                dis[a][b-1]=dis[a][b]-1;


            if(dis[a][b]!=1&&dis[a][b+1]!=1)
                dis[a][b+1]=dis[a][b]-1;

            if(dis[a][b]!=1&&dis[a+1][b-1]!=1)
                dis[a+1][b-1]=dis[a][b]-1;

            if(dis[a][b]!=1&&dis[a+1][b]!=1)
                dis[a+1][b]=dis[a][b]-1;

            if(dis[a][b]!=1&&dis[a+1][b+1]!=1)
                dis[a+1][b+1]=dis[a][b]-1;
            dis[a][b]=1;
        }//将每个区域W集中
    int c,d,i1,s=0;
    for(c=0; c<x; c++)
        for(d=0; d<y; d++)
        {
            if(dis[c][d]<0)
                for(i1=0; i1<110; i1++)
                    s=-(dis[c][c])+s;
        }

    int yy;
    yy=cnt1-s;
    scanf("%d",yy);
    return 0;
}
