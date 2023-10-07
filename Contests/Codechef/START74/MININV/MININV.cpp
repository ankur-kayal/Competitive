#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;

	vector<int> A(N);
	for(auto &u: A)
		cin >> u;

	int64_t answer = 0;
	map<int64_t, int64_t> cnt;
	map<int64_t, int64_t> cnt_back;
	for (int i = N - 1; i >= 0; i--) {
		cnt[A[i]]++;
	}

	vector<int64_t> inversions(N);

	for (int i = N - 1; i >= 0; i--) {
		inversions[i] = cnt[A[i] + 1] - cnt_back[A[i]];
		cnt[A[i]]--;
		cnt_back[A[i] + 1]++;
	}

	for (int i = N - 2; i >= 0; i--) {
		inversions[i] += inversions[i + 1];
	}


	cout << *max_element(inversions.begin(), inversions.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}