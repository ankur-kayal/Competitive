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

const int maxN = 1e7;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	while(q--) {
		int n;
		cin>>n;
		vector<int>t(n);
		for(int i=0;i<n;i++)
			cin>>t[i];
	 
		sort(t.begin(),t.end());
	 
		vector<vector<int>>dp(n+1,vector<int>(2*n+5,maxN));
		dp[0][0] = 0;
		for(int i=0;i<n;i++) {
			for(int j=1;j<=2*n;j++) {
				for(int k=0;k<j;k++) {
					dp[i+1][j] = min( dp[i+1][j], dp[i][k] + abs(j-t[i]) );
				}
			}
		}
		int ans = maxN;
		for(int i=1;i<=2*n;i++)
			ans = min( ans, dp[n][i] );
		cout << ans << '\n';
	}

}