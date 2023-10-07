#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;

	vector<int> A(N);
	for(auto &u: A)
		cin >> u;

	int odd_count = count(A.begin(), A.end(), 1);

	int even_count = count(A.begin(), A.end(), 0);
	int elements_left = N - odd_count;

	if (even_count == 1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
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