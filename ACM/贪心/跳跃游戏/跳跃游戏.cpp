#include<bits/stdc++.h>
using namespace std;
int n,a[510],vis[510], b[2] = {1,-1};
bool bfs(int x){
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int cur = q.front();
        if(cur==n-1)
            return true;
        q.pop();
        vis[cur]=1;
        for(int i = 0;i<2;i++){
            int cc = cur+a[cur]*b[i];
            if(cc>=0&&cc<n&&!vis[cc]){
                q.push(cc);
                vis[cc]=1;
            }
        }
    }
    return false;
}
int main(){
    cin>>n;
    memset(vis,0,sizeof(vis));
    for(int i = 0;i<n;i++)
        cin>>a[i];
    if(bfs(0))
        cout<< "true" << endl;
    else
        cout<<"false" << endl;
    return 0;
}
