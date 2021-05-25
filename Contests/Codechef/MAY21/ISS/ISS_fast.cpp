#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


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

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
 
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
 
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
 
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}
 
// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<int64_t, int>> result;
 
    if (n <= sieve_max) {
        while (n != 1) {
            int64_t p = smallest_factor[n];
            int exponent = 0;
 
            do {
                n /= p;
                exponent++;
            } while (n % p == 0);
 
            result.emplace_back(p, exponent);
        }
 
        return result;
    }
 
    for (int64_t p : primes) {
        if (p * p > n)
            break;
 
        if (n % p == 0) {
            result.emplace_back(p, 0);
 
            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }
 
    if (n > 1)
        result.emplace_back(n, 1);
 
    return result;
}
 
vector<int64_t> generate_factors(const vector<pair<int64_t, int>> &prime_factors, bool sorted = false) {
    // See http://oeis.org/A066150 and http://oeis.org/A036451 for upper bounds on number of factors.
    static vector<int64_t> buffer;
    int product = 1;
 
    for (auto &pf : prime_factors)
        product *= pf.second + 1;
 
    vector<int64_t> factors = {1};
    factors.reserve(product);
 
    if (sorted)
        buffer.resize(product);
 
    for (auto &pf : prime_factors) {
        int64_t p = pf.first;
        int exponent = pf.second;
        int before_size = int(factors.size());
 
        for (int i = 0; i < exponent * before_size; i++)
            factors.push_back(factors[factors.size() - before_size] * p);
 
        if (sorted && factors[before_size - 1] > p)
            for (int section = before_size; section < int(factors.size()); section *= 2)
                for (int i = 0; i + section < int(factors.size()); i += 2 * section) {
                    int length = min(2 * section, int(factors.size()) - i);
                    merge(factors.begin() + i, factors.begin() + i + section,
                          factors.begin() + i + section, factors.begin() + i + length,
                          buffer.begin());
                    copy(buffer.begin(), buffer.begin() + length, factors.begin() + i);
                }
    }
 
    return factors;
}

const int maxK = 4 * 1e6 + 10;
vector<vector<int64_t>> prime_factors(maxK);

void preprocess() {
    sieve(maxK);
    for(int i=5;i+4<maxK;i+=4) {
        int n = i;
        while (n != 1) {
            int64_t p = smallest_factor[n];
 
            do {
                n /= p;
            } while (n % p == 0);
 
            prime_factors[i].push_back(p);
        }
    }
}

int find_highest_power(int n, int upper) {
    int count = 0;
    int mul = n;
    while(n <= 4 * upper + 1) {
        count += (2 * upper - 1) / n + 1;
        n *= mul;
    }
    return count;
}

vector<int64_t> cache(maxK);

void generate_all_k_values() {
    for(int k=1;k<=1'0;k++) {
        int64_t ans = 0;
    
        int ones = 2 * k;
        for(auto u: prime_factors[4 * k + 1]) {
            int count = find_highest_power(u, k);
            ones -= count;
            ans += count * u;
            debug() << imie(k) imie(count) imie(u);
        }
        ans += ones;

        cache[k] = ans;
    }
}

void run_cases() {
    int k;
    cin >> k;
    
    cout << cache[k] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    preprocess();
    generate_all_k_values();

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}