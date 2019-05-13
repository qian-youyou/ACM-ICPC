#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll prime[17] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
ll n,ans;
int i;
void dfs(ll th, ll num, ll step){
	if(step == 0){
		ll t = pow(n, 1.0 / num);
		if(pow(t, 0.0 + num) > n)
            t--;
		t--;
		if(t > 0)
			ans += t * ((i & 1) ? 1 : -1);
		return;
	}
    if(th>=17)
        return;
    if(num*prime[th]<60)
        dfs(th+1,num*prime[th],step-1);
    dfs(th+1,num,step);
}
int main(){
    while(~scanf("%lld",&n)){
        ans = 0;
        for(i = 1;i <= 3;i++)
            dfs(0,1,i);
        printf("%lld\n",ans+1);
    }
    return 0;
}
