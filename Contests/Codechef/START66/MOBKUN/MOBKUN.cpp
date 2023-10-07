#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int64_t N, M, K, X;
	cin >> N >> M >> K >> X;

	int64_t l = 0, r = 1e9;

	while(r > l + 1) {
		int64_t m = (l + r) / 2;

		int64_t total_mob_years = (m) / K;

		int64_t total_days_before = (m) * N + total_mob_years * M;

		if (total_days_before < X) {
			l = m;
		} else {
			r = m;
		}
	}

	cout << (r % K == 0 ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}