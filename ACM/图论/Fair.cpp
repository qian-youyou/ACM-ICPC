#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n,m,k,s;
int _type[maxn];
bool vis[maxn], vi[maxn];
struct note{
    int value;
    int num;
};
vector< vector<int> >v;
int bfs(int now){
    memset(vis,false,sizeof(vis));
    memset(vi,false,sizeof(vis));
    int cnt = 0,ans = 0;
    queue<note>que;
    note tmp;
    tmp.num = now;
    tmp.value = 0;
    que.push(tmp);
    vi[now]=true;
    while(!que.empty()){
        note cur = que.front();
        que.pop();
        if(!vis[_type[cur.num]]){
            vis[_type[cur.num]] = true;
            ans+=cur.value;
            cnt++;
        }
        if(cnt>=s)
            return ans;
        for(vector<int>::iterator it = v[cur.num].begin();it!=v[cur.num].end();it++){
            if(!vi[*it]){
                note tmp = cur;
                tmp.num = *it;
                tmp.value++;
                que.push(tmp);
                vi[*it]=true;
            }
        }
    }
    return ans;
}
int main(){
    while(cin>>n>>m>>k>>s){
        v.resize(n+1);
        for(int i = 1;i <= n; i++){
            cin>>_type[i];
        }
        for(int i = 0;i < m;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(int i = 1;i<n;i++)
            cout<<bfs(i)<<" ";
        cout<<bfs(n)<<endl;
    }
    return 0;
}
