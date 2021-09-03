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

const int inf = 1e9;

void run_cases() {
    int N;
    cin >> N;

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
    vector<int64_t> branches;

    function<int64_t(int, int)> dfs = [&](int node, int par) -> int64_t {
        if(par != -1) {
            C[node] += C[par];
        }
        int64_t max_gold = C[node];
        for(int child: adj[node]) {
            if(child != par) {
                int64_t got = dfs(child, node);
                max_gold = max(max_gold, got);
                if(node == 0) {
                    branches.push_back(got);
                }
            }
        }
        return max_gold;
    };

    dfs(0, -1);

    sort(branches.rbegin(), branches.rend());

    if(branches.size() == 0) {
        cout << C[0] << '\n';
    }
    else if(branches.size() == 1) {
        cout << branches.front() << '\n';
    } else {
        cout << branches[0] + branches[1] - C[0] << '\n';
    }

    // debug() << imie(branches);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("c1_validation_input.txt", "r", stdin);
    // freopen("c1_validation_output.txt", "w", stdout);

    /*For final submit*/
    // freopen("c1_final_input.txt", "r", stdin);
    // freopen("c1_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}