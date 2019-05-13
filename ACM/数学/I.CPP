#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
const int maxn = 200010;
string arr[maxn];
bool isend[maxn];
int cnt = 1;

bool HasChar(string s) {
  for (int i = 0; s[i]; ++i) {
    if (s[i] < '0' || s[i] > 9) {
      return 1;
    }
  }
  return 0;
}

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
  int ans = 0, k = 0;

  for (int i = 1; i < cnt; ++i) {
    int len = arr[i].size();
    if (isend[i] == 1) {
      // 是结尾
      if (HasChar(arr[i])) {
        // 不合法
        v.push_back(ans);
        ans = 0;
        continue;
      }

//////////////////////////////////////////

      if (arr[i][0] == '0' && len == 1) {
        if (i == len - 1) {
          // 是最后一个字符串
          // 直接输出
          if (k == 0) {
            cout << arr[i];
            ++k;
          } else {
            cout << ' ' << arr[i];
          }
          ++ans;
          v.push_back(ans);
          ans = 0;
          continue;
        }

        if (HasChar(arr[i+1])) {
          // 下一个有字符
          ++ans;
          if (k == 0) {
            cout << arr[i];
            ++k;
          } else {
            cout << ' ' << arr[i];
          }

        } else {
          // 下一个无字符
          ++i;
        }
        v.push_back(ans);
        ans = 0;

      } else if (arr[i][0] == 0 && len > 1) {

        // 开头是0，长度大于1，不合法
        v.push_back(ans);
        ans = 0;
        if (!HasChar(arr[i+1])) {
          // 下一个无字符
          ++i;
        }

      } else {



        // 是开头没有0合法数字
        if (i == len - 1) {
          // 是最后一个字符串
          // 直接输出
          if (k == 0) {
            cout << arr[i];
            ++k;
          } else {
            cout << ' ' << arr[i];
          }
          ++ans;
          v.push_back(ans);
          ans = 0;
          continue;
        }
        if (!HasChar(arr[i+1])) {
          // 下一个也没有字符
          if (k == 0) {
            cout << arr[i] << arr[i + 1];
            ++k;
          } else {
            cout << ' ' << arr[i] << arr[i + 1];
          }
          ++i;
        } else {

          // 下一行第一个串有字符
          if (k == 0) {
            cout << arr[i];
            ++k;
          } else {
            cout << ' ' << arr[i];
          }
        }

        ++ans;
        v.push_back(ans);
        ans = 0;
      }


//////////////////////////////////////////////////////////

    } else {

      // 在中间
      if (HasChar(arr[i])) {
        // 有字符，不合法
        continue;
      }
      // 没有字符
      if ((len == 1 && arr[i][0] == '0') || arr[i][0] > '0') {
        // 合法
        ++ans;
        if (k == 0) {
          cout << arr[i];
          ++k;
        } else {
          cout << ' ' << arr[i];
        }
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
