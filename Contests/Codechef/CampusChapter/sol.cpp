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

vector<vector<int>> adj;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin >> n >> m;
    adj = vector<vector<int>>(n, vector<int>());

    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // vector<vector<int>> score(n);
    vector<int64_t> score(n,1);
    for(int i=0;i<n;i++) {
        for(auto u: adj[i]) {
            if(u > i) {
                score[u] = max(score[u], score[i] + 1);
            }
        }
    }

    int64_t ans = -1;
    for(int i=0;i<n;i++) {
        ans = max(ans, score[i] * int(adj[i].size()));
    }
    cout << ans << '\n';
}