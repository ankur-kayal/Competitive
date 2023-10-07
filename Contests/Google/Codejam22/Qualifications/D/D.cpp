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

void run_cases() {
    int N;
    cin >> N;

    vector<int64_t> fun(N);
    for(auto &u: fun) {
        cin >> u;
    }

    vector<int> P(N);
    for(auto &u: P) {
        cin >> u;
        u--;
    }

    vector<vector<int>> adj(N);

    vector<int> roots;
    for(int i = 0; i < N; i++) {
        if(P[i] == -1) {
            roots.push_back(i);
        } else {
            adj[i].push_back(P[i]);
            adj[P[i]].push_back(i);
        }
    }

    int64_t score = 0;

    function<void(int,int)> dfs = [&](int node, int par) -> void{
        vector<int64_t> funs;
        for(int child: adj[node]) {
            if(child != par) {
                dfs(child, node);

                funs.push_back(fun[child]);
            }
        }

        sort(funs.begin(), funs.end());
        for(int i = 1; i < funs.size(); i++) {
            score += funs[i];
        }

        if(!funs.empty())
            fun[node] = max(fun[node], funs[0]);
    };

    for(auto u: roots) {
        dfs(u, -1);
        score += fun[u];
    }

    cout << score << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}