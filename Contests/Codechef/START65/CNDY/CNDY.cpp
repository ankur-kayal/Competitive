#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;

	vector<int> A(2 * N);
	for(auto &u: A)
		cin >> u;

	set<int> first, second;

	for(auto u: A) {
		if (!first.count(u)) {
			first.insert(u);
		} else if (!second.count(u)) {
			second.insert(u);
		} else {
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}