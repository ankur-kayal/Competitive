#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N, M;
	cin >> N >> M;

	vector<int> T(M), C(M);

	for(auto &u: T)
		cin >> u;

	for(auto &u: C)
		cin >> u;

	vector<vector<int>> dp(M + 1, vector<int>(2, 0));
	vector<vector<int>> values(M + 1, vector<int>(2));

	for(int i = 0; i < M; i++) {
		int diff;
		if (i == 0) {
			diff = T[i];
		} else {
			diff = T[i] - T[i - 1];
		}

		for (int j = 0; j < 2; j++) {
			int a = values[i][j];
			int b = values[i][j];

			if (C[i] == 1) {
				
			}
		}
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