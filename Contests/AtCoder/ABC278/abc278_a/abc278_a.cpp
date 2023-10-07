#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N, K;
	cin >> N >> K;

	deque<int> A(N);
	for(auto &u: A)
		cin >> u;

	while(K--) {
		A.pop_front();
		A.push_back(0);
	}

	for(auto &u: A) {
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