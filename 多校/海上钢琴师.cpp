#include<bits/stdc++.h>
using namespace std;
int vis[1007][1007];
int main()
{
    srand(time(0));
    int n,m,c;
    cin>>m>>n;
    FILE *fp = fopen("test.txt","w");
    fprintf(fp,"%d %d\n",m,n);
    //cout<<n<<' '<<m<<endl;
    memset(vis,0,sizeof(vis));
    for(int i = 0; i<m; i++)
    {
        int x= rand()%n+1;
        int y = rand()%n+1;
        c = rand()%2000;
        while(vis[x][y]||x==y)
        {
            x= rand()%n+1;
            y = rand()%n+1;
        }
        vis[x][y]=vis[y][x]=1;
        fprintf(fp,"%d %d %d\n",x,y,c);
        //cout<<x<<' '<<y<<' '<<c<<endl;
    }
    fclose(fp);
    return 0;
}
