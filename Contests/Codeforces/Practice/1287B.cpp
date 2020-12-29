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

	int n,k;
	cin >> n >> k;
	map<string, int> cnt;
	vector<string> a(n);
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		a[i] = s;
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			string cur = "";
 
			for (int l = 0 ; l < k ; l++) {
				if (a[i][l] == a[j][l]) {
				  	cur += a[i][l];
				} 
				else {
				  	if ('S' != a[i][l] && 'S' != a[j][l]) {
				    	cur += 'S';
				  	}         
				  	if ('E' != a[i][l] && 'E' != a[j][l]) {
				    	cur += 'E';
				  	}
				  	if ('T' != a[i][l] && 'T' != a[j][l]) {
				    	cur += 'T';
				  	}
				}
			}

			if (cnt.count(cur)) {
			ans += cnt[cur];
			}
		}
		cnt[a[i]]++;
	}
	cout << ans << '\n';
}