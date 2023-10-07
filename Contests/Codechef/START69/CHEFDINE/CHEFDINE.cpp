#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N, K;
	cin >> N >> K;

	vector<int> A(N), B(N);
	for(auto &u: A)
		cin >> u;
	for(auto &u: B) {
		cin >> u;
	}

	vector<pair<int,int>> item;
	for(int i = 0; i < N; i++) {
		item.emplace_back(A[i], B[i]);
	}

	sort(item.begin(), item.end(), [&](auto a, auto b) {
		return a.second < b.second;
	});

	set<int> used_items;
	int64_t answer = 0;
	for(auto [category, time]: item) {
		if (used_items.count(category)) {
			continue;
		}
		answer += time;
		used_items.insert(category);

		if (used_items.size() == K) {
			break;
		}
	}

	if (used_items.size() == K) {
		cout << answer << '\n';
	} else {
		cout << -1 << '\n';
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