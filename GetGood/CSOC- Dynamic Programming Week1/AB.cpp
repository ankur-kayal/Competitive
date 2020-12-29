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

	string s;
	cin >> s;
	int n = s.length();
	vector<long long> dp(n+1);
	dp[0] = dp[1] = 1;

	int mod = 1e9 + 7;
	int cnt = 0;

	bool ok = 1;

	for(int i=0;i<n;i++) {
		if(s[i] == 'm' or s[i] == 'w') {
			ok = 0;
		}
	}

	if(ok) {
		for(int i=1;i<=n;i++) {
			if(i > 1) {
				if(s[i-1] == s[i-2] and (s[i-1] == 'u' or s[i-1] == 'n')) {
					dp[i] = (dp[i-1] + dp[i-2])%mod;
				}
				else {
					dp[i] = dp[i-1];
				}
			}
		}
		cout << dp[n] << '\n';
	}
	else {
		cout << 0 << '\n';
	}
}