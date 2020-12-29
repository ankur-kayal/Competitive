#include <bits/stdc++.h>
using namespace std;

// studied from -> https://cs.uwaterloo.ca/journals/JIS/VOL4/MARGOLIUS/inversions.pdf

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

const long long mod = 2;
unordered_map<long long, long long> store;


long long find2(long long x) {
	long long res = 0;
	long long mul = 2;
	while((x / mul) > 0) {
		res += (x / mul);
		mul *= 2;
	}
	return res;
}

long long pentagonal(long long x) {
	return (x*(3*x - 1))/2;
}

// long long combine(long long n, long long r) {
// 	long long num = n + r - 1;
// 	long long deno = r;

// 	if(deno == 0) {
// 		return 1;
// 	}
// 	if(num % 2 == 0 and deno % 2 == 1) {
// 		return 0;
// 	}
// 	if(num % 2 == 1 and deno % 2 == 1) {
// 		return 0;
// 	}
// 	else return 1;
// }

long long combine(long long n, long long r) {
	long long num = n + r - 1;
	long long den = r;
	long long anded = den&(num-den);
	long long parity;
	if(anded > 0) {
		parity = 0;
	}
	else {
		parity = 1;
	}
	return parity;
	// long long parity1;
	// if(store[n+r-1] == 0) store[n+r-1] = find2(n+r-1);
	// if(store[r] == 0) store[r] = find2(r);
	// if(store[n-1] == 0) store[n-1] = find2(n-1);
	// long long res = store[n + r - 1] - store[r] - store[n-1];
	
	// if(res > 0) {
	// 	parity1 = 0;
	// }
	// else {
	// 	parity1 = 1;
	// }
	// cout << parity << " " << parity1 << '\n';
	// return parity1;
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--)
	{
		long long n,k;
		cin >> n >> k;

		long long ans = 0;
		for (long long i = 1; ; ++i)
		{
			long long den = k - pentagonal(i) - i;
			if(den < 0)
				break;
			long long temp = combine(n,den);
			if(i&1)
				temp = mod - temp;
			ans = (ans + temp)%mod;
		}
		for (long long i = 1; ; ++i)
		{
			long long den = k - pentagonal(i);
			if(den < 0)
				break;
			long long temp = combine(n,den);
			if(i&1)
				temp = mod - temp;
			ans = (ans + temp)%mod;
		}
		ans = (ans + combine(n,k))%mod;

		cout << ans << "\n";
	}
	debug() << imie(store);

	// cout << combine(10,2) << '\n';
}