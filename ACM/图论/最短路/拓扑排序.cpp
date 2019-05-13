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
    queue<int>q;
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
        int x=q.front();
        top[l++]=x;//将 x 加入到拓扑序中
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
