#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	string s;
	cin >> s;
	string t;
	cin >> t;

	for(int i = 0; i < s.length(); i++) {
		if(s[i] != t[i]) {
			cout << i + 1 << '\n';
			return;
		}
	}
	cout << t.length() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}