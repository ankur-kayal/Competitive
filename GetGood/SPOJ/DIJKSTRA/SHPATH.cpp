#include <bits/stdc++.h>
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

//----------------------------------- END DEFINES -------------------------------- 

void run_cases() {
    int n;
    cin >> n;
    map<string, int> id; 
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        id[s] = i;
        int neighbours;
        cin >> neighbours;
        for(int j=0;j<neighbours;j++) {
            int u = i;
            int v, cost;
            cin >> v >> cost;
            --v;
            adj[u].emplace_back(v, cost);
            adj[v].emplace_back(u, cost);
        }
    }

    // debug() << imie(adj);
    // return;
    int queries;
    cin >> queries;
    const int inf = 1e9 + 7;
    vector<int> d, p;
    while(queries--) {
        string source, dest;
        cin >> source >> dest;
        int s = id[source];
        int f = id[dest];

        d.assign(n, inf);
        p.assign(n, inf);

        d[s] = 0;
        set<pair<int,int>> pq;
        pq.insert({0, s});

        while(!pq.empty()) {
            int v = pq.begin()->second;
            pq.erase(pq.begin());

            for(auto edge: adj[v]) {
                int to = edge.first;
                int len = edge.second;


                if(d[v] + len < d[to]) {
                    pq.erase({d[to], to});
                    d[to] = d[v] + len;
                    p[to] = v;
                    pq.insert({d[to], to});
                }
            }
            // if(v == f) {
            //     break;
            // }
        }

        cout << d[f] << '\n';
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