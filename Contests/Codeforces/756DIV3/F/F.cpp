#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

struct segment_change {
    int64_t to_set;
    static const int64_t SENTINEL = 0;

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
        return segment_change(to_set + other.to_set);
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
            sum = sum + change.to_set;
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
    int N, S;
    cin >> N >> S;

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    segment_tree tree;

    tree.init(N + 100);

    for(int i = 0; i < N; i++) {
        tree.update(i, N, segment_change(A[i]));
    }

    vector<int> ans = {0, N + 100, N + 100}; // ans, l, r

    for(int i = 0; i < N; i++) {
        int l = i - 1, r = N;
        while(r > l + 1) {
            int m = (l + r) / 2;
            debug() << imie(i) imie(m) imie(tree.query(i, m + 1).sum);
            if(S + tree.query(i, m + 1).sum >= 0) {
                l = m;
            } else {
                r = m;
            }
        }

        if(l >= i) {
            debug() << imie(i) imie(l);
            ans = max(ans, {l - i + 1, i + 1, l + 1});
        }

        tree.update(i, N, segment_change(-A[i]));
    }

    if(ans[0] == 0) {
        cout << -1 << '\n';
    } else {
        cout << ans[1] << " " << ans[2] << '\n';
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