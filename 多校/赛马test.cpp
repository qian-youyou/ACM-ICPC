#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    for(int i = 0;i<50;i++){
        int n = rand()%1000+1;
        cout<<n<<endl;
        for(int j = 0;j<n;j++)
            cout<<rand()%500<<' ';
        cout<<endl;
        for(int j = 0;j<n;j++)
            cout<<rand()%500<<' ';
        cout<<endl;
    }
}
