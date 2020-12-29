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

vector<vector<pair<int,int>>> ans;

void add(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
	vector<pair<int,int>> tmp;
	tmp.push_back(a);
	tmp.push_back(b);
	tmp.push_back(c);
	ans.push_back(tmp);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		ans.clear();
		int n,m;
		cin >> n >> m;
		vector<vector<int>> a(n , vector<int>(m));
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				char ch;
				cin >> ch;

				a[i][j] = ch - '0';
			}
		}
		// debug() << imie(a);
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(a[i][j] == 1) {
					pair<int,int> pt1 = {i, j};
					pair<int,int> pt2, pt3, pt4;
					if(j + 1 < m and i + 1 < n) {
						pt2 = {i + 1, j};
						pt3 = {i + 1, j + 1};
						pt4 = {i, j + 1};
					}
					else if(i - 1 >= 0 and j - 1 >= 0) {
						pt2 = {i - 1, j};
						pt3 = {i - 1, j - 1};
						pt4 = {i, j - 1};
					}
					else if(i + 1 < n and j - 1 >= 0) {
						pt2 = {i + 1, j};
						pt3 = {i + 1, j - 1};
						pt4 = {i, j - 1};
					}
					else {
						pt2 = {i - 1, j};
						pt3 = {i - 1, j + 1};
						pt4 = {i, j + 1};
					}
					// debug() << imie(pt1) imie(pt2) imie(pt3) imie(pt4);
					add(pt1, pt2, pt3);
					add(pt1, pt3, pt4);
					add(pt1, pt4, pt2);
				}
			}
		}
		// assert((int)ans.size() <= 3 * n * m);
		debug() << imie((int)ans.size()) imie(3 * n * m);
		cout << ans.size() << '\n';
		for(auto u: ans) {
			for(auto v: u) {
				cout << v.first + 1 << " " << v.second + 1 << " ";
			}
			cout << '\n';
		}
	}
}