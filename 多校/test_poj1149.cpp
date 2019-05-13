#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    int n,m;
    int sum = 0;
    scanf("%d%d",&m,&n);
    for(int i = 0;i<m;i++){
        int tmp = rand()%1000;
        sum += tmp;
        cout<<tmp<<' ';
    }
    cout<<endl;
    for(int i = 0;i<n;i++){
        int tmp = rand()%(m+1);
        cout<<tmp;
        set<int>s;
        for(;s.size()<tmp;){
            s.insert(rand()%m+1);
        }
        for(set<int>::iterator it = s.begin();it!=s.end();it++)
            cout<<' '<<*it;
        int ccc = rand()%(sum/2+1);
        cout<<' '<<ccc<<endl;
        sum-=ccc;
    }
    return 0;
}
