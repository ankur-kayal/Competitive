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
		long long p,q;
		cin >> p >> q;

		long long hcf = __gcd(p,q);
		if(hcf != q) {
			cout << p << '\n';
		}
		else if(p < q) {
			cout << p << '\n';
		}
		else {
			map<int,int> cnt;
			long long num = q;
			for(long long i=2;i*i<=q;i++) {
				if(num % i == 0) {
					while(num % i == 0) {
						num/=i;
						cnt[i]++;
					}
				}
			}
			if(num > 1) {
				cnt[num]++;
			}
			long long ans = -1;
			for(auto u: cnt) {
				long long f = u.first;
				long long c = u.second;
				long long tmp = 0;
				long long ntmp = p;
				while(ntmp % f == 0) {
					tmp++;
					ntmp /= f;
				}
				long long div = 1;
				for(int i=1;i<=tmp - c + 1;i++) {
					div *= f;
				}
				ans = max(ans, p / div);
			}
			debug() << imie(cnt);
			assert(ans != -1);
			cout << ans << '\n';
		}
		// long long ans = -1;
		// for(long long i=1;i*i<=p;i++) {
		// 	if(p % i == 0) {
		// 		long long x = i;
		// 		long long y = p / i;
		// 		if(x % q != 0) {
		// 			ans = max(ans,x);
		// 		}
		// 		if(y % q != 0) {
		// 			ans = max(ans,y);
		// 		}
		// 	}
		// }
		// cout << ans << '\n';
		// debug() << imie(hcf);
	}
}