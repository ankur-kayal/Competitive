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

	int n,q,s;
	cin >> n >> q >> s;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}

	int last = 0;

	function<int(int,int)> calculateLIS = [&](int l, int r) {
		int ans = 0;
		for(int i=l;i<=r;i++) {
			int tmp = 0;
			int maxTillNow = 0;
			for(int j=i;j<=r;j++) {
				if(a[j] > maxTillNow) {
					maxTillNow = a[j];
					tmp++;
				}
			}
			ans = max(ans, tmp);
			if(r - l < ans) {
				break;
			}	
		}
		return ans;
	};

	while(q--) {
		int x,y;
		cin >> x >> y;
		x = ((x + s * last - 1) % n) + 1;
		y = ((y + s * last - 1) % n) + 1;

		if(x > y) {
			swap(x,y);
		}

		last = calculateLIS(x,y);
		cout << last << '\n';
	}
}