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

void run_cases() {
    int N, K;
    cin >> N >> K;

    vector<int> friends_room(K);
    for(auto &u: friends_room) {
        cin >> u;
        u--;
    }

    vector<vector<int>> adj(N);

    for(int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> possible_endpoints;

    for(int i = 0; i < N; i++) {
        if(adj[i].size() == 1) {
            possible_endpoints.push_back(i);
        }
    }

    vector<int> friends_distance(N, N + 100);
    vector<int> q;
    for(auto u: friends_room) {
        friends_distance[u] = 0;
        q.push_back(u);
    }


    for(int i = 0; i < q.size(); i++) {
        int x = q[i];
        for(auto u: adj[x]) {
            if(friends_distance[u] == N + 100) {
                friends_distance[u] = friends_distance[x] + 1;
                q.push_back(u);
            }
        }
    }

    vector<int> vlad_distance(N, N + 100);
    q.clear();
    q.push_back(0);
    vlad_distance[0] = 0;

    for(int i = 0; i < q.size(); i++) {
        int x = q[i];
        for(auto u: adj[x]) {
            if(vlad_distance[u] == N + 100) {
                vlad_distance[u] = vlad_distance[x] + 1;
                q.push_back(u);
            }
        }
    }

    debug() << imie(friends_distance) << '\n' << imie(vlad_distance);

    debug() << imie(possible_endpoints);

    for(auto u: possible_endpoints) {
        if(u == 0) {
            continue;
        }

        if(vlad_distance[u] < friends_distance[u]) {
            cout << -1 << '\n';
            return;
        }
    }

    vector<int> subtree_friends(N, 0);
    vector<int> parent(N, -1);

    function<void(int,int)> dfs = [&](int node, int par) {
        debug() << imie(node) imie(par);
        parent[node] = par;
        for(int child: adj[node]) {
            if(child != par) {
                dfs(child, node);
                subtree_friends[node] += subtree_friends[child];
            }
        }

        if(friends_distance[node] == 0) {
            subtree_friends[node]++;
        }
    };

    dfs(0, -1);

    int ans = K;

    q = {0};
    for(int i = 0; i < q.size(); i++) {
        int x = q[i];
        for(int child: adj[x]) {
            if(child == parent[x]) {
                continue;
            }
            debug() << imie(child) imie(vlad_distance[child]) imie(friends_distance[child]);
            if(vlad_distance[child] >= friends_distance[child]) {
                ans -= (subtree_friends[child] - 1);
            } else {
                q.push_back(child);
            }
        }
        debug() << imie(q);
    }

    debug() << imie(q);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}