// problem link -> https://codeforces.com/problemset/problem/698/A

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

	int n;
	cin >> n;
	vector<int> a(n+1);
	vector<vector<int>> dp(n+1,vector<int>(3,0));
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	debug() << imie(a);
	cerr << '\n';

	for(int i=1;i<=n;i++) {
		dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
		if(a[i] == 1 or a[i] == 3){
			dp[i][1] = max({dp[i-1][0] + 1, dp[i-1][2] + 1});
		}
		if(a[i] == 2 or a[i] == 3) {
			dp[i][2] = max({dp[i-1][0] + 1, dp[i-1][1] + 1});
		}
	}
	debug() << imie(a);
	cerr << '\n';
	debug() << imie(dp);
	cout << n - max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
}