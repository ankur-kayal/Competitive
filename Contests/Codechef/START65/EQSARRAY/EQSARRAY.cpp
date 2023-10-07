#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N, K;
	cin >> N >> K;

	vector<int> A(N);
	for(auto &u: A)
		cin >> u;

	if (N == 1) {
		if (A[0] == K) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
		return;
	}

	for(int i = 0; i < N - 1; i++) {
		if (A[i] == K) {
			cout << "Yes" << '\n';
			return;
		}
	}

	cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}