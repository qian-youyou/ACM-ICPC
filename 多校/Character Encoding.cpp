#include<bits/stdc++.h>
#define ll long long
//typedef long long ll;
const int mod=1000000007;
using namespace std;
struct node{
	ll m[2][2];
};
node a,c;
node mp;
node power(node x,node y){//æÿ’Û≥À∑®
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			mp.m[i][j]=0;
			for(int p =0;p<2;p++)
				mp.m[i][j]+=(x.m[i][p]*y.m[p][j]);
		}
	return mp;
}
int/*void*/ work(ll n){//øÏÀŸ√›
	while(n){
		if(n&1){
			c=power(c,a);
		}
		a=power(a,a);
		n>>=1;
	}
//	return c;
}
using namespace std;
int main(){
	ll x,y,n;
	scanf("%lld %lld",&x,&y);
	scanf("%lld",&n);
	a.m[0][0]=1;c.m[0][0]=1;
	a.m[0][1]=-1;c.m[0][1]=0;
	a.m[1][0]=1;c.m[1][0]=0;
	a.m[1][1]=0;c.m[1][1]=1;
	if(n == 1)
		printf("%lld\n", x );
    else if(n == 2)
		printf("%lld\n", y );
    else {
   		work(n-2);
		ll ans=((abs(y)%mod)*(abs(c.m[0][0])%mod)%mod+(abs(x)%mod*abs(c.m[0][1])%mod)%mod)%mod;
		printf("%lld\n",ans);
	}
	/*	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
			printf("%d ",c.m[i][j]);
			printf("\n");
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
			printf("%d ",a.m[i][j]);
			printf("\n");
	}*/
	return 0;
}
