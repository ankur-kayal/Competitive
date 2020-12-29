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
	const int mod = 1e9 + 7;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<long long> a(n + 1);
		for(int i=1;i<=n;i++) {
			cin >> a[i];
		}

		int maxN = n + 5;
		vector<long long> pref(maxN + 5), status(maxN + 5);
		long long ans = 0;
		vector<long long> candies(maxN + 5);
		for(int i=1;i<=maxN + 2;i++) {
			candies[i] = a[((i-1)%n) + 1];
		}
		int marker1 = 1;
		int marker2 = 2;
		int open = 1;
		long long r = maxN + 2;
		for(int i=1;i<=maxN;i++) {
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
			// debug() << imie(open) imie(available) imie(candies[i]);
			status[i] = open;
			if(available & 1) {
				open = open ^ 1;
			}
			if(i % n == 0) {
				open = open ^ 1;
			}
			pref[i] = ans;
		}
		// debug() << imie(status);
		// debug() << imie(pref);
		int q;
		cin >> q;
		while(q--) {
			long long r;
			cin >> r;
			if(r == 1) {
				cout << a[1] << '\n';
				continue;
			}
			long long pre = pref[n];
			long long mult = ((r - 2) / n) % mod;
			long long ans = (pre * mult) % mod;
			long long left = max(0LL, (r - 2) - n * ((r - 2) / n));
			// debug() << imie(ans) imie(left) imie(pre);
			ans = (ans + pref[left]) % mod;
			long long index = ((r - 1) % n) + 1;
			long long secondLast, last;
			long long bonus = 0;
			long long chef;

			if(index == 1) {
				chef = status[n];
				secondLast = a[n];
				last = a[1];
				if(chef) {
					if(secondLast & 1) {
						bonus = secondLast + last;
					}
					else {
						bonus = secondLast + last - 1;
					}
				}
				else {
					if(secondLast == 1) {
						bonus = last;
					}
				}
				
			}
			else {
				chef = status[index - 1];
				secondLast = a[index - 1];
				last = a[index];
				if(chef) {
					if(secondLast == 1) {
						bonus = 1;
					}
					else if(secondLast & 1) {
						bonus = secondLast + last - 1;
					}
					else {
						bonus = secondLast + last;
					}
				}
				else {
					if(secondLast == 1) {
						bonus = last;
					}
				}
			}
			// debug() << imie(last) imie(secondLast);
			// debug() << imie(ans) imie(bonus);
			ans = (ans + bonus) % mod;
			
			cout << ans << '\n';
		}
	}
}