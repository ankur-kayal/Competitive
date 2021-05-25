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
    static const int64_t SENTINEL = 1e9;

    // Make sure that the default constructor is the identity segment
    segment(int64_t _sum = SENTINEL) : sum(_sum) {}

    // checks if the current segment is empty based on the default value
    bool empty() const {
        return sum == SENTINEL;
    }

    // evaluating the change on a particular node
    void apply(int length, const segment_change &change) {
        if(change.has_change()) {
            sum = sum + change.to_add;
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

static const int64_t INF = 1e9;

void run_cases() {
    int N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    int64_t dp[101][35001];
    for(int i=0;i<=K;i++) {
        for(int j=0;j<=N;j++) {
            dp[i][j] = INF;
        }
    }

    segment_tree tree;
    dp[0][0] = 0;
    
    auto init_and_build_tree = [&](int k) -> void {
        tree.init(N + 1);
        vector<segment> segments(N + 1);
        for(int i=0;i<=N;i++) {
            segments[i] = segment(dp[k][i]);
        }
        tree.build(segments);
    };

    init_and_build_tree(0);

    for(int i=1;i<=K;i++) {
        vector<int> last(N + 1, -1);
        dp[i][0] = 0;
        for(int j=1;j<=N;j++) {
            if(last[A[j - 1]] == -1) {
                last[A[j - 1]] = j;
            } else {
                tree.update(0, last[A[j - 1]], segment_change(j - last[A[j - 1]]));
                last[A[j - 1]] = j;
            }
            dp[i][j] = tree.query(0, j).sum;
        }
        init_and_build_tree(i);
    }

    cout << dp[K][N];

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}