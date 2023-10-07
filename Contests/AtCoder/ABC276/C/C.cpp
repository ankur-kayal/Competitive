#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;

	vector<int> P(N);
	for(auto &u: P) {
		cin >> u;
	}

	prev_permutation(P.begin(), P.end());

	for(auto u: P) {
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