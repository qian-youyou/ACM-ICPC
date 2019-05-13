#include<bits/stdc++.h>
using namespace std;
struct Arc{
    int point;
    int next;
    Arc(int x = -1, int y = -1):point(x),next(y) {}
};

Arc arc[50005];
int node[5005];
int digree[5005];
int top[5005];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    priority_queue<int, vector<int>, greater<int> >q;
    for(int i=1; i<=m; i++){
        int a,b;
        scanf("%d%d",&a,&b);

        arc[i].next=node[a];
        arc[i].point=b;
        node[a]=i;
        digree[b]++;
    }
    for(int i=1; i<=n; i++){
        if(digree[i]==0){
            q.push(i);
        }
    }
    int l=0;
    while(!q.empty()){
        int x=q.top();
        top[l++]=x;//�� x ���뵽��������
        q.pop();
        for(int e=node[x]; e!=-1; e=arc[e].next){
            digree[arc[e].point]--;
            if(digree[arc[e].point]==0){
                q.push(arc[e].point);
            }
        }
    }
    for(int i = 0; i<n - 1; i++)
        cout<<top[i]<<' ';
    cout << top[n-1] << endl;
    return 0;
}






#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int maxn=510;
int graph[maxn][maxn];//����ͼ
int degree[maxn];//�������

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(graph,0,sizeof(graph));
        memset(degree,0,sizeof(degree));
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(!graph[u][v])
            {
                graph[u][v]=1;
                degree[v]++;/�����++
            }
        }
        priority_queue<int,vector<int>,greater<int> >q;
        for(int i=1;i<=n;i++)
            if(degree[i]==0)
            q.push(i);
        bool first=1;
        while(!q.empty())
        {
            int cur=q.top();
            q.pop();
            if(first)
            {
                cout<<cur;
                first=0;
            }
            else
                cout<<" "<<cur;
            for(int i=1;i<=n;i++)
            {
                if(graph[cur][i])
                {
                    degree[i]--;//�����ĵ����ȼ�1
                    if(degree[i]==0)//�������Ϊ0�����Ӷ���
                        q.push(i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
