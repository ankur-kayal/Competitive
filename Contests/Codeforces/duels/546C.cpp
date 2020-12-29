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
	int n;
	cin >> n;
	int k1;
	cin >> k1;
	queue<int> a,b;
	for(int i=0;i<k1;i++) {
		int foo;
		cin >> foo;
		a.push(foo);
	}
	int k2;
	cin >> k2;
	for(int i=0;i<k2;i++) {
		int foo;
		cin >> foo;
		b.push(foo);
	}
	int ans = 0;
	for(int i=0;i<1000000;i++) {
		int c1 = a.front();
		a.pop();
		int c2 = b.front();
		b.pop();
		if(c1 > c2) {
			a.push(c2);
			a.push(c1);
		}
		else {
			b.push(c1);
			b.push(c2);
		}
		ans++;
		if(a.empty() or b.empty()) {
			break;
		}
	}
	if(a.empty() or b.empty()) {
		cout << ans << ' ';
		if(a.empty()) {
			cout << 2 << '\n';
		}
		else {
			cout << 1 << '\n';
		}
	}
	else {
		cout << -1 << '\n';
	}
}