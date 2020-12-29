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
		int n,k;
		cin >> n >> k;
		string a,b;
		cin >> a >> b;
		vector<int> cnta(26,0);
		vector<int> cntb(26,0);
		for(auto u: a) {
			cnta[u - 'a']++;
		}
		for(auto u: b) {
			cntb[u - 'a']++;
		}
		for(int i=0;i<25;i++) {
			int rem = cnta[i] - cntb[i];
			if(rem > 0) {
				cnta[i + 1] += (rem / k * k);
				cnta[i] -= (rem / k * k);
			}
			
		}
		debug() << imie(cnta);
		debug() << imie(cntb);
		bool ok = true;
		for(int i=0;i<26;i++) {
			if(cnta[i] != cntb[i]) {
				ok = false;
			}
		}
		cout << (ok ? "Yes" : "No") << '\n';
	}
}