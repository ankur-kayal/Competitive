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
int maxN;
vector<int> a;

void upd(int i, int delta) {
	while(i < maxN) {
		a[i] += delta;
		i += (i & -i);
	}
}


int sum(int i) {
	int cnt = 0;
	while(i > 0) {
		cnt += a[i];
		i -= (i & -i);
	}

	return cnt;
}

void qry(int k) {
	int l = 0, r = maxN;

	while(r > l + 1) {
		int m = (r + l) / 2;
		if(k <= sum(m)) {
			r = m;
		}
		else {
			l = m;
		}
	}
	upd(r, -1);
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,q;
	cin >> n >> q;
	maxN = n + 5;
	a.assign(maxN, 0);
	for(int i=0;i<n;i++) {
		int f;
		cin >> f;
		upd(f, 1);
	}
	while(q--) {
		int k;
		cin >> k;
		if(k < 0) {
			k = abs(k);
			qry(k);
		}
		else {
			upd(k, 1);
		}
	}

	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(sum(i) >= 1) {
			ans = i;
			break;
		}
	}

	cout << ans << '\n';
}