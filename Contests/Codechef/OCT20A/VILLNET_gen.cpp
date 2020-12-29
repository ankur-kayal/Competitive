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

vector<vector<int>> dp(100, vector<int>(100,1000000));
map<pair<int,int>> store;

void init() {

	int marker = 1;
	for(int i=-13;i<=13;i+=2) {
		for(int j=1;j<=13;j+=2) {
			if(__gcd(abs(i),j) == 1) {
				store[{i,j}] = marker;
				marker++;
			}
		}
	}

	for(int k=1;k<=82;k++) {
		for(int i=1;i<=82;i++) {
			for(int j=1;j<=82;j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}

void subtask1(pair<int,int> p1, pair<int,int> p2) {
	int a1 = store[p1];
	int a2 = store[p2];
	cout << dp[a1][a2] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	vector<pair<int,int>> pts;

	for(int i=-13;i<=13;i+=2) {
		for(int j=1;j<=13;j+=2) {
			if(__gcd(abs(i),j) == 1) {
				pts.push_back({i,j});
			}
		}
	}
	debug() << imie(pts.size());
}