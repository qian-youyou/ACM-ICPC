#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll a,b,c,n;
        scanf("%lld%lld",&n,&a);
        if(n>2||n==0)
        {
            printf("-1 -1\n");
            continue;
        }
        else if(n==1)
        {
            printf("1 %lld\n",a+1);
            continue;
        }
        else
        {
            if(a%2==1&&a>1)
            {
                ll cc=(a-1)/2;
                b=2*cc*(cc+1);
                c=2*cc*(cc+1)+1;
                printf("%lld %lld\n",b,c);
            }
            else if(a%2==0&&a>2)
            {
                ll cc=a/2;
                b=cc*cc-1;
                c=cc*cc+1;
                printf("%lld %lld\n",b,c);
            }
            else{
                printf("-1 -1\n");
            }
        }

    }
    return 0;
}
