#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

struct segment_change {
    int64_t to_add;
    static const int64_t SENTINEL = 0;

    // Make sure that the default constructor is the identity segment_change
    segment_change(int64_t _to_add = SENTINEL) : to_add(_to_add) {}

    // resets to the SENTINEL value
    void reset() {
        to_add = SENTINEL;
    }

    bool has_change() const {
        return to_add != SENTINEL;
    }

    // Return the combined result of applying this segment change followed by the `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add);
    }
};

struct segment {
    int64_t sum;

    static const int64_t SENTINEL = 2e9;

    // Make sure that the default constructor is the identity segment
    segment(int64_t _sum = SENTINEL) : sum(_sum) {}

    // checks if the current segment is empty based on the default value
    bool empty() const {
        return sum == SENTINEL;
    }

    // evaluating the change on a particular node
    void apply(int length, const segment_change &change) {
        if(change.has_change()) {
            sum += change.to_add;
        }
    }

    // merge function
    void join(const segment &other) {
        sum = min(sum, other.sum);
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct segment_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    segment_tree(int n = -1) {
        if(n >= 0) {
            init(n);
        }
    }

    void init(int n) {
        tree_n = 1;
        while(tree_n < n) {
            tree_n *= 2;
        }

        tree.assign(2 * tree_n, segment());
        changes.assign(2 * tree_n, segment_change());
    }

    void build(const vector<segment> &initial, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < int(initial.size())) {
                tree[x] = initial[lx];
            }
            return;
        }

        int m = (rx + lx) / 2;
        build(initial, 2 * x + 1, lx, m);
        build(initial, 2 * x + 2, m, rx);
        tree[x].join(tree[2 * x + 1], tree[2 * x + 2]);
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        build(initial, 0, 0, tree_n);
    }

    // Apply the change to the current index and push down the change
    void propagate(int x, int lx, int rx) {
        if(!changes[x].has_change()) {
            return;
        }
        tree[x].apply(rx - lx, changes[x]);
        if(rx - lx != 1) {
            changes[2 * x + 1] = changes[2 * x + 1].combine(changes[x]);
            changes[2 * x + 2] = changes[2 * x + 2].combine(changes[x]);
        }
        changes[x].reset();
    }

    // Queries in the range [l, r)
    segment query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(lx >= r or l >= rx) {
            return segment();
        }
        if(lx >= l && rx <= r) {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        segment left = query(l, r, 2 * x + 1, lx, m);
        segment right = query(l, r, 2 * x + 2, m, rx);
        left.join(right);
        return left;
    }

    segment query(int l, int r) {
        return query(l, r, 0, 0, tree_n);
    }

    // Updates the change in the range [l, r)
    void update(int l, int r, const segment_change &change, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(lx >= r || l >= rx) {
            return;
        }
        if(lx >= l && rx <= r) {
            changes[x] = changes[x].combine(change);
            propagate(x, lx, rx);
            return;
        }

        int m = (lx + rx) / 2;
        update(l, r, change, 2 * x + 1, lx, m);
        update(l, r, change, 2 * x + 2, m, rx);
        tree[x].join(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int l, int r, const segment_change &change) {
        update(l, r, change, 0, 0, tree_n);
    } 
};

void run_cases() {
    int N, M;
    cin >> N >> M;

    vector<array<int, 3>> segments(N);

    for(int i = 0; i < N; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        segments[i] = {l, r, w};
    }

    sort(segments.begin(), segments.end(), [&](const array<int, 3> &a, const array<int, 3> &b) {
        return a[2] < b[2];
    });

    int l = 0, ans = 1e9;

    vector<segment> vals(M, segment(0));

    segment_tree tree(M);
    tree.build(vals);

    for(int r = 0; r < N; r++) {
        int ll = segments[r][0];
        int rr = segments[r][1];

        tree.update(ll, rr, segment_change(1));

        while(tree.query(1, M).sum > 0) {
            ans = min(ans, segments[r][2] - segments[l][2]);
            tree.update(segments[l][0], segments[l][1], segment_change(-1));
            l++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}