#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        cin>>s;
        int flag = -1;
        vector<long long> Q;
        int len = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]-'0'!=flag)
            {
                Q.push_back(len);
                len = 1;
                flag = s[i]-'0';
            }
            else
                len++;
        }
        Q.push_back(len);
        Q.push_back(0);
        long long res = 0;
        for(int i=1;i<Q.size()-1;i++)
            res += Q[i]*Q[i];
        long long ans = res;
        for(int i=1;i<Q.size()-1;i++)
        {
            long long tmp = 0;
            if(Q[i]==1)
                ans = max(ans,res-Q[i-1]*Q[i-1]-Q[i]*Q[i]-Q[i+1]*Q[i+1]+(Q[i-1]+Q[i+1]+1)*(Q[i-1]+Q[i+1]+1));
            else
            {
                ans = max(ans,res-Q[i-1]*Q[i-1]-Q[i]*Q[i]+(Q[i-1]+1)*(Q[i-1]+1)+(Q[i]-1)*(Q[i]-1));
                ans = max(ans,res-Q[i+1]*Q[i+1]-Q[i]*Q[i]+(Q[i+1]+1)*(Q[i+1]+1)+(Q[i]-1)*(Q[i]-1));
            }
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
}
