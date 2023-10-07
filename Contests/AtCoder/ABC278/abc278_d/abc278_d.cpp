#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;

	vector<int64_t> A(N);
	for(auto &u: A) {
		cin >> u;
	}

	bool assignment_done = false;
	int64_t assigned_value = -1;

	map<int, int64_t> to_add;

	int Q;
	cin >> Q;
	while(Q--) {
		int ch;
		cin >> ch;

		if (ch == 1) {
			int64_t x;
			cin >> x;
			assignment_done = true;
			assigned_value = x;
			to_add.clear();
		} else if (ch == 2) {
			int i;
			int64_t x;
			cin >> i >> x;
			i--;
			to_add[i] += x;
		} else {
			int i;
			cin >> i;
			i--;
			if (!assignment_done) {
				cout << A[i] + to_add[i] << '\n';
			} else {
				cout << assigned_value + to_add[i] << '\n';
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