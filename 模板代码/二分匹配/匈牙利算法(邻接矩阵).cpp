#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 107;
int N, K;
int edge[maxn][maxn], head[maxn];
bool vis[maxn];
void init(){
    memset(edge, 0, sizeof(edge));
    memset(head, 0, sizeof(head));
}
bool find_edge(int x) {
	for (int i = 1; i <= N; i++) {
		if (edge[x][i] && !vis[i]) {
			vis[i] = true;
			if (!head[i] || find_edge(head[i])) {
				head[i] = x;
				return true;
			}
		}
	}
	return false;
}
int Magyar(int N){
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(vis, false, sizeof(vis));
        if (find_edge(i)) {
            ans++;
        }
    }
    return ans;
}
int main() {
	while (cin >> N >> K) {
		int x, y;
		for (int i = 1; i <= K; i++){
			cin >> x >> y;
			edge[x][y] = 1;
		}
		cout << Magyar(N) << endl;
	}
	return 0;
}
