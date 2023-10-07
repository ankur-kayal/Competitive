#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N;
	cin >> N;

	deque<int> A(N);
	for(auto &u: A)
		cin >> u;

	int moves = 0;

	while(A.size() > 1) {
		int first_element = A.front();
		A.pop_front();
		int last_element = A.back();
		A.pop_back();

		if (first_element > last_element) {
			A.push_front(first_element - last_element);
			moves++;
		} else if (last_element > first_element) {
			A.push_back(last_element - first_element);
			moves++;
		}
	}

	cout << moves << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}