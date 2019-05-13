#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100;
char str[maxn][35], s1[35], s2[35];
int num, cnt, head[maxn], vis[maxn];

struct Edge {
  int to, next;
} edge[maxn];

void insert(int x, int y) {
  edge[cnt].to = y, edge[cnt].next = head[x];
  head[x] = cnt++;
}

bool dfs(int now) {
  if (vis[now]) return 1;
  for (int i = head[now]; i != -1; i = edge[i].next) {
    int to = edge[i].to;
    if (dfs(to)) return 1;
  }
  return 0;
}

int main() {
  int n, a, b, f;
  while (~scanf("%d", &n)) {
    memset(head, -1, sizeof head);
    num = cnt = f = 0;

    for (int i = 0; i < n; ++i) {
      scanf("%s%s", s1, s2);
      if (f) continue;
      memset(vis, 0, sizeof vis);

      a = b = -1;
      for (int j = 0; j < num && (a == -1 || b == -1); ++j) {
        if (a == -1 && strcmp(str[j], s1) == 0) a = j;
        if (b == -1 && strcmp(str[j], s2) == 0) b = j;
      }
      if (a != -1 && b != -1) {
        vis[a] = 1;
        if (dfs(b)) {
          printf("%s %s\n", s1, s2);
          f = 1;
        } else {
          insert(a, b);
        }
      } else {
        if (a == -1) {a = num; strcpy(str[num++], s1);}
        if (b == -1) {b = num; strcpy(str[num++], s2);}

        insert(a, b);
      }
    }
    if (f == 0) printf("0\n");
  }
  return 0;
}
