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
            //�������ٶ���������������ٶ�������Ҫ�죬ֱ��Ӯ
            if(a[i]>b[j])s++,i++,j++;
            //�����ɵ��ٶ�������������ٶ�����Ҫ�죬ֱ��Ӯ
            else if(a[k]>b[l])s++,k--,l--;
            else{
                //������ٶ������ĺ������ٶ�������Ƚϣ����С�ھ�ֱ����
                if(a[i]<b[l])s--;
                i++,l--;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
