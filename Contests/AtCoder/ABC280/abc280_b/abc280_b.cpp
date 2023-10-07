#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;

	vector<int64_t> S(N);
	for(auto &u: S)
		cin >> u;

	vector<int64_t> A(N);
	A[0] = S[0];
	for(int i = 1; i < N; i++) {
		A[i] = S[i] - S[i - 1];
	}

	for(auto u: A) {
		cout << u << " ";
	}
	cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}