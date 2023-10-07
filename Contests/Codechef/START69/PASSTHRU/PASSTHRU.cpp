#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query {
    int l, r, id, lca;
    int64_t ord;

    Query(): l(), r(), id(), lca() {}
    Query(int _l, int _r, int _id, int _lca): l(_l), r(_r), id(_id), lca(_lca), ord(gilbertOrder(l, r, 21, 0)) {}

    bool operator<(const Query& other) const {
        return ord < other.ord;
    }
};


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

void run_cases() {
    int N;
    cin >> N;

    vector<int> cnt(N);
    vector<int> cnt2(N);

    vector<int> A(N);
    for(auto &u: A) {
        cin >> u;
    }

    vector<int64_t> values(N);

    vector<pair<int, int>> pairs(N);
    for(int i = 0; i < N; ++i) {
        pairs[i] = {A[i], i};
    }
    sort(pairs.begin(), pairs.end());
    int nxt = 0;
    for(int i = 0; i < N; ++i) {
        if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
        values[nxt] = A[pairs[i].second];
        A[pairs[i].second] = nxt;
    }

    for(auto u: A) {
        cnt[u]++;
    }

    vector<vector<int>> adj(N);
    vector<int> in(N), out(N), euler;
    int timer = 0;
    vector<int> nodes(N);

    auto add_edge = [&](int u, int v) -> void {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    vector<pair<int,int>> edges;
    vector<int> depth(N);

    for(int i = 1; i < N; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        add_edge(x, y);
        edges.emplace_back(x, y);
    }

    function<void(int,int)> dfs = [&](int node, int par) -> void {
        in[node]=timer++;
        euler.push_back(node);
        for(int child: adj[node]) {
            if(child != par) {
                depth[child] = depth[node] + 1;
                dfs(child, node);
            }
        }
        out[node] = timer++;
        euler.push_back(-1);
    };

    dfs(0, -1);

    vector<Query> queries;
    vector<int64_t> answers(N);
    int64_t ans = 0;

    debug() << imie(euler);
    debug() << imie(in);
    debug() << imie(out);
    debug() << imie(values);

    for(int i = 0; i < N; i++) {
        queries.push_back(Query(in[i], out[i], i, -1));
    }

    auto add_number = [&](int index) -> void {
        cnt2[A[index]]++;
        if (cnt2[A[index]] == 1 && cnt2[A[index]] < cnt[A[index]]) {
            debug() << imie("add") imie(nodes) imie(index) imie(values[A[index]]);
            ans += values[A[index]];
        }

        if (cnt2[A[index]] == cnt[A[index]] && cnt2[A[index]] > 1) {
            debug() << imie("sub") imie(nodes) imie(index) imie(values[A[index]]);
            ans -= values[A[index]];
        }
    };

    auto remove_number = [&](int index) -> void {

        cnt2[A[index]]--;

        if (cnt2[A[index]] == 0 && cnt[A[index]] > 1) {
            debug() << imie("remove") imie(nodes) imie(index) imie(values[A[index]]);
            ans -= values[A[index]];
        }

        if (cnt2[A[index]] > 0 && cnt[A[index]] - 1 == cnt2[A[index]]) {
            ans += values[A[index]];
        }
    };

    auto check = [&](int node) -> void {
        if(node == -1) {
            return;
        }

        if(nodes[node]) {
            remove_number(node);
            nodes[node]--;
        } else {
            add_number(node);
            nodes[node]++;
        }
    };

    auto solve = [&](int index) -> void {
        ans = 0;
        nodes.assign(N, 0);
        int globalL = queries[index].l, globalR = queries[index].l - 1;

        for(auto &query: queries) {
            debug() << imie(query.l) imie(query.r);
            while(query.l < globalL) {
                globalL--;
                check(euler[globalL]);
            }

            while(query.l > globalL) {
                check(euler[globalL]);
                globalL++;
            }

            while(query.r < globalR) {
                check(euler[globalR]);
                globalR--;
            }

            while(query.r > globalR) {
                globalR++;
                check(euler[globalR]);
            }

            debug() << imie(ans);

            answers[query.id] = ans;
        }
    };

    sort(queries.begin(), queries.end());
    solve(0);

    for(auto [u, v]: edges) {
        if (depth[u] > depth[v]) {
            cout << answers[u] << " ";
        } else {
            cout << answers[v] << " ";
        }
    }

    cout << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}