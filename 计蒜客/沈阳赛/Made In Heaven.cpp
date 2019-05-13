#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long
const ll maxn=100010;
ll n,m,dis[maxn];
ll tot,head1[maxn],head2[maxn];
bool flag[maxn];
struct edge
{
    ll to;
    ll w;
    ll next;
}e[maxn*2],e2[maxn*2];
struct node
{
    ll f;
    ll g;
    ll from;
    bool operator < (node a)const
    {
        if(a.f==f)
        return g>a.g;
        return f>a.f;
    }
};
void add_edge(ll u,ll v,ll w)
{
    tot++;
    e[tot].to=v;
    e[tot].w=w;
    e[tot].next=head1[u];
    head1[u]=tot;
    e2[tot].to=u;
    e2[tot].w=w;
    e2[tot].next=head2[v];
    head2[v]=tot;
}
void prepare()
{
    for(ll i=1;i<=n;i++)
    dis[i]=maxn;tot=0;
    memset(head1,0,sizeof(head1));
    memset(head2,0,sizeof(head2));
}
void spfa(ll t)
{
    for(ll i=1;i<=n;i++)
    dis[i]=maxn;
    dis[t]=0;
    queue<ll> q;
    q.push(t);
    flag[t]=1;
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();flag[v]=0;
        for(ll i=head2[v];i;i=e2[i].next)
        if(dis[e2[i].to]>dis[v]+e2[i].w)
        {
            dis[e2[i].to]=dis[v]+e2[i].w;
            if(!flag[e2[i].to])
            {
                q.push(e2[i].to);
                flag[e2[i].to]=1;
            }
        }
    }
}
ll a_star(ll s,ll t,ll k)
{
    if(s==t) k++;
    if(dis[s]==maxn) return -1;
    priority_queue<node> q;
    ll cnt=0;
    node tmp,to;
    tmp.from=s;
    tmp.g=0;
    tmp.f=tmp.g+dis[tmp.from];
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        if(tmp.from==t) cnt++;
        if(cnt==k) return tmp.g;
        for(ll i=head1[tmp.from];i;i=e[i].next)
        {
            to.from=e[i].to;
            to.g=tmp.g+e[i].w;
            to.f=to.g+dis[to.from];
            q.push(to);
        }
    }
    return -1;
}
int main()
{
    ll x,y,z,s,t,k;
    ll T;
    while(cin>>n>>m)
    {
        cin>>s>>t>>k>>T;
        prepare();
        for(ll i=1;i<=m;i++)
        {
            cin>>x>>y>>z;
            add_edge(x,y,z);
        }
        spfa(t);
        ll ans=a_star(s,t,k);
        if(ans<=T&&ans!=-1)
            cout<<"yareyaredawa"<<endl;
        else
            cout<<"Whitesnake!"<<endl;
    }
    return 0;
}
