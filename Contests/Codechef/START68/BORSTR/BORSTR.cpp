#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;

	string S;
	cin >> S;

	map<string, int> cnt;

	string substring = "";
	char prev = S[0];
	substring += S[0];

	for(int i = 1; i < N; i++) {
		if (S[i] != prev) {
			cnt[substring]++;
			substring = "";
		}
		prev = S[i];
		substring += S[i];
	}

	cnt[substring]++;

	int ans = 0;
	for(auto [key, value]: cnt) {
		int len = key.length();

		if (value > 1) {
			ans = max(ans, len);
		} else {
			ans = max(ans, len - 1);
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