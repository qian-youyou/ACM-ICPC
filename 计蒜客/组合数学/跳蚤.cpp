#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long int
using namespace std;
const int maxn = 1005,maxm = 100005,INF = 1000000000;

LL N,M;
int fac[maxn],faci = 0;

void Sp(){
	LL e = M;
	for (LL i = 2; i * i <= e; i++){
		if (e % i == 0){
			fac[++faci] = i;
			while (e % i == 0) e /= i;
		}
	}
	if (e - 1) fac[++faci] = e;
}

LL qpow(LL a,LL b){
	LL ans = 1;
	for (; b; b >>= 1, a *= a)
		if (b & 1) ans *= a;
	return ans;
}

LL cal(int s){
	LL mult = 1,pos = 1;
	for (int i = 1; s; i++,s >>= 1){
		if (s & 1){
			mult *= fac[i];
			pos *= -1;
		}
	}
	return qpow(M/mult,N) * pos;
}

void solve(){
	Sp();
	LL tot = qpow(M,N),maxv = ((LL)1 << faci) - 1;
	for (int s = 1; s <= maxv; s++)
		tot += cal(s);
	cout<<tot<<endl;
}

int main()
{
	cin>>N>>M;
	solve();
	return 0;
}
