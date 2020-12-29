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

	long long n;
	cin >> n;
	int zero = 0, one = 0, two = 0, s = 0, k = 0, ans;
	while(n != 0) {
		int d = n % 10;
		if(d % 3 == 0) {
			zero++;
		}
		if(d % 3 == 1) {
			one++;
		}
		if(d % 3 == 2) {
			two++;
		}
		s += d;
		n /= 10;
		k++;
	}

	if(s % 3 == 0) {
		ans = 0;
	}
	if(s % 3 == 1) {
		if(one != 0) {
			ans = 1;
		}
		else if(two >= 2) {
			ans = 2;
		}
		else {
			ans = -1;
		}
	}

	if(s % 3 == 2) {
		if(two != 0) {
			ans = 1;
		}
		else if(one >= 2) {
			ans = 2;
		}
		else {
			ans = -1;
		}
	}

	if(ans <= k - 1) {
		cout << ans << '\n';
	}
	else {
		cout << -1 << '\n';
	}

}