#include<bits/stdc++.h>
using namespace std;
const int maxn = 10007;
int n, hei, wei;
struct node{
    double l, r;
}a[maxn];
int cmp(node a, node b){
    if(a.l==b.l)
        return a.r>b.r;
    return a.l<b.l;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int flag = 0;
        cin >> n >> wei >> hei;
        for(int i = 0; i < n; i++){
            int xi, ri;
            cin >> xi >> ri;
            if(ri*2<=hei){
                a[i].r = 0;
                a[i].l = 0;
                continue;
            }
            double tmp = sqrt((double)pow(ri, 2) - (double)pow(hei / 2.0, 2));
            a[i].l = xi - tmp < 0 ? 0 : xi - tmp;
            a[i].r = xi + tmp;
        }
        sort(a,a+n,cmp);
        int it = 0;
        while(it < n && a[it].r <= 0)
            it++;
        double sum = 0;
        int cnt = 0;
        if(it < n && a[it].l==0){
            sum = a[it].r;
            cnt++;
            it++;
        }
        else
            flag = 1;
        while(it < n && sum < (double)wei){
            double maxD = sum;
            while(it < n && a[it].l <= sum){
                maxD = max(maxD, a[it].r);
                it++;
            }
            if(maxD <= sum){
                flag = 1;
                break;
            }
            sum = maxD;
            cnt++;
            it++;
        }
        if(sum < (double)wei)
            flag = 1;
        if(flag)
            cout<<"0"<<endl;
        else
            cout<<cnt<<endl;
    }
    return 0;
}
