#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 55;
LL fei[maxn] = {1, 1};

void init() {
  for (int i = 2; i < 50; ++i) {
    fei[i] = fei[i - 1] + fei[i - 2];
  }
}

int main() {
  init();
  LL M;
  while (~scanf("%lld", &M)) {
    if (M == 0) {
      printf("2\n1 1\n2 1\n");
      continue;
    }
    vector<LL> v;
    for (int i = 49; i >= 0; --i) {
      if (M >= fei[i]) {
        M -= fei[i];
        v.push_back(fei[i]);
        //printf("%lld\n", fei[i]);
      }
    }
    int len = v.size(), now = 0, sta = 0;
    printf("%d\n", len + 1);
    while (now < len) {
      printf("%d %lld\n", sta + 1, 200 - v[now++]);
      sta += 2;
    }
    printf("%d %d\n", sta, sta);
  }
  return 0;
}
