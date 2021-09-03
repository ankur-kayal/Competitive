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

const int inf = 1e9;

void run_cases() {
    int N, K;
    cin >> N >> K;

    vector<int64_t> C(N);
    for(auto &u: C)
        cin >> u;

    vector<vector<int>> adj(N);

    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    multiset<int64_t> order;

    int root = 0;

    auto dfs = y_combinator([&](auto dfs, int node, int par) -> void {
        if(adj[node].size() == 1 && node != root) {
            order.insert(C[node]);
            return;
        }


        int64_t max_child_gold = -1;
        for(int child: adj[node]) {
            if(child != par) {
                dfs(child, node);
                max_child_gold = max(max_child_gold, C[child]);
            }
        }

        if(node != root) {
            C[node] += max_child_gold;
            order.erase(order.find(max_child_gold));
            order.insert(C[node]);
        }

    });

    dfs(root, -1);

    debug() << imie(order);
    debug() << imie(C);

    int64_t ans = C[root];

    vector<pair<int64_t, int64_t>> pq;
    for(auto u: adj[root]) {
        pq.emplace_back(C[u], -1);
        order.erase(order.find(C[u]));
    }
    for(auto u: order) {
        pq.emplace_back(u, -2);
    }

    sort(pq.rbegin(), pq.rend());

    debug() << imie(pq);

    int connected_to_one = 0;

    bool first = true;

    for(auto [weight, cost]: pq) {
        cost = -cost;
        if(connected_to_one >= 2) {
            cost = min(int64_t(2), cost + 1);
        }
        if(cost == 1) {
            connected_to_one++;
        }
        debug() << imie(K) imie(cost) imie(connected_to_one);
        if(!first) {
            K++;
        }
        if(K - cost < 0) {
            break;
        }
        K -= cost;
        first = false;
        ans += weight;

    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("c2_validation_input.txt", "r", stdin);
    // freopen("c2_validation_output.txt", "w", stdout);

    /*For final submit*/
    // freopen("c2_final_input.txt", "r", stdin);
    // freopen("c2_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}