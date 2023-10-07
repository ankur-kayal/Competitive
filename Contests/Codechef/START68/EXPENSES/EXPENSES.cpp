#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N, X;
	cin >> N >> X;

	int earning = 1;
	for(int i = 1; i <= X; i++) {
		earning *= 2;
	}



	while(N--) {
		earning /= 2;
	}

	cout << earning << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}