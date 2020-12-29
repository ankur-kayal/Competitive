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
void NO() {
	cout << "Impossible" << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin >> n >> m;
	vector<vector<int>> a(n,vector<int>(m));
	vector<vector<int>> b(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> a[i][j];
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> b[i][j];
		}
	}

	

	// transforming rows
	// making every element of b[i][j] greater than a[i][j]
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(a[i][j] <= b[i][j]) {
				swap(a[i][j],b[i][j]);
			}
		}
	}	
	debug() << imie(a) imie(b);

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(j-1 >= 0 and a[i][j] <= a[i][j-1]) {
				debug() << imie(i) imie(j);
				NO();
			}
			if(i-1 >= 0 and a[i][j] <= a[i-1][j]) {
				debug() << imie(i) imie(j);
				NO();
			}
			if(j-1 >= 0 and b[i][j] <= b[i][j-1]) {
				debug() << imie(i) imie(j);
				NO();
			}
			if(i-1 >= 0 and b[i][j] <= b[i-1][j]) {
				debug() << imie(i) imie(j);
				NO();
			}
		}
	}
	cout << "Possible" << '\n';

}