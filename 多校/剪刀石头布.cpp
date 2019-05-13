#include <iostream>
#include <cmath>
#include<cstdio>
using namespace std;
typedef long long int LL;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int T;
    scanf("%d",&T);
    LL a1, a2, a3, b1, b2, b3;
    while (T--) {
        //cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
        scanf("%lld%lld%lld",&a1,&a2,&a3);
        scanf("%lld%lld%lld",&b1,&b2,&b3);
        LL ret = a1 * b2 + a2 * b3 + a3 * b1 - a1 * b3 - a2 * b1 - a3 * b2;
        LL fenmu = a1 + a2 + a3;
        if (ret == 0) {
            //cout << 0 << endl;
            printf("0\n");
        } else if (abs(ret) >= abs(fenmu) && ret % fenmu == 0) {
           // cout << ret / fenmu << endl;
           printf("%lld\n",ret/fenmu);
        } else {
            LL m = gcd(ret, fenmu);
            //cout << ret / m << '/' << fenmu / m << endl;
            LL a=ret / m,b=fenmu / m;
            if(b<0) a=-a;
            printf("%lld/%lld\n",a , b );
        }

    }
    return 0;
}
