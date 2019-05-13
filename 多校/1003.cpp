#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(j)
                    cout<<' ';
                if(i+j==n-1)
                    cout<<1;
                else
                    cout<<0;
            }
            cout<<endl;
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(j)
                    cout<<' ';
                if(i==n-1&&j==n-1)
                    cout<<1;
                else
                    cout<<0;
            }
            cout<<endl;
        }
    }
    return 0;
}
