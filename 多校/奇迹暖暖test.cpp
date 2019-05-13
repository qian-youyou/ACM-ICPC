#include<bits/stdc++.h>
using namespace std;
int vis[1007][1007];
int main()
{
    srand(time(0));
    int n;
    scanf("%d",&n);
    FILE *fp = fopen("test.txt","w");
    fprintf(fp,"%d\n",n);
    //cout<<n<<' '<<m<<endl;
    memset(vis,0,sizeof(vis));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int x = rand()%100000;
            if(j)
                fprintf(fp," ");
            fprintf(fp,"%d",x);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    return 0;
}
