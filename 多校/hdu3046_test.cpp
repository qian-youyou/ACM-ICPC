#include<bits/stdc++.h>
using namespace std;
int fun(){
    int a = rand()%3-rand()%3;
    if(a<0)1001
        return 0;
    return a;
}
int main(){
    int n,m;
    srand(time(0));
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<rand()%3<<' ';
        }
        cout<<endl;
    }
    return 0;
}
