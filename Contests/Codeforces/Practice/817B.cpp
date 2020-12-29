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

long long answer(long long n, long long r) {
	debug() << imie(n) imie(r);
	long long deno = 1;
	long long num = 1;
	for(int i=1;i<=r;i++) {
		deno *= i;
		num *= (n-i+1);
	}
	debug() << imie(num) imie(deno);
	return num / deno;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	set<int> a;
	map<int,int> cnt;
	for(int i=0;i<n;i++) {
		int tmp;
		cin >> tmp;
		a.insert(tmp);
		cnt[tmp]++;
	}
	debug() << imie(cnt);
	int c = 3;
	for(auto u: a) {
		debug() << imie(c);
		if(c - cnt[u] <= 0) {
			// debug() << imie(a[i]) imie(cnt[a[i]]);
			cout << answer(cnt[u], c);
			exit(0);
		}
		// debug() << imie(cnt)
		c -= cnt[u];
	}

}