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

long long cost;

void calculate(ll xstart, ll ystart, ll xend, ll yend, ll tmpcost, ll recursionLimit) {
	if(xstart == xend and ystart == yend) {
		cost = min(cost, tmpcost);
		return;
	}
	if(recursionLimit >= 10) {
		return;
	}
	// go east 
	calculate(xstart + 2 * ystart, ystart, xend, yend, tmpcost + 1, recursionLimit + 1);

	// go west
	calculate(xstart - 2 * ystart, ystart, xend, yend, tmpcost + 1, recursionLimit + 1);

	// go north
	if(ystart + 2 * xstart > 0) {
		calculate(xstart, ystart + 2 * xstart, xend, yend, tmpcost + 1, recursionLimit + 1);
	}
	else {
		calculate(-1LL * xstart, -1LL * (ystart + 2 * xstart), xend, yend, tmpcost + 1, recursionLimit + 1);
	}

	// go south
	if(ystart - 2 * xstart > 0) {
		calculate(xstart, ystart - 2 * xstart, xend, yend, tmpcost + 1, recursionLimit + 1);
	}
	else {
		calculate(-1LL * xstart, -1LL * (ystart - 2 * xstart), xend, yend, tmpcost + 1, recursionLimit + 1);
	}
}

void subtask2(pair<ll,ll> p1, pair<ll,ll> p2) {
	cost = 1e18;
	calculate(p1.first, p1.second, p2.first, p2.second, 0LL, 0);
	cout << cost << '\n';
}

vector<vector<ll>> dp(1000, vector<ll>(1000,1000000));
map<pair<ll,ll>,ll> store;

void init() {

	ll marker = 1;
	ll lim = 13;
	for(ll i=-lim;i<=lim;i+=2) {
		for(ll j=1;j<=lim;j+=2) {
			if(__gcd(abs(i),j) == 1) {
				store[{i,j}] = marker;
				marker++;
			}
		}
	}

	for(auto u: store) {
		pair<ll,ll> pt = u.first;
		ll x = pt.first;
		ll y = pt.second;
		dp[u.second][u.second] = 0;

		pair<ll,ll> north, south, east, west;

		east = make_pair(x + 2 * y, y);
		west = make_pair(x - 2 * y, y);
		if(y + 2 * x > 0) {
			north = make_pair(x , y + 2 * x);
		}
		else {
			north = make_pair(-1LL * x, -1LL * (y + 2 * x));
		}
		if(y - 2 * x > 0) {
			south = make_pair(x , y - 2 * x);
		}
		else {
			south = make_pair(-1LL * x, -1LL * (y - 2 * x));
		}

		if(store.count(east)) {
			dp[store[pt]][store[east]] = 1;
			dp[store[east]][store[pt]] = 1;
		}

		if(store.count(west)) {
			dp[store[pt]][store[west]] = 1;
			dp[store[west]][store[pt]] = 1;
		}

		if(store.count(north)) {
			dp[store[pt]][store[north]] = 1;
			dp[store[north]][store[pt]] = 1;
		}

		if(store.count(south)) {
			dp[store[pt]][store[south]] = 1;
			dp[store[south]][store[pt]] = 1;
		}
	}

	ll maxN = store.size();
	debug() << store.size();
	for(ll k=1;k<=maxN;k++) {
		for(ll i=1;i<=maxN;i++) {
			for(ll j=1;j<=maxN;j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	// for(int i=1;i<=82;i++) {
	// 	for(int j=1;j<=82;j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }
}

void subtask1(pair<ll,ll> p1, pair<ll,ll> p2) {
	ll a1 = store[p1];
	ll a2 = store[p2];
	debug() << imie(a1) imie(a2);
	assert(dp[a1][a2] == dp[a2][a1]);
	cout << dp[a1][a2] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	init();
	ll t;
	cin >> t;
	while(t--) {
		ll xstart, ystart, xend, yend;
		cin >> xstart >> ystart >> xend >> yend;

		if(max({xstart, ystart, xend, yend}) < 10) {
			subtask1(make_pair(xstart, ystart), make_pair(xend, yend));
		}
		else {
			subtask2(make_pair(xstart, ystart), make_pair(xend, yend));
		}
	}

	debug() << imie(clock());
}