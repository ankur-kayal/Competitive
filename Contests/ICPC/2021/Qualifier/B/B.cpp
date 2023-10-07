#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;

	string S;
	cin >> S;

	vector<int> D(N);
	for(auto &u: D) {
		cin >> u;
	}

	int moves = 0;

	vector<int> colors(N + 100);
	for(int i = 0; i < N; i++) {
		if(S[i] == 'R') {
			
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