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

const int mSum = 1e5;
const int maxN = 100;

vector<vector<int>> dp(maxN + 1, vector<int>(mSum + 1, 0));

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	set<int> ans;
	int n;
	cin >> n;
	dp[0][0] = 1;
	vector<int> vals(n + 1);
	for(int i=1;i<=n;i++) {
		cin >> vals[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=mSum;j++) {
			if(vals[i] > j) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				if(dp[i - 1][j - vals[i]] == 1) {
					dp[i][j] = 1;
					ans.insert(j);
				}
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		// debug() << imie(i) << imie(ans);
	}
	// for(auto u: dp) {
	// 	debug() << imie(u);
	// }
	// debug() << imie(ans);
	cout << ans.size() << '\n';
	for(auto u: ans) {
		cout << u << ' ';
	}
}