#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+9;
const int inf = 0x3f3f3f3f; //�轫road��dis��ʼ��Ϊ������inf
int n,m,k,s;

int pre[maxn];//��¼����õ����һ���������
int dis[maxn];  //��������㵽Դ�����̾���,dis[s]Ϊ0
int road[maxn][maxn];  //����֮��ֱ�Ӿ����ϵ
bool vis[maxn];     //�ж�Դ�㵽�õ�ľ����Ƿ�Ϊ��̾���

void dijkstra(int s,int e)
{//sΪ��㣬eΪ�յ�
    memset(vis, false, sizeof(vis));//����Ƿ�������·��
    vis[s] = true;//�����㵽��һ�����С�����Ѿ����
    for(int i = 1; i <= n; i++){
        dis[i] = road[s][i];//��ʼ����㵽ÿһ����ľ���
        pre[i]=s;//��ʼ��·����ÿ�������һ����Ϊ���
    }
    dis[s] = 0;
    for(int u = 1; u<n; u++)
    {
        int minD = inf,k = -1;
        for(int i = 1; i<= n; i++)
        {   //Ѱ��û�з��ʹ������·
            if(!vis[i]&&dis[i]<minD)
            {
                k = i;//��¼�±�
                minD = dis[i];//��¼��Сֵ
            }
        }
        if(k==-1)    break;
        vis[k] = true;//����Ѿ����ʹ�
        //�ɳڲ���
        for(int i = 1; i<= n; i++)
        {
            if(!vis[i]&&dis[k]+road[k][i]<dis[i])
            {
                dis[i]=dis[k]+road[k][i];
                pre[i]=k;
            }//if
        }//for
    }
}
void print(int cur)
{
    if(cur==1){
        printf("1");
        return;
    }
    print(pre[cur]);
    printf(" %d",cur);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(road,inf,sizeof(road));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=m;i++)
        {
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            road[a][b]=min(d,road[a][b]);
            //�����fans[i],�յ���S
        }
        dis[1]=0;//���
        dijkstra(1,n);
            //if(dis[n]==inf)    printf("-1");
            //else   {
                for(int i=1;i<=n;i++)
                    printf("dis=%d\n%d:%d\n",dis[i],i,pre[i]);
                print(n);
            //}
            printf("\n");
        }
    return 0;
}
