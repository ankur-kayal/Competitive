#include <bits/stdc++.h>
#include <bitset>
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
#define Stringize( L )     #L 
#define MakeString( M, L ) M(L)
#define $Line MakeString( Stringize, __LINE__ )
#define Reminder __FILE__ "("  ") : Warning: "

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
        return splitmix64(x(a.first) * 37 + y(a.second) + FIXED_RANDOM);
    }
};
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;

//----------------------- CUSTOM UNORDERED MAP HASH END--------------------------

vector<int64_t> atkin() {
    static const int64_t limit = 1e9 + 1000;
    vector<int64_t> primes;

    bitset<limit> sieve;
    sieve.reset();
    if (limit > 2)
        primes.push_back(2);
    if (limit > 3)
        primes.push_back(3);

    for (int64_t x = 1; x * x < limit; x++) {
        for (int64_t y = 1; y * y < limit; y++) {
              
            // Main part of Sieve of Atkin
            int64_t n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve.set(n);
  
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                sieve.set(n);
  
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve.set(n);
        }
    }
  
    // Mark all multiples of squares as non-prime
    for (int64_t r = 5; r * r < limit; r++) {
        if (sieve[r]) {
            for (int i = r * r; i < limit; i += r * r)
                sieve.reset(i);
        }
    }

    for (int64_t a = 5; a < limit; a++)
        if(sieve[a]) {
            primes.push_back(a);
        }

    return primes;
}

vector<int64_t> product_of_primes;
void run_cases() {
    int64_t Z;
    cin >> Z;
    cout << *prev(upper_bound(all(product_of_primes), Z)) << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    vector<int64_t> primes = atkin();
    // debug() << imie(primes);
    for(int i=0;i<primes.size()-1;i++) {
        product_of_primes.push_back(primes[i] * primes[i + 1]);
    }

    // debug() << imie(primes.back());

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}