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

	int t;
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		vector<char> s(n);
		for(int i=0;i<n;i++) {
			cin >> s[i];
		}
		int ans = 0;
		int tmp = 0;
		int l = 0;
		vector<pair<int,int>> score;
		int marker = 0;
		if(s[0] == 'L') {
			marker = 2;
		}
		int lost = 0;
		int bonus = 0;
		for(int i=0;i<n;i++) {
			if(s[i] == 'W') {
				tmp++;
				if(i-1>=0 and s[i-1] == 'W') {
					tmp++;
				}
				if(l > 0) {
					score.emplace_back(marker,l);
					l = 0;
				}
				marker = 0;
			}
			else {
				lost++;
				ans += tmp;
				l++;
				tmp = 0;
			}
		}
		if(lost == n) {
			if(k > 0)
			cout << 2 * min(n,k) - 1 << '\n';
			else {
				cout << 0 << '\n';
			}
			continue;
		}
		ans += tmp;
		if(l != 0) {
			if(marker == 0) {
				marker = 1;
			}
			score.emplace_back(marker,l);
		}
		debug() << imie(ans);
		sort(score.begin(), score.end());

		for(auto u: score) {
			int m = u.first;
			int ele = u.second;
			if(ele <= k) {
				ans += ele * 2;
				if(m == 0) {
					bonus++;
				}
				// if(m == 2) {
				// 	ans--;
				// 	if(ele > 1) {
				// 		bonus++;
				// 	}
				// }
				k -= ele;
			}
			else {
				ans += k * 2;
				k -= k;
			}

		}
		debug() << imie(ans);
		cout << ans + bonus << '\n';
		
	}
}