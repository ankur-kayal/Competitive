// problem link -> https://atcoder.jp/contests/abc149/tasks/abc149_c

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

	vector<int> seive(1000'005,1);
	seive[0] = seive[1] = 0;
	for(int i=2;i*i<=1000'000;i++) {
		if(seive[i] == 1) {
			for(int j=i*i;j<=1000'000;j+=i) {
				seive[j] = 0;
			}
		}
	}
	vector<int> primes;
	for(int i=2;i<=1000'000;i++) {
		if(seive[i] == 1) {
			primes.push_back(i);
		}
	}

	int x;
	cin >> x;
	for(auto u: primes) {
		if(u >= x) {
			cout << u;
			return 0;
		}
	}
}