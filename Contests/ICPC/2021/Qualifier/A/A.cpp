#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N, X;
	cin >> N >> X;

	string S;
	cin >> S;

	priority_queue<int> pq;

	int ones = 0;
	int zero = 0;
	for(auto u: S) {
		if(u == '0') {
			zero++;
		} else {
			ones++;
			pq.push(zero);
			zero = 0;
		}
	}

	if(zero > 0) {
		pq.push(zero);
	}

	while(X > 0 && !pq.empty()) {
		int top = pq.top();
		pq.pop();

		int currentCost = top * 2 + 1;
		if(currentCost <= X) {
			X -= currentCost;
			ones += top;
		} else {
			int canTake = (X - 1) / 2;
			int remaining = top - canTake;

			X -= (2 * canTake + 1);
			ones += canTake;
			if(remaining > 0) {
				pq.push(remaining);
			}
		}
	}

	cout << ones << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}