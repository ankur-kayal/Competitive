#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			if (ch == '#') {
				ans++;
			}
		}
	}

	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}