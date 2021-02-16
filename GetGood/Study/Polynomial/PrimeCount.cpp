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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define nl '\n'

//----------------------------------- END DEFINES -------------------------------- 

//-------------------------- CUSTOM UNORDERED MAP HASH ---------------------------

struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(a + FIXED_RANDOM);
    }
    template<class T> size_t operator()(T a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        return splitmix64(x(a) + FIXED_RANDOM);
    }
    template<class T, class H> size_t operator()(pair<T, H> a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        hash<H> y;
        return splitmix64(x(a.f) * 37 + y(a.s) + FIXED_RANDOM);
    }
};
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;

//----------------------- CUSTOM UNORDERED MAP HASH END--------------------------



vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i * i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}

uint64_t kth_root(uint64_t a, int k) {
  if(k == 1) return a;
  auto check = [&](uint32_t x) {
    uint64_t mul = 1;
    for(int j = 0; j < k; j++) {
      if(__builtin_mul_overflow(mul, x, &mul)) return false;
    }
    return mul <= a;
  };
  uint64_t ret = 0;
  for(int i = 31; i >= 0; i--) {
    if(check(ret | (1u << i))) ret |= 1u << i;
  }
  return ret;
}

template< int64_t LIM = 100000000000LL >
struct PrimeCount {
private:
  int64_t sq;
  vector< bool > prime;
  vector< int64_t > prime_sum, primes;

  int64_t p2(int64_t x, int64_t y) {
    if(x < 4) return 0;
    int64_t a = pi(y);
    int64_t b = pi(kth_root(x, 2));
    if(a >= b) return 0;
    int64_t sum = (a - 2) * (a + 1) / 2 - (b - 2) * (b + 1) / 2;
    for(int64_t i = a; i < b; i++) sum += pi(x / primes[i]);
    return sum;
  }

  int64_t phi(int64_t m, int64_t n) {
    if(m < 1) return 0;
    if(n > m) return 1;
    if(n < 1) return m;
    if(m <= primes[n - 1] * primes[n - 1]) return pi(m) - n + 1;
    if(m <= primes[n - 1] * primes[n - 1] * primes[n - 1] && m <= sq) {
      int64_t sx = pi(kth_root(m, 2));
      int64_t ans = pi(m) - (sx + n - 2) * (sx - n + 1) / 2;
      for(int64_t i = n; i < sx; ++i) ans += pi(m / primes[i]);
      return ans;
    }
    return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);
  }

public:

  PrimeCount() : sq(kth_root(LIM, 2)), prime_sum(sq + 1) {
    prime = prime_table(sq);
    for(int i = 1; i <= sq; i++) prime_sum[i] = prime_sum[i - 1] + prime[i];
    primes.reserve(prime_sum[sq]);
    for(int i = 1; i <= sq; i++) if(prime[i]) primes.push_back(i);
  }

  int64_t pi(int64_t n) {
    if(n <= sq) return prime_sum[n];
    int64_t m = kth_root(n, 3);
    int64_t a = pi(m);
    return phi(n, a) + a - 1 - p2(n, m);
  }
};


void run_cases() {
    int64_t N;
    cin >> N;
    PrimeCount<> pc;

    cout << pc.pi(N);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}