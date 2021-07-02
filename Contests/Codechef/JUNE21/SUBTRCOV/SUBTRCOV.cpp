#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


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
    int N, K;
    cin >> N >> K;
    vector<vector<int>> adj(N);
    for(int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> depth(N);

    // find diameter endpoint which will always be included
    auto find_endpoint = y_combinator([&](auto find_endpoint, int node, int par) -> void {
        for(int child: adj[node]) {
            if(child != par) {
                depth[child] = depth[node] + 1;
                find_endpoint(child, node);
            }
        }
    });

    find_endpoint(0, -1);

    int max_depth = *max_element(depth.begin(), depth.end());
    int root = find(depth.begin(), depth.end(), max_depth) - depth.begin();

    multiset<int> order;
    vector<int> dists(N);

    auto dfs = y_combinator([&](auto dfs, int node, int par) -> void {
        if(adj[node].size() == 1 && node != root) {
            dists[node] = 1;
            order.insert(1);
            return;
        }

        int max_child_dist = -1;
        for(int child: adj[node]) {
            if(child != par) {
                dfs(child, node);
                max_child_dist = max(max_child_dist, dists[child]);
            }
        }

        if(node != root) {
            dists[node] = max_child_dist + 1;
            order.erase(order.find(max_child_dist));
            order.insert(dists[node]);
        }
    });

    dfs(root, -1);

    debug() << imie(order);

    int index = 0;
    vector<int> vals(order.rbegin(), order.rend());
    int nodes = 1;
    while(K > 1) {
        K -= vals[index++];
        nodes++;
    }

    cout << nodes << '\n';
}   

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}