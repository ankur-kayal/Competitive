// problem link -> https://atcoder.jp/contests/abc150/tasks/abc150_c

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

int find_small(vector<int> &a, int k) {
	int cnt = 0;
	for(int i=1;i<k;i++) {
		if(a[i] == 0) {
			cnt++;
		} 
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> fact(9);
	fact[1] = fact[0] = 1;
	for(int i=2;i<=8;i++) {
		fact[i] = fact[i-1] * i;
	}

	vector<int> p(n),q(n),used(n+1,0);
	for(int i=0;i<n;i++) {
		cin >> p[i];
	}
	for(int i=0;i<n;i++) {
		cin >> q[i];
	}

	int s1 = 1;
	for(int i=0;i<n;i++) {
		int k = p[i];
		int mul = find_small(used,k);
		s1 += (fact[n-i-1] * mul);
		debug() << imie(mul) << imie(fact[n-i-1]) << imie(s1);
		used[k] = 1;
	}

	int s2 = 1;
	used.assign(n+1,0);
	for(int i=0;i<n;i++) {
		int k = q[i];
		int mul = find_small(used,k);
		s2 += (fact[n-i-1] * mul);
		used[k] = 1;
	}

	debug() << imie(s1) imie(s2);

	cout << abs(s1 - s2) << '\n';

}