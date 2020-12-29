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

	const int MOD = 1e9 + 7;

	int n,m;
	cin >> n >> m;
	vector<vector<long long>> dp(n+1, vector<long long>(m+1,0));
	vector<long long> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}

	// dp[i][v] = number of possibilities with value v at index i
	if(a[0] == 0) {
		for(int i = 1;i<=m;i++) {
			dp[0][i] = 1;
		}
	}
	else {
		dp[0][a[0]] = 1;
	}
	for(int i=1;i<n;i++) {
		if(a[i] == 0) {
			for(int v=1;v<=m;v++) {
				dp[i][v] = (dp[i][v] + dp[i-1][v]) % MOD;
				if(v-1>=1) {
					dp[i][v] = (dp[i][v] + dp[i-1][v-1]) % MOD;
				}
				if(v+1 <= m) {
					dp[i][v] = (dp[i][v] + dp[i-1][v + 1]) % MOD;
				}
			}
		}
		else {
			int v = a[i];
			dp[i][v] = (dp[i][v] + dp[i-1][v]) % MOD;
			if(v-1>=1) {
				dp[i][v] = (dp[i][v] + dp[i-1][v-1]) % MOD;
			}
			if(v+1 <= m) {
				dp[i][v] = (dp[i][v] + dp[i-1][v + 1]) % MOD;
			}
		}
	}
	long long ans = 0;
	if(a[n-1] == 0) {
		for(int i=1;i<=m;i++) {
			ans = (ans + dp[n-1][i]) % MOD;
		}
	}
	else {
		ans = dp[n-1][a[n-1]];
	}

	cout << ans << '\n';
}