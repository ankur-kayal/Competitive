#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize ("trapv")

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define nl '\n'

//----------------------------------- END DEFINES --------------------------------
vector<vector<int>> adj, levels;
vector<int> p, children, renumber;
vector<int64_t> factor;

void dfs(int node, int depth) {
    levels[depth].push_back(node);
    factor[node] = 1;
    int64_t LCM = 1;
    int one_child;
    // vector<int64_t> child_factors;
    for(int child : adj[node]) {
        if(child != p[node]) {
            one_child = child;
            dfs(child, depth + 1);
            // child_factors.push_back(factor[child]);
        }
    }

    if(children[node] == 1) {
        renumber[node] = renumber[one_child];
    }
    // int64_t HCF = 1;
    // for(auto u: child_factors) {
    //     HCF = gcd(HCF, u);
    // }
    // for(auto u: child_factors) {
    //     factor[node] *= u / HCF;
    // }
    // factor[node] = max(1LL, factor[node] * children[node]);
} 

void run_cases() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1, vector<int>());
    levels = vector<vector<int>>(n + 1, vector<int>());
    p = vector<int>(n + 1);
    renumber = vector<int>(n + 1);
    children = vector<int>(n + 1);
    factor = vector<int64_t>(n + 1);
    for(int i=2;i<=n;i++) {
        cin >> p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
        children[p[i]]++;
    }

    for(int i=1;i<=n;i++) {
        renumber[i] = i;
    }

    dfs(1, 1);

    vector<vector<pair<int64_t, int64_t>>> tasks(n + 1, vector<pair<int64_t, int64_t>>());
    int Q;
    cin >> Q;
    vector<int64_t> ans(Q + 1, 0);
    for(int i=1;i<=Q;i++) {
        int v, W;
        cin >> v >> W;
        bool ok = true;
        if(children[renumber[v]] != 0) ok = true;
        else if(W % children[renumber[v]] != 0)
            ok = false;

        if(ok)
            tasks[renumber[v]].push_back({i, W});
        else ans[i] += W;
    }

    

    while(levels.back().empty()) {
        levels.pop_back();
    }

    debug() << imie(tasks);
    // return;

    for(auto level: levels) {
        if(!level.empty())
        for(auto old_node: level) {
            int node = renumber[old_node];
            // int node = old_node;
            debug() << imie(level) imie(old_node) imie(renumber[old_node]);
            while(!tasks[node].empty()) {
                auto current_task = tasks[node].back();
                tasks[node].pop_back();
                int64_t W = current_task.second;
                int64_t index = current_task.first;
                if(children[node] == 0) continue;
                if(W % children[node] == 0) {
                    for(auto child: adj[node]) {

                        if(child != p[node]) {
                            tasks[renumber[child]].push_back({index, W / children[node]});
                        }
                    }
                }
                else {
                    debug() << imie(node) imie(children[node]) imie(W);
                    ans[index] += W;
                }
            }
            debug() << imie(tasks);
        }
    }

    for(int i=1;i<=Q;i++) {
        cout << ans[i] << nl;
    }

    debug() << imie(levels);

    debug() << imie(renumber);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}