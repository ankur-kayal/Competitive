#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N + 1);
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());

		cout << adj[i].size();

		for(auto u: adj[i]) {
			cout << " " << u;
		}

		cout << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}