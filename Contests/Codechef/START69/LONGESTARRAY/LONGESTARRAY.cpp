#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;

	vector<int> A(N);
	for(auto &u: A) {
		cin >> u;
	}

	vector<int> suffix_or(N + 1);
	for(int i = N - 1; i >= 0; i--) {
		suffix_or[i] = suffix_or[i + 1] | A[i];
	}

	int answer = -1;

	int l = 0;

	int prefix_or = 0;

	int outside_or = 0;
	int subarray_or = 0;

	vector<int> bits(31);

	for(int r = 0; r < N; r++) {
		for(int i = 0; i < 30; i++) {
			if (A[r] >> i & 1) {
				bits[i]++;
				if (bits[i] == 1) {
					subarray_or += (1 << i);
				}
			}
		}
		while(l < r && subarray_or > (prefix_or | suffix_or[r + 1])) {
			prefix_or = prefix_or | A[l];
			for(int i = 0; i < 30; i++) {
				if (A[l] >> i & 1) {
					bits[i]--;
					if (bits[i] == 0) {
						subarray_or -= (1 << i);
					}
				}
			}
			l++;
		}

		if (l <= r && subarray_or == (prefix_or | suffix_or[r + 1])) {
			answer = max(answer, r - l + 1);
		}
	}

	cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}