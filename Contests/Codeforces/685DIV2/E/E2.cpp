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

int AND(int i, int j) {
	cout << "AND " << i << " " << j << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

int OR(int i, int j) {
	cout << "OR " << i << " " << j << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

int XOR(int i, int j) {
	cout << "XOR " << i << " " << j << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	map<int,int> cnt;
	int mx = 1;
	for(int i=2;i<=n;i++) {
		a[i] = XOR(1, i);
		cnt[a[i]]++;
		mx = max(mx, cnt[a[i]]);
	}
	debug() << imie(cnt);
	if((int)cnt.size() == n - 1) {
		int index = -1;
		for(int i=2;i<=n;i++) {
			if(a[i] == n - 1) {
				index = i;
				break;
			}
		}
		int index2 = index == n ? n - 1 : n;
		int X12 = a[index2];
		int X13 = a[index];
		int X23 = X12 ^ X13;
		int A12 = AND(1, index2);
		int A23 = AND(index2, index);
		int A13 = 0;

		int p = X12 + 2 * A12;
		int q = X23 + 2 * A23;
		int r = X13 + 2 * A13;
		debug() << imie(p) imie(q) imie(r);

		a[1] = (p - q + r) / 2;
	}
	else {
		vector<int> ind;
		int val = -1;
		for(auto u: cnt) {
			if(u.second == mx) {
				val = u.first;
				break;
			}
		}
		for(int i=2;i<=n;i++) {
			if(a[i] == val) {
				ind.push_back(i);
			}
		}

		assert((int)ind.size() >= 2);
		int ans = AND(ind[0], ind[1]);
		a[1] = a[ind[0]] ^ ans;
	}	

	for(int i=2;i<=n;i++) {
		a[i] = a[i] ^ a[1];
	}
	cout << "! ";
	for(int i=1;i<=n;i++) {
		// assert(a[i] <= n -1);
		cout << a[i] << " ";
	}
}