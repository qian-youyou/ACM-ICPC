#include<bits/stdc++.h>
using namespace std;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string str[13]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
int fun(int y,int m,int d){
    int cnt = 0;
    if(y)
        cnt += y*365 + (y-1)/4 + 1;
    for(int i = 1;i < m;i++){
        cnt+=mon[i];
    }
    if(y%4==0&&m>2){
        cnt++;
    }
    cnt += d;
    return cnt;
}
bool check(int y,int m,int d){
    if(m&&(m<=12)){
        if(d&&(d<=((y%4==0&&m==2)?29:mon[m])))
            return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        scanf("%02d/%02d/%02d",&a,&b,&c);
        if(check(a,b,c)){
            if(check(c,a,b)){
                fun(a,b,c)-fun(c,a,b)!=0?cout<<abs(fun(a,b,c)-fun(c,a,b))<<endl:cout<<str[b]<<" "<<c<<", "<<a+2000<<endl;
            }
            else
                cout<<str[b]<<" "<<c<<", "<<a+2000<<endl;
        }
        else
            cout<<str[a]<<" "<<b<<", "<<c+2000<<endl;
    }
    return 0;
}
