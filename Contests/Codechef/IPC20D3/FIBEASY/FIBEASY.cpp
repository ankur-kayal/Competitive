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

void multiply(int64_t F[2][2], int64_t M[2][2]) {
   int64_t a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
   int64_t b= F[0][0] * M[0][1] + F[0][1] * M[1][1];
   int64_t c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
   int64_t d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
   F[0][0] = a % 10;
   F[0][1] = b % 10;
   F[1][0] = c % 10;
   F[1][1] = d % 10;
}

void power(int64_t F[2][2], int64_t n) {
   if (n == 0 || n == 1)
      return;
   int64_t M[2][2] = {{1,1},{1,0}};
   power(F, n / 2);
   multiply(F, F);
   if (n % 2 != 0)
      multiply(F, M);
}

int64_t compute(int64_t n) {
   int64_t F[2][2] = {{1,1},{1,0}};
   if (n == 0)
      return 0;
   power(F, n - 1);
   return F[0][0];
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int64_t n;
		cin >> n;

		int64_t x = 1;
		while(x <= n) {
			x *= 2;
		}
		if(x > n) {
			x /= 2;
		}
		cout << compute(x - 1) << '\n';	
	}
}