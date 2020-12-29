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

bool isDivisor(string big, string small) {
	int m = (int)big.length() / (int)small.length();
	string res = "";
	for(int i=0;i<m;i++) {
		res += small;
	}
	return res == big;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s1,s2;
	cin >> s1 >> s2;

	int n = s1.length();
	int m = s2.length();
	if(n > m) {
		swap(s1,s2);
	}
	string tmp1 = "", tmp2 = "";
	int rep = min(n,m);
	int ans = 0;
	for(int i=1;2*i<=rep;i++) {
		tmp1 += s1[i-1];
		tmp2 += s2[i-1];
		if(tmp1 != tmp2) {
			cout << 0 << '\n';
			exit(0);
		}
		if(n % i == 0 and m % i == 0) {
			if(isDivisor(s1,tmp1) and isDivisor(s2,tmp1)) {
				ans++;
			}
		}
	}
	// cout << isDivisor(s2,s1);
	ans += (isDivisor(s2,s1));
	cout << ans << '\n';

}