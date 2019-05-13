#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
LL sum[maxn];
int Next[maxn];

int main() {
  int t, ca = 1;
  scanf("%d", &t);
  while (t--) {
    LL A, B, N, x;
    scanf("%lld%lld%lld", &A, &B, &N);
    for (int i = 1; i <= A; ++i) {
      scanf("%lld", &x);
      sum[i] = sum[i - 1] + x;
    }
    for (int i = 1; i <= A; ++i) {
      int pos = lower_bound(sum + 1, sum + A + 1, i) - sum;
      Next[i] = pos;
      //printf("%d %d\n", i, Next[i]);
    }
    LL now = A, Last = 1;
    while (Next[now] != now && N) {
      --N;
      Last = now - sum[Next[now] - 1];
      now = Next[now];
      //printf("%lld-%lld\n", now, Last);
    }
  return 0;
}
