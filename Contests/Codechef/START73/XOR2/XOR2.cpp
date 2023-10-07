#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;
	vector<int> A(N);

	for(auto &u: A)
		cin >> u;

	for(int i = 1; i < N; i++) {
		A[i] = A[i] ^ A[i - 1];
		A[i - 1] = A[i - 1] ^ A[i - 1];
	}

	if (N % 2 == 0) {
		if (A.back() == 0) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	} else {
		cout << "YES" << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}