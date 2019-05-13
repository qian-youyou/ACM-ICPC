#include<bits/stdc++.h>
using namespace std;

const int maxn = 1007;
const int inf = 0x3f3f3f3f; //�轫road��dis��ʼ��Ϊ������inf
int n;
int dis[maxn];  //��������㵽Դ�����̾���,dis[s]Ϊ0
int road[maxn][maxn];   //����֮��ֱ�Ӿ����ϵ
bool vis[maxn];     //�ж�Դ�㵽�õ�ľ����Ƿ�Ϊ��̾���
int dijkstra(int s, int e){
    int ans = -1;
    memset(vis, false, sizeof(vis));
    vis[s] = true;
    for(int i = 1;i <= n;i++)
        dis[i] = road[s][i];

    return ans;
}
int main(){
    cin>>n;
    memset(road,inf,sizeof(road));
    for(int i = 1;i<=n;i++)
    {
int tmp;
        int x,y;
        cin>>x>>y>>tmp;
        road[y][x]=road[x][y]=tmp;
    }
    cout<<dijkstra(1,n)<<endl;
    return 0;
}
