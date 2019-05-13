#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000007;
int minu[maxn],bi[maxn],n,m;
int main(){
    int ca;
    cin>>ca;
    for(int t = 1;t<=ca;t++){
        int maxx = -1;
        memset(minu,0,sizeof(minu));
        cin>>n>>m;
        for(int i = 0;i<n;i++){
            int a,b;
            cin>>a>>b;
            minu[a]++;
            minu[b+1]--;
            maxx=max(maxx,b+1);
        }
        bi[0]=0;
        for(int i = 1;i<=maxx;i++){
            bi[i]=bi[i-1]+minu[i];
        }
        cout<<"Case #"<<t<<":\n";
        for(int i = 0;i<m;i++){
            int tmp;
            cin>>tmp;
            cout<<bi[tmp]<<endl;
        }
    }
    return 0;
}
