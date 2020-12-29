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

	int n,x;
	cin >> n >> x;
	vector<int> c(n);
	for(int i=0;i<n;i++) {
		cin >> c[i];
	}
	const int maxA = 1e6+10;
	const int maxN = 1e9;
	vector<int> amt(maxA,maxN);

	for(int i=0;i<n;i++) {
		amt[c[i]] = 1;
	}
	for(int i=1;i<=x;i++) {
		for(int j=0;j<n;j++) {
			if(i + c[j] <=x) {
				amt[i + c[j]] = min(amt[i+c[j]], amt[i] + 1);
			}
		}
	}
	cout << (amt[x] == maxN ? -1 : amt[x]) << '\n';
}