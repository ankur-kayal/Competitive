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

void checker(vector<int> &a) {
	int n = a.size();
	// bool ok = true;
	for(int i=1;i<n-1;i++) {
		assert((a[i]&a[i+1])>0);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	set<int> forbidden;
	for(int i=1;i<25;i++) {
		forbidden.insert(1LL<<i);
	}
	debug() << imie(forbidden);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n == 1) {
			cout << 1 << '\n';
		}
		if(!forbidden.count(n)) {
			vector<int> ans(n+1);
			for(int i=1;i<=n;i++) {
				ans[i] = i;
			}
			swap(ans[1],ans[2]);
			swap(ans[2],ans[3]);
			for(int i=2;(1LL<<i) <= n;i++) {
				int index = 1LL<<i;
				swap(ans[index],ans[index + 1]);
			}
			checker(ans);
			for(int i=1;i<=n;i++) {
				cout << ans[i] << " ";
			}
			cout << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
}