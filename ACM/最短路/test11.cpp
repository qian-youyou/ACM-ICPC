#include <bits/stdc++.h>
using namespace std;
int main() {
	int iCase;
	cin >> iCase;
	while (iCase--) {
		int n, cnt = 0, num;
		cin >> n;
		while (n--) {
			cin >> num;
			if (num % 4 == 0) num--;
			else if (num % 4 == 3) num++;
			cnt ^= num;
		}
		if (cnt == 0) cout << "Bob" << endl;
		else cout << "Alice" << endl;
	}
	return 0;
}
