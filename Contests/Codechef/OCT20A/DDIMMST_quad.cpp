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

#define ll long long

long long calc(vector<long long> &a, vector<long long> &b) {
	long long res = 0;
	for(ll i=0;i<(ll)a.size();i++) {
		res += abs(a[i]-b[i]);
	}
	return res;
}

vector<ll> parent, rnk;

void make_set(ll v) {
    parent[v] = v;
    rnk[v] = 0;
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

struct Edge {
    ll u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n,d;
	cin >> n >> d;

	vector<vector<ll>> pts(n,vector<ll>(5,0));

	for(ll i=0;i<n;i++) {
		for(ll j=0;j<5;j++) {
			pts[i][j] = 0;
		}
	}

	for(ll i=0;i<n;i++) {
		for(ll j=0;j<d;j++) {
			cin >> pts[i][j];
		}
	}

	// find the central point of partition for each dimention

	vector<ll> central(5,0);
	for(ll i=0;i<n;i++) {
		for(ll j=0;j<5;j++) {
			central[j] += pts[i][j];
		}
	}

	for(ll i=0;i<5;i++) {
		central[i] /= n;
	}

	debug() << imie(central);

	vector<vector<ll>> quadrant(32, vector<ll>(5,0));
	vector<ll> qpt(32,-1);
	for(ll i=0;i<32;i++) {
		for(ll j=0;j<5;j++) {
			quadrant[i][j] = central[j];
		}
	}

	debug() << imie(quadrant);

	for(ll i=0;i<n;i++) {
		ll score = 0;
		for(ll j=0;j<5;j++) {
			if(pts[i][j] <= central[j]) {
				score += (1<<j);
			}
		}
		if(calc(quadrant[score], central) < calc(pts[i], central)) {
			qpt[score] = i;
			quadrant[score] = pts[i];
		}
	}

	vector<Edge> edges;

	for(ll i=0;i<n;i++) {
		for(ll j=0;j<32;j++) {
			if(qpt[j] != -1 and i != qpt[j]) {
				Edge tmp;
				tmp.u = i;
				tmp.v = qpt[j];
				tmp.weight = calc(pts[i], pts[qpt[j]]);
				edges.push_back(tmp);
			}
		}
	}


	

	ll cost = 0;
	// vector<Edge> result;
	parent.resize(n);
	rnk.resize(n);
	for (ll i = 0; i < n; i++)
	    make_set(i);

	sort(edges.rbegin(), edges.rend());

	for (Edge e : edges) {
	    if (find_set(e.u) != find_set(e.v)) {
	        cost += e.weight;
	        // result.push_back(e);
	        union_sets(e.u, e.v);
	    }
	}

	cout << cost << '\n';
}