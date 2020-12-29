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
		string a,b;
		cin >> a >> b;
		int n = a.length();
		vector<int> odd;
		vector<int> even;
		for(int i=0;i<n;i+=2) {
			if(a[i] != b[i]) {
				odd.push_back(i);
			}
		}
		for(int i=1;i<n;i+=2) {
			if(a[i] != b[i]) {
				even.push_back(i);
			}
		}
		int64_t ans = 0;
		odd.push_back(100000000);
		even.push_back(100000000);
		for(int i=0;i<odd.size() - 1;i++) {
			if(odd[i]+ 2 != odd[i + 1]) {
				ans++;
			}
		}
		for(int i=0;i<even.size() - 1;i++) {
			if(even[i]+ 2 != even[i + 1]) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
}