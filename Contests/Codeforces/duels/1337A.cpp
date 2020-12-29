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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> a[i][j];
		}
	}

	// debug() << imie(a);

	vector<vector<int>> rows, cols;
	rows.resize(n);
	cols.resize(m);

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			rows[i].push_back(a[i][j]);
		}
		sort(rows[i].begin(), rows[i].end());
		auto it = unique(rows[i].begin(), rows[i].end());
		rows[i].resize(distance(rows[i].begin(), it));
	}

	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cols[i].push_back(a[j][i]);
		}
		sort(cols[i].begin(), cols[i].end());
		auto it = unique(cols[i].begin(), cols[i].end());
		cols[i].resize(distance(cols[i].begin(), it));
	}

	debug() << imie(rows);
	debug() << imie(cols);

	vector<vector<int>> ans(n, vector<int>(m,0));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			debug() << imie(i) imie(j);
			int ele = a[i][j];
			int lr = lower_bound(rows[i].begin(), rows[i].end(), ele) - rows[i].begin();
			int gr = (int)rows[i].size() - lr - 1;

			int lc = lower_bound(cols[j].begin(), cols[j].end(), ele) - cols[j].begin();
			int gc = (int)cols[j].size() - lc - 1;

			ans[i][j] = max(lr,lc) + max(gr, gc) + 1;
			debug() << imie(lr) imie(gr) imie(lc) imie(gc);

		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
}