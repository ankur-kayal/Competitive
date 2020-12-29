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
vector<long long> fact(1000005), ifact(1000005), inv(100005);
 
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
	fact[1] = 1;
    fact[0] = 1;
	ifact[1] = 1;
    ifact[0] = 1;
    inv[1] = 1;
	for(int i=2;i<=100000;i++) {
		fact[i] = (fact[i-1] * i) % mod;
		inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
	}
    for(int i=2;i<=100000;i++) {
        ifact[i] = (ifact[i-1] * inv[i]) % mod;
    }
}

long long combine(long long n, long long r) {
	if(r > n) {
		return 0;
	}
	return mult(fact[n], mult(ifact[r], ifact[n-r]));
}

void bin_search(vector<int>&a, int x, int num, int maxN) {
	int l = 0;
	int r = a.size();
	int cnt = 0;
	long long ans = 1;
	int big = maxN - num;
	int small = num - 1;

	while (l < r) { 
		cnt++;
        int m = (l + r) / 2; 
        if(a[m] <= x) {
        	l = m + 1;
        	
        	if(a[m] != x) {
        		ans = mult(ans, small);
        		small = max(0,small-1);
        	}
        	
        }
        else {
        	r = m;
        	ans = mult(ans, big);
        	big = max(0, big - 1);
        }
        debug() << imie(ans);
    }
    ans = mult(ans, fact[maxN-cnt]);
    cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	int n,x,pos;
	cin >> n >> x >> pos;
	// const int mod = 1e9 + 7;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		a[i] = i;
	}
	bin_search(a,pos,x,n);

	// int big = n - x;
	// // int small = x - 1;
	// long long ans = mult(mult(combine(big, cnt - 1), fact[n-cnt]), 1);
	// debug() << imie(big) imie(cnt);
	// cout << ans << '\n';

}