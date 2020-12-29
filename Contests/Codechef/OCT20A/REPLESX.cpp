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
		int n,x,p,k;
		cin >> n >> x >> p >> k;
		vector<int> a(n,0);
		for(int i=0;i<n;i++) {
			cin >> a[i];
		}
		sort(a.begin(),a.end());
		
		if(p < k){
			// p < k
			if(a[p-1] < x) {
				cout << -1 << '\n';
			}
			else if(a[p-1] == x) {
				cout << 0 << '\n';
			}
			else {
				int ans = 0;
				for(int i=0;i<k;i++) {
					debug() << imie(a[i]) << imie(x);
					if(a[i] <= x) {
						ans++;
					}
					else {
						break;
					}
				}
				debug() << imie(k) imie(ans);
				ans = p - ans;
				assert(ans > 0);
				cout << ans << '\n';
			}
			
		} // this case solved

		else if(p == k){
			// p == k
			int ans = 0;
			if(a[p-1] < x) {
				for(int i=k-1;i<n;i++) {
					if(a[i] < x) {
						ans++;
					}
				}
				cout << ans << '\n';
			}
			else if(a[p-1] == x) {
				cout << 0 << '\n';
			}
			else {
				int ans = 0;
				for(int i=0;i<k;i++) {
					if(a[i] <= x) {
						ans++;
					}
				}
				cout << (p - ans) << '\n';
			}
		} // this case solved

		else{
			// p > k 
			if(a[p-1] < x) {
				int ans = 0;
				for(int i=p-1;i<n;i++) {
					if(a[i] < x) {
						ans++;
					}
				}
				cout << ans << '\n';
			}
			else if(a[p-1] == x) {
				cout << 0 << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		} 
	}
}