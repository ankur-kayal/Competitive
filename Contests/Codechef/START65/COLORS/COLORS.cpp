#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

bool good(int N, int K, int m) {
	vector<int> A(N);
	int color = 1;
	int i;
	for (i = 0; i < N - (N % K); i++) {
		if (color > m) {
			color = 1;
		}
		A[i] = color;
		color++;
	}

	for(; i < N; i++) {
		A[i] = color;
		color++;
	}

	for(int i = 0; i < N; i++) {
		A.push_back(A[i]);
	}

	vector<bool> visited(m);
	for(int i = 0; i < K; i++) {
		if (visited[A[i]]) {
			return false;
		}
		visited[A[i]] = true;
	}

	// verify all subarrays
	int l = 0;

	for(int r = K; r < 2 * N; r++) {
		visited[A[l]] = false;
		l++;
		if (visited[A[r]]) {
			return false;
		}
		visited[A[r]] = true;
	}
	return true;
}

void run_cases() {
	int N, K;
	cin >> N >> K;

	int l = 0, r = N;

	while(r > l + 1) {
		int m = (l + r) / 2;

		if (good(N, K, m)) {
			r = m;
		} else {
			l = m;
		}
	}

	cout << r << '\n';
	vector<int> A(N);
	int color = 1;
	int i;
	for (i = 0; i < N - (N % K); i++) {
		if (color > r) {
			color = 1;
		}
		A[i] = color;
		color++;
	}

	for(; i < N; i++) {
		A[i] = color;
		color++;
	}

	output_vector(A);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}