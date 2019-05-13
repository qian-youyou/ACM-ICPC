#include<bits/stdc++.h>
using namespace std;
const int maxn = 1007;
int n,m;
struct Edge
{
    int x;
    int y;
    int l;
} edge[maxn];
int fa[maxn];
int init()
{
    for(int i = 0; i<maxn; i++)
        fa[i] = i;
}
int findfa(int x)
{
    return fa[x] == x ? x : (fa[x] = findfa(fa[x]));
}

int merge_1(int x,int y)
{
    fa[findfa(x)] = findfa(y);
}
int kruskal()
{
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i< m; i++)
    {
        int fx = findfa(edge[i].x);
        int fy = findfa(edge[i].y);
        if(fx!=fy)
        {
            merge_1(fx,fy);
            cnt++;
            sum+=edge[i].l;
            if(cnt>=n-1)
                break;
        }
    }
    return sum;
}
int cmp(Edge x,Edge y)
{
    return x.l>y.l;
}
int main()
{
    int aa[maxn],bb[maxn];
    init();
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        cin>>aa[i]>>bb[i];
    }
    m = 0;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<i; j++)
        {
            edge[m].x = i;
            edge[m].y = j;
            edge[m].l = aa[i]*bb[j]+bb[i]*aa[j];
            m++;
        }
    }
    sort(edge,edge+m,cmp);
    //for(int i = 1; i<=m; i++)
        //cout<<edge[i].x<<' '<<edge[i].y<<' '<<edge[i].l<<endl;
    cout<<kruskal()<<endl;
    return 0;
}
