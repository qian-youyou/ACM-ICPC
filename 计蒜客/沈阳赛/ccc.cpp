#include<iostream>
#include<cstdio>
using namespace std;
int pri[19] = {2,3,5,7,11,13,17,23,31,37,53,71,73,113,131,137,173,311,317};
int read()
{
    char ch=' ';
    int ans=0;
    while(ch<'0' || ch>'9')
        ch=getchar();
    while(ch<='9' && ch>='0')
    {
        if(ans<100000)
        ans=ans*10+ch-'0';
        ch=getchar();
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int aaa=1;aaa<=t;aaa++){
        int ans = read();
        int i;

        for(i = 0;i<19;i++){
            if(pri[i]>ans){
                cout<<"Case #"<<aaa<<": "<<pri[i-1]<<endl;
                break;
            }
        }
        if(i==19)
            cout<<"Case #"<<aaa<<": "<<pri[18]<<endl;
    }
    return 0;
}
