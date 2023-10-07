#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	string s;
	cin >> s;

	int count_01 = 0, count_10 = 0;

	for(int i = 1; i < s.length(); i++) {
		if (s[i - 1] == '1' && s[i] == '0') {
			count_10++;
		} else if (s[i - 1] == '0' && s[i] == '1') {
			count_01++;
		}
	}

	int answer = 0;

	for(int i = 0; i < s.length(); i++) {
		int n_count_10 = count_10;
		int n_count_01 = count_01;

		if (i > 0) {
			if (s[i - 1] == '0' && s[i] == '1') {
				n_count_01--;
			}
			if (s[i - 1] == '1' && s[i] == '0') {
				n_count_10--;
			}
		}

		if (i + 1 < s.length()) {
			if (s[i] == '0' && s[i + 1] == '1') {
				n_count_01--;
			}
			if (s[i] == '1' && s[i + 1] == '0') {
				n_count_10--;
			}
		}

		if (s[i] == '0') {
			s[i] = '1';
		} else {
			s[i] = '0';
		}

		if (i > 0) {
			if (s[i - 1] == '0' && s[i] == '1') {
				n_count_01++;
			}
			if (s[i - 1] == '1' && s[i] == '0') {
				n_count_10++;
			}
		}

		if (i + 1 < s.length()) {
			if (s[i] == '0' && s[i + 1] == '1') {
				n_count_01++;
			}
			if (s[i] == '1' && s[i + 1] == '0') {
				n_count_10++;
			}
		}

		if (s[i] == '0') {
			s[i] = '1';
		} else {
			s[i] = '0';
		}


		if (n_count_10 == n_count_01) {
			answer++;
		}

	}
	cout << answer << '\n';
	
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}