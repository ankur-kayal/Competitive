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
	vector<long long> c(n);
	for(int i=0;i<n;i++) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	const int mod = 1e9+7;
	// vector<vector<int>>dp(n+1,vector<int>(x+1,0));

	// dp[0][0] = 1;

	vector<int> dp(x+1,0);
	dp[0] = 1;

	for(int i=0;i<n;i++) {
		for(int j=1;j<=x;j++) {
			if(j-c[i] >= 0) {
				dp[j] = (dp[j] + dp[j-c[i]]) % mod;
			}
		}
	}
	cout << dp[x] << '\n';
}