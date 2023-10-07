#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    T tree_sum = 0;
    vector<T> tree;
 
    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }
 
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
 
    void init(int n) {
        tree_n = n;
        tree_sum = 0;
        tree.assign(tree_n + 1, 0);
    }
 
    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
        tree_sum = 0;
 
        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];
            tree_sum += initial[i - 1];
 
            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }
 
    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);
        tree_sum += change;
 
        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }
 
    // Returns the sum of the range [0, count).
    T query(int count) const {
        count = min(count, tree_n);
        T sum = 0;
 
        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];
 
        return sum;
    }
 
    // Returns the sum of the range [start, tree_n).
    T query_suffix(int start) const {
        return tree_sum - query(start);
    }
 
    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }
 
    // Returns the element at index a in O(1) amortized across every index. Equivalent to query(a, a + 1).
    T get(int a) const {
        assert(0 <= a && a < tree_n);
        int above = a + 1;
        T sum = tree[above];
        above -= above & -above;
 
        while (a != above) {
            sum -= tree[a];
            a -= a & -a;
        }
 
        return sum;
    }
 
    bool set(int index, T value) {
        assert(0 <= index && index < tree_n);
        T current = get(index);
 
        if (current == value)
            return false;
 
        update(index, value - current);
        return true;
    }
};

void run_cases() {
	int N, Q;
	cin >> N >> Q;

	vector<int64_t> A(N);
	for (auto &u: A) {
		cin >> u;
	}

	vector<fenwick_tree<int64_t>> trees(60);
	for(int i = 0; i < 60; i++) {
		trees[i] = fenwick_tree<int64_t>(N);
	}

	for(int i = 0; i < 60; i++) {
		for(int j = 0; j < N; j++) {
			if (A[j] >> i & 1) {
				trees[i].set(j, 1);
			}
		}
	}

	while(Q--) {
		int k, l1, r1, l2, r2;

		cin >> k >> l1 >> r1 >> l2 >> r2;

		int64_t first_range = trees[k].query(l1 - 1, r1);
		int64_t second_range = trees[k].query(l2 - 1, r2);

		int64_t first_range_total_elements = r1 - l1 + 1;
		int64_t second_range_total_elements = r2 - l2 + 1;

		int64_t answer = (first_range * (second_range_total_elements - second_range)) + (second_range * (first_range_total_elements - first_range));
		cout << answer << '\n';
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