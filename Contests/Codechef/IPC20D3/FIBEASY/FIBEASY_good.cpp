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
	const int maxN = 1e7 + 10;
	vector<int64_t> fib(maxN);
	fib[0] = 0;
	fib[1] = 1; 
	for(int i=2;i<=maxN-1;i++) {
		fib[i] = (fib[i-1] + fib[i-2])%10;
	}
	while(t--) {
		/*int64_t n;
		cin >> n;
		vector<int> dum(n + 1);
		for(int i=1;i<=n;i++) {
			dum[i] = i;
		}
		vector<int> tmp(dum.begin(), dum.end());
		while((int)dum.size() != 2) {
			tmp.clear();
			tmp.push_back(0);
			for(int i=2;i<=(int)dum.size();i+=2) {
				tmp.push_back(dum[i]);
			}
			dum.clear();
			dum = tmp;
		}
		cout << fib[dum[1] - 1] << '\n';
		*/
		int64_t n;
		cin >> n;

		int64_t x = 1;
		while(x <= n) {
			x *= 2;
		}
		if(x > n) {
			x /= 2;
		}
		if(x == 1) {
			cout << 0 << '\n';
		}
		else {
			cout << fib[x - 1] << '\n';
		}
	}
}