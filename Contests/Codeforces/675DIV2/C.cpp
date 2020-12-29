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

vector<long long> fact(1000005), ifact(1000005);

const int mod = 1e9 + 7;

long long logpow(long long x,long long y) {
	long long res = 1;
	while(y > 0) {
		
		if(y & 1) {
			res = (res * x) % mod;
		}
		y = y >> 1;
		x = (x * x)%mod;
		// debug() << imie(res);
	}
	return res;
}

long long mult(long long a, long long b) {
	return (a * b) % mod;
}

long long add(long long a, long long b) {
	return (a + b) % mod;
}

long long sub(long long a, long long b) {
	return (a - b + mod) % mod;
}

long long divide(long long a, long long b) {
	return mult(a,logpow(b,mod-2));
}

void init() {
	fact[0] = 0;
	for(int i=1;i<=100000;i++) {
		fact[i] = add(fact[i-1],mult(i, logpow(10,i-1)));
	}
	// debug() << imie(fact);
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();

	string s;
	cin >> s;
	int n = s.length();
	long long ans = 0;
	for(int i=0;i<(int)s.length();i++) {
		long long digit = s[i] - '0';
		ans = add(ans,mult(mult(logpow(10,n-i-1),digit), divide(mult(i,i+1),2)));
		ans = add(ans, mult(digit, fact[n-i-1]));
	}
	cout << ans << '\n';
	// debug() << imie(fact);
}