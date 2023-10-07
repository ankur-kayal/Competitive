#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;
	int Y;
	cin >> Y;
	vector<int> A(N);
	for(auto &u: A)
		cin >> u;

	vector<int> bits(24);
	for(auto u: A) {
		for (int bit = 0; bit < 24; bit++) {
			if (u >> bit & 1) {
				bits[bit] = 1;
			}
		}
	}

	int ans = 0;
	for (int bit = 0; bit < 24; bit++) {
		bool set = Y >> bit & 1;
		if (set && bits[bit] == 0) {
			ans += (1 << bit);
		}
		if (!set && bits[bit] == 1) {
			cout << -1 << '\n';
			return;
		}
	}

	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}