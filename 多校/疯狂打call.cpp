#include<bits/stdc++.h>
using namespace std;
int n, m;
int vis[60];
vector<vector<int> >v;
int dfs(int now){
    vis[now] = 1;
    if(now == n)
        return 1;
    for(vector<int>::iterator it = v[now].begin(); it != v[now].end(); it++){
        int tmp = *it;
        if(!vis[tmp]){
            vis[tmp] = 1;
            if(dfs(tmp))
                return 1;
        }
    }
    return 0;
}
int main(){
    while(cin >> n >> m){
        v.clear();
        v.resize(n + 1);
        for(int i = 1; i <= m; i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }
        memset(vis, 0 ,sizeof(vis));
        if(dfs(1))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
