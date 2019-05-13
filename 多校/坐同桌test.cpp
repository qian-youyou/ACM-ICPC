#include<bits/stdc++.h>
using namespace std;
int vis[1007][1007];
int main()
{
    srand(time(0));
    int n,m,e,c;
    scanf("%d%d%d",&n,&m,&e);
    FILE *fp = fopen("test.txt","w");
    fprintf(fp,"%d %d %d\n",n,m,e);
    //cout<<n<<' '<<m<<endl;
    memset(vis,0,sizeof(vis));
    for(int i = 0; i<e; i++)
    {
        int x= rand()%n+1;
        int y = rand()%m+1;
        while(vis[x][y]||x==y)
        {
            x= rand()%n+1;
            y = rand()%m+1;
        }
        vis[x][y]=1;
        fprintf(fp,"%d %d\n",x,y);
        //cout<<x<<' '<<y<<' '<<c<<endl;
    }
    fclose(fp);
    return 0;
}
