#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

struct segment_change {
    int64_t to_set;
    static const int64_t SENTINEL = -1;

    // Make sure that the default constructor is the identity segment_change
    segment_change(int64_t _to_set = SENTINEL) : to_set(_to_set) {}

    // resets to the SENTINEL value
    void reset() {
        to_set = SENTINEL;
    }

    bool has_change() const {
        return to_set != SENTINEL;
    }

    // Return the combined result of applying this segment change followed by the `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(other.to_set);
    }
};

struct segment {
    int64_t sum;

    // Make sure that the default constructor is the identity segment
    segment(int64_t _sum = 0) : sum(_sum) {}

    // checks if the current segment is empty based on the default value
    bool empty() const {
        return sum == 0;
    }

    // evaluating the change on a particular node
    void apply(int length, const segment_change &change) {
        if(change.has_change()) {
            sum = change.to_set;
        }
    }

    // merge function
    void join(const segment &other) {
        sum = sum + other.sum;
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

int64_t compute(int64_t A, int64_t P) {
    int64_t ans = 0;
    while(A > 0 && A % P == 0) {
        ans++;
        A /= P;
    }
    return ans;
}

void run_cases() {
    int64_t N, Q, P;

    cin >> N >> Q >> P;


    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;
    segment_tree divisible, normal, special, cnt_not_div;
    vector<segment> divisible_segments(N, segment(0));
    vector<segment> normal_segments(N, segment(0));
    vector<segment> special_segments(N, segment(0));
    vector<segment> cnt_not_div_segments(N, segment(0));
    for(int i = 0; i < N; i++) {
        if(A[i] % P == 0) {
            divisible_segments[i] = segment(compute(A[i], P));
        } else if(A[i] >= P) {
            cnt_not_div_segments[i] = segment(1);
            normal_segments[i] = segment(compute(A[i] - (A[i] % P), P));
            special_segments[i] = segment(compute(A[i] + (A[i] % P), P) - 1);
        }
    }
    divisible.build(divisible_segments);
    normal.build(normal_segments);
    special.build(special_segments);
    cnt_not_div.build(cnt_not_div_segments);

    while(Q--) {
        int ch;
        cin >> ch;
        if(ch == 1) {
            int64_t pos, val;
            cin >> pos >> val;
            --pos;
            if(val % P == 0) {
                divisible.update(pos, pos + 1, segment_change(compute(val, P)));
                cnt_not_div.update(pos, pos + 1, segment_change(0));
                normal.update(pos, pos + 1, segment_change(0));
                special.update(pos, pos + 1, segment_change(0));
            } else if(val >= P) {
                divisible.update(pos, pos + 1, segment_change(0));
                cnt_not_div.update(pos, pos + 1, segment_change(1));
                normal.update(pos, pos + 1, segment_change(compute(val - (val % P), P)));
                special.update(pos, pos + 1, segment_change(compute(val + (val % P), P) - 1));
            } else {
                divisible.update(pos, pos + 1, segment_change(0));
                cnt_not_div.update(pos, pos + 1, segment_change(0));
                normal.update(pos, pos + 1, segment_change(0));
                special.update(pos, pos + 1, segment_change(0));
            }
        } else {
            int64_t s, l, r;
            cin >> s >> l >> r;
            --l;
            int64_t Vs = compute(s, P);

            int64_t ans = divisible.query(l, r).sum * s;
            ans += Vs * cnt_not_div.query(l, r).sum;
            if(P == 2 && s % 2 == 0) {
                ans += special.query(l, r).sum;
            }
            ans += normal.query(l, r).sum;
            cout << ' ' << ans;
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ":";
        run_cases();
    }
}