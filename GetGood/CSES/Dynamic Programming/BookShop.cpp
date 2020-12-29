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

	int n,x;
	cin >> n >> x;

	vector<vector<int>> dp(n+1, vector<int>(x+1,0));

	vector<int> price(n), pages(n);
	for(int i=0;i<n;i++) {
		cin >> price[i];
	}
	for(int i=0;i<n;i++) {
		cin >> pages[i];
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=x;j++) {
			if(j-price[i-1] >= 0) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i-1]] + pages[i-1]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	// for(int i=0;i<=n;i++) {
	// 	debug() << imie(dp[i]);
	// }

	cout << dp[n][x] << '\n';
}