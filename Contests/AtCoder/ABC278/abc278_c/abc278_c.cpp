#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N, Q;
	cin >> N >> Q;

	set<pair<int,int>> follows;

	while(Q--) {
		int t, a, b;
		cin >> t >> a >> b;

		if (t == 1) {
			follows.insert(make_pair(a, b));
		} else if (t == 2) {
			if (follows.count(make_pair(a, b))) {
				follows.erase(make_pair(a, b));
			}
		} else {
			if (follows.count(make_pair(a, b)) && follows.count(make_pair(b, a))) {
				cout << "Yes" << '\n';
			}  else {
				cout << "No" << '\n';
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}