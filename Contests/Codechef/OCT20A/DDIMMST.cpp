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
const long long inf = 1e15;

struct Edge {
    long long w = inf, to = -1;
};

long long calc(vector<long long> &a, vector<long long> &b) {
	long long res = 0;
	for(int i=0;i<(int)a.size();i++) {
		res += abs(a[i]-b[i]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long n,d;
	cin >> n >> d;
	vector<vector<long long>> pts(n+1, vector<long long>(d,0));
	for(int i=1;i<=n;i++) {
		for(int j=0;j<d;j++) {
			cin >> pts[i][j];
		}
	}

	vector<vector<long long>> adj(n+1,vector<long long>(n+1,inf));

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(i != j) {
				adj[i][j] = -1LL * calc(pts[i], pts[j]);
			}
		}
	}

	long long total_weight = 0;
    vector<bool> selected(n+1, false);
    vector<Edge> min_e(n+1);
    min_e[1].w = 0;

    for (int i=1; i<=n; ++i) {
        int v = -1;
        for (int j = 1; j <= n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        selected[v] = true;
        total_weight += min_e[v].w;

        for (int to = 1; to <= n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    cout << -1LL * total_weight << '\n';


}