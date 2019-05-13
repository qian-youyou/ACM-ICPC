#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int a[1005],b[1005];
int main(){
    int n;
    while(cin>>n&&n){
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        int s=0;
        for(int i=0,j=0,k=n-1,l=n-1; i<=k;){
            //如果田忌速度最慢的马比齐王速度最慢的要快，直接赢
            if(a[i]>b[j])s++,i++,j++;
            //如果田忌的速度最快的马比齐王速度最快的要快，直接赢
            else if(a[k]>b[l])s++,k--,l--;
            else{
                //用田忌速度最慢的和齐王速度最快的马比较，如果小于就直接输
                if(a[i]<b[l])s--;
                i++,l--;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
