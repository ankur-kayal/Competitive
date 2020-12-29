#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

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

#define int int64_t
vector<vector<int>> adj;
vector<int> level, vis, cycle, subTree;
stack<int> order;

void dfs(int node, int par) {
    vis[node] = 1;
    order.push(node);
    if((int)cycle.size() > 0) {
        return;
    }
    for(int child: adj[node]) {
        if((int)cycle.size() > 0) {
            return;
        }
        if(child != par) {
            if(vis[child] == 1) {
                // cerr << child << " " << node << " " << vis[child]  << " " << order.size() << '\n';
                while(!order.empty()) {
                    cycle.push_back(order.top());
                    if(order.top() == child) {
                        break;
                    }
                    order.pop();
                }
                return;
            }
            else {
                dfs(child, node);
            }
        }
    }
    if(!order.empty()) {
        order.pop();
    }
}

void count_subtree(int node) {
    vis[node] = 1;
    subTree[node] = 1;
    for(int child: adj[node]) {
        if(vis[child] == 0) {
            count_subtree(child);
            subTree[node] += subTree[child];
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        adj = vector<vector<int>>(n, vector<int>());
        vis = vector<int>(n, 0);
        subTree = vector<int>(n, 0);
        cycle.clear();
        while(!order.empty()) {
            order.pop();
        }
        int64_t ans = n * (n - 1);
        for(int i=0;i<n;i++) {
            int u,v;
            cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);
        // debug() << imie(cycle);
        vis.assign(n, 0);
        for(int u: cycle) {
            vis[u] = 1;
        }
        for(int u: cycle) {
            count_subtree(u);
            ans -= subTree[u] * (subTree[u] - 1) / 2;
        }
        cout << ans << '\n';
    }
}