#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};

void run_cases() {
	int N;
	cin >> N;

	vector<int> A(N);
	for(auto &u: A)
		cin >> u;

	vector<vector<int64_t>> edges;
	for(int bit = 0; bit < 30; bit++) {
		int last = -1;
		for(int i = 0; i < N; i++) {
			if (A[i] >> bit & 1) {
				if (last != -1) {
					edges.push_back({i, last, (1 << bit)});
				}
				last = i;
			}
		}
	}

	sort(edges.begin(), edges.end(), [&](vector<int64_t> &a, vector<int64_t> &b){
		return a[2] < b[2];
	});

	union_find uf;
	uf.init(N);

	int64_t weights = 0;


	for(auto u: edges) {
		if (uf.unite(u[0], u[1])) {
			weights += u[2];
		}
	}

	if (uf.components == 1) {
		cout << weights << '\n';
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