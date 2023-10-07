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

void run_cases() {
	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);
	for(auto &u: B) {
		cin >> u;
	}

	map<int, deque<int>> positions;
	for(int i = 0; i < N; i++) {
		positions[B[i]].push_back(i);
	}

	int element = 1;
	for(int i = 0; i < N; i++) {
		if (A[i] != 0) {
			continue;
		}

		int freq = B[i];
		while(!positions[B[i]].empty() && freq > 0) {
			A[positions[B[i]].front()] = element;
			positions[B[i]].pop_front();
			freq--;
		}

		element++;
		if (freq > 0) {
			cout << -1 << '\n';
			return;
		}
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