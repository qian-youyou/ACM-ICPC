#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;
const int maxn = 200010;
string arr[maxn];
bool isend[maxn];
int cnt = 1;

int main() {
  //freopen("/Users/Amon/Desktop/a.txt", "r", stdin);
  string ss;
  while (getline(cin, ss)) {
    istringstream line;
    line.str(ss);
    isend[cnt - 1] = 1;
    while (line >> arr[cnt]) {
      ++cnt;
    }
  }
  isend[cnt - 1] = 1;

  vector<int> v;
  int ans = 0;

  for (int i = 1; i < cnt; ++i) {
    int len = arr[i].size();
    if (isend[i] == 1) {
      // �ǽ�β
      if (arr[i][0] < '0' || arr[i][0] > '9' || arr[i][len-1] < '0' || arr[i][len-1] > '9') {
        // ���Ϸ�
        v.push_back(ans);
        ans = 0;
        continue;
      }

      if (arr[i][0] == '0' && len == 1) {
        len = arr[i+1].size();
        if (arr[i + 1][0] < '0' || arr[i + 1][0] > '9' || arr[i + 1][len-1] < '0' || arr[i + 1][len-1] > '9') {
          ++ans;
          cout << arr[i] << ' ';
        } else {
          ++i;
        }
        v.push_back(ans);
        ans = 0;
      } else if (arr[i][0] == '0' && len > 1) {
        // ��ͷ��0�����ȴ���1�����Ϸ�
        ++i;
        v.push_back(ans);
        ans = 0;
      } else {
        // �ǺϷ�����
        len = arr[i+1].size();
        if (!(arr[i][0] < '0' || arr[i][0] > '9' || arr[i][len-1] < '0' || arr[i][len-1] > '9')) {
          // ��һ��Ҳ�Ϸ�
          cout << arr[i] << arr[i + 1] << ' ';
          ++i;
        } else {
          cout << arr[i] << ' ';
        }
        ++ans;
        v.push_back(ans);
        ans = 0;
      }



    } else {
      // ���м�
      if (arr[i][0] < '0' || arr[i][0] > '9' || arr[i][len-1] < '0' || arr[i][len-1] > '9') {
        // ���Ϸ�
        continue;
      }

      if ((len == 1 && arr[i][0] == '0') || arr[i][0] > '0') {
        // �Ϸ�
        ++ans;
        cout << arr[i] << ' ';
        continue;
      }
    }
  }
  cout << endl;
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    printf("%d\n", v[i]);
  }
  return 0;
}
