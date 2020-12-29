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
const int maxN = 72;
const int inf = 1e9;
int dp[maxN][maxN][maxN][maxN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m,k;
	cin >> n >> m >> k;
	
	for(int i=0;i<maxN;i++) {
		for(int j=0;j<maxN;j++) {
			for(int p=0;p<maxN;p++) {
				for(int l=0;l<maxN;l++) {
					dp[i][j][p][l] = -inf;
				}
			}
		}
	}

	dp[0][0][0][0] = 0;

	int a[n][m];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> a[i][j];
		}
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			for(int cnt=0;cnt<=m/2;cnt++) {
				for(int rem = 0;rem < k;rem++) {
					if(dp[i][j][cnt][rem] == -inf) continue;
					int ni = (j == m-1 ? i + 1 : i);
					int nj = (j == m-1 ? 0 : j + 1);
					if(i != ni) {
						dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
					}
					else {
						dp[ni][nj][cnt][rem] = max(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
					}
					if(cnt + 1 <= m/2) {
						int nrem = (a[i][j] + rem) % k;
						if(i != ni) {
							dp[ni][nj][0][nrem] = max(dp[ni][nj][0][nrem], dp[i][j][cnt][rem] + a[i][j]);
						}
						else {
							dp[ni][nj][cnt+1][nrem] = max(dp[ni][nj][cnt+1][nrem], dp[i][j][cnt][rem] + a[i][j]);
						}
					}
				}
			}
		}
	}

	cout << max(0, dp[n][0][0][0]) << '\n';

	
}