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

	long long mod = 1e9 + 7;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<long long> a(n+1);
		for(int i=1;i<=n;i++) {
			cin >> a[i];
		}
		int q;
		cin >> q;
		while(q--) {
			long long r;
			cin >> r;
			debug() << imie(r);
			long long ans = 0;
			vector<long long> candies(r+5);
			for(int i=1;i<=r+2;i++) {
				candies[i] = a[((i-1)%n) + 1];
			}
			// debug() << imie(candies);
			
			int open = 1;
			for(int i=1;i<=r;i++) {
				long long available = candies[i];

				// when number of candies is odd
				if(available & 1) {
					long long value = available;
					// if number of candies is not 1 then proceed
					if(available != 1) {
						if(i + 1 <= r and candies[i + 1] == 1) {
							if(i + 1 == r and i % n == 0) {
								value = available;
							}
							else if(i + 1 == r or (i + 1) % n == 0 or i % n == 0) {
								value = available - 1;
							}
						}
						else if(i % n != 0) {
							value = available - 1;
						}
					}
					available = value;
				}

				// when number of candies is even
				else {
					long long value = available;
					if(i + 1 <= r and candies[i + 1] == 1) {
						if(i + 1 == r and i % n == 0) {
							value = available - 1;
							// cout << "culprit" << '\n';
						}
						else if(i + 1 == r or (i + 1) % n == 0 or i % n == 0) {
							value = available;
						}
						else {
							value = available - 1;
							// cout << "culprit" << '\n';
						}
					}
					else {
						if(i % n == 0 and candies[i+1] != 1) {
							value = available - 1;
							// cout << "culprit" << '\n';
						}
					}
					available = value;
				}
				
				// below conditions are 100% correct
				if(i == r) {
					available = candies[i];
				}
				if(open) {
					ans = (ans + available) % mod;
				}
				debug() << imie(open) imie(available) imie(candies[i]);
				if(available & 1) {
					open = open ^ 1;
				}
				if(i % n == 0) {
					open = open ^ 1;
				}
			}
			cout << ans << '\n';
		}
	}
}