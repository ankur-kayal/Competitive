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

ll cost(ll num, ll part) {
	ll s1 = num / part;
	ll rem = num%part;
	return (part-rem)*s1*s1 + rem*(s1+1)*(s1+1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,k;
	cin >> n >> k;
	vector<long long> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}

	ll ans = 0;
	for(int i=0;i<n;i++) {
		ans += a[i]*a[i];
	}
	vector<ll> b(n,1);

	priority_queue<pair<ll,ll>> p;
	for(int i=0;i<n;i++) {
		ll score = cost(a[i],1) - cost(a[i],2);
		p.push(make_pair(score, i));
	}

	for(int i=0;i<k-n;i++) {
		pair<ll,ll> x = p.top();
		p.pop();
		ans -= x.first;
		b[x.second]++;
		ll score = cost(a[x.second],b[x.second]) - cost(a[x.second],b[x.second]+1);
		p.push({score, x.second});
	}
	cout << ans << '\n';
}