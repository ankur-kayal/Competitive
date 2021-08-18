#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

template<const int &MOD>
struct _m_int {
    int val;
 
    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}
 
    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
 
    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    #if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
    #endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }
 
    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }
 
    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
 
    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }
 
    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
 
    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];
 
    static void prepare_inv() {
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);
 
        save_inv[0] = 0;
        save_inv[1] = 1;
 
        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }
 
    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();
 
        if (val < SAVE_INV)
            return save_inv[val];
 
        _m_int product = 1;
        int v = val;
 
        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }
 
        return product * save_inv[v];
    }
 
    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);
 
        _m_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            p >>= 1;
 
            if (p > 0)
                a *= a;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};
 
template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];
 
extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;

vector<int> mobius;
vector<bool> prime;
vector<int> primes;

void build_mobius(int maximum) {
    assert(maximum >= 0);

    mobius.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    mobius[1] = 1;

    for(int i = 2; i <= maximum; i++) {
        if(prime[i]) {
            primes.push_back(i);
            mobius[i] = -1;
        }

        for(int j: primes) {
            if(i * j > maximum) {
                break;
            }
            prime[i * j] = false;
            if(i % j == 0) {
                mobius[i * j] = 0;
                break;
            } else {
                mobius[i * j] = mobius[i] * mobius[j];
            }
        }
    }
}

void run_cases() {

    auto solve = [] (vector<int> &L, vector<int> &R, int max_sum) -> mod_int {

        int N = L.size();

        vector<vector<mod_int>> dp(N + 1, vector<mod_int>(max_sum + 1));
        dp[0] = {1};

        for(int i = 0; i < N; i++) {
            for(int j = 0; j <= max_sum; j++) {
                int l = j - R[i] - 1;
                int r = j - L[i];
                if(r >= 0) {
                    dp[i + 1][j] += dp[i][r];
                }
                if(l >= 0) {
                    dp[i + 1][j] -= dp[i][l];
                }
            }
            for(int j = 1; j <= max_sum; j++) {
                dp[i + 1][j] += dp[i + 1][j - 1];
            }
        }

        mod_int res = 0;

        for(int i = 0; i <= max_sum; i++) {
            res += dp[N][i];
        }
        return res;
    };

    build_mobius(int(1e5) + 100);

    int N, M;
    cin >> N >> M;

    vector<int> L(N), R(N);
    for(int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }

    mod_int ans = 0;

    for(int gcd = 1; gcd <= M; gcd++) {
        vector<int> LS(N), RS(N);
        for(int i = 0; i < N; i++) {
            LS[i] = (L[i] + gcd - 1) / gcd;
            RS[i] = R[i] / gcd;
        }

        ans += mobius[gcd] * solve(LS, RS, M / gcd);

    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}