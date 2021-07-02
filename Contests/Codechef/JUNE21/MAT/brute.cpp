#include <algorithm>
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

vector<mod_int> _factorial = {1, 1}, _inv_factorial = {1, 1};
 
void prepare_factorials(int64_t maximum) {
    static int prepared_maximum = 1;
 
    if (maximum <= prepared_maximum)
        return;
 
    // Prevent increasing maximum by only 1 each time.
    maximum += maximum / 16;
    _factorial.resize(maximum + 1);
    _inv_factorial.resize(maximum + 1);
 
    for (int i = prepared_maximum + 1; i <= maximum; i++) {
        _factorial[i] = i * _factorial[i - 1];
        _inv_factorial[i] = _inv_factorial[i - 1] / i;
    }
 
    prepared_maximum = int(maximum);
}
 
mod_int factorial(int n) {
    if (n < 0) return 0;
    prepare_factorials(n);
    return _factorial[n];
}
 
mod_int inv_factorial(int n) {
    if (n < 0) return 0;
    prepare_factorials(n);
    return _inv_factorial[n];
}
 
mod_int choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    prepare_factorials(n);
    return _factorial[n] * _inv_factorial[r] * _inv_factorial[n - r];
}
 
mod_int permute(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    prepare_factorials(n);
    return _factorial[n] * _inv_factorial[n - r];
}
 
mod_int inv_choose(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    prepare_factorials(n);
    return _inv_factorial[n] * _factorial[r] * _factorial[n - r];
}
 
mod_int inv_permute(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    prepare_factorials(n);
    return _inv_factorial[n] * _factorial[n - r];
}

template<const int &MOD>
struct NTT {
    using ntt_int = _m_int<MOD>;
 
    vector<ntt_int> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    ntt_int root;
 
    void reset() {
        roots = {0, 1};
        max_size = -1;
    }
 
    static bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }
 
    static int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;
 
        return max(n, 1);
    }
 
    // Given n (a power of two), finds k such that n == 1 << k.
    static int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }
 
    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<ntt_int> &values) {
        if (int(bit_reverse.size()) != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);
 
            for (int i = 1; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) | ((i & 1) << (length - 1));
        }
 
        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }
 
    void find_root() {
        max_size = 1 << __builtin_ctz(MOD - 1);
        root = 2;
 
        // Find a max_size-th primitive root of MOD.
        while (!(root.pow(max_size) == 1 && root.pow(max_size / 2) != 1))
            root++;
    }
 
    void prepare_roots(int n) {
        if (max_size < 0)
            find_root();
 
        assert(n <= max_size);
 
        if (int(roots.size()) >= n)
            return;
 
        int length = get_length(int(roots.size()));
        roots.resize(n);
 
        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th primitive roots of MOD.
        while (1 << length < n) {
            // z is a 2^(length + 1)-th primitive root of MOD.
            ntt_int z = root.pow(max_size >> (length + 1));
 
            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * z;
            }
 
            length++;
        }
    }
 
    void fft_iterative(int n, vector<ntt_int> &values) {
        assert(is_power_of_two(n));
        prepare_roots(n);
        bit_reorder(n, values);
 
        for (int len = 1; len < n; len *= 2)
            for (int start = 0; start < n; start += 2 * len)
                for (int i = 0; i < len; i++) {
                    ntt_int even = values[start + i];
                    ntt_int odd = values[start + len + i] * roots[len + i];
                    values[start + len + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }
 
    void invert_fft(int n, vector<ntt_int> &values) {
        ntt_int inv_n = ntt_int(n).inv();
 
        for (int i = 0; i < n; i++)
            values[i] *= inv_n;
 
        reverse(values.begin() + 1, values.end());
        fft_iterative(n, values);
    }
 
    const int FFT_CUTOFF = 150;
 
    // Note: `circular = true` can be used for a 2x speedup when only the `max(n, m) - min(n, m) + 1` fully overlapping
    // ranges are needed. It computes results using indices modulo the power-of-two FFT size; see the brute force below.
    template<typename T>
    vector<T> mod_multiply(const vector<T> &_left, const vector<T> &_right, bool circular = false) {
        if (_left.empty() || _right.empty())
            return {};
 
        vector<ntt_int> left(_left.begin(), _left.end());
        vector<ntt_int> right(_right.begin(), _right.end());
 
        int n = int(left.size());
        int m = int(right.size());
 
        int output_size = circular ? round_up_power_two(max(n, m)) : n + m - 1;
 
        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            auto &&mod_output_size = [&](int x) {
                return x < output_size ? x : x - output_size;
            };
 
            static const uint64_t U64_BOUND = numeric_limits<uint64_t>::max() - uint64_t(MOD) * MOD;
            vector<uint64_t> result(output_size, 0);
 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    int index = mod_output_size(i + j);
                    result[index] += uint64_t(left[i]) * uint64_t(right[j]);
 
                    if (result[index] > U64_BOUND)
                        result[index] %= MOD;
                }
 
            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;
 
            return vector<T>(result.begin(), result.end());
        }
 
        int N = round_up_power_two(output_size);
        left.resize(N, 0);
        right.resize(N, 0);
 
        if (left == right) {
            fft_iterative(N, left);
            right = left;
        } else {
            fft_iterative(N, left);
            fft_iterative(N, right);
        }
 
        for (int i = 0; i < N; i++)
            left[i] *= right[i];
 
        invert_fft(N, left);
        return vector<T>(left.begin(), left.begin() + output_size);
    }

    template<typename T>
    vector<T> mod_inverse(const vector<T> &_a) {
        vector<ntt_int> a(_a.begin(), _a.end());
        assert(!a.empty());
        int N = int(a.size());
        vector<ntt_int> b = {a[0].inv()};
        while(int(b.size()) < N) {
            vector<ntt_int> x(a.begin(), a.begin() + min(a.size(), b.size() << 1));
            x.resize(b.size() << 1);
            b.resize(b.size() << 1);
            vector<ntt_int> c = b;
            fft_iterative(int(c.size()), c);
            fft_iterative(int(x.size()), x);
            ntt_int inv = ntt_int(int(x.size())).inv();
            for (int i = 0; i < (int) x.size(); i++) {
                x[i] *= c[i] * inv;
            }
            reverse(x.begin() + 1, x.end());
            fft_iterative(int(x.size()), x);
            rotate(x.begin(), x.begin() + (x.size() >> 1), x.end());
            fill(x.begin() + (x.size() >> 1), x.end(), 0);
            fft_iterative(int(x.size()), x);
            for (int i = 0; i < (int) x.size(); i++) {
                x[i] *= c[i] * inv;
            }
            reverse(x.begin() + 1, x.end());
            fft_iterative(int(x.size()), x);
            for (int i = 0; i < ((int) x.size() >> 1); i++) {
                b[i + ((int) x.size() >> 1)] = -x[i];
            }
        }
        b.resize(N);
        return vector<T>(b.begin(), b.end());
    }
 
    template<typename T>
    vector<T> mod_power(const vector<T> &v, int exponent) {
        assert(exponent >= 0);
        vector<T> result = {1};
 
        if (exponent == 0)
            return result;
 
        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);
 
            if (exponent >> k & 1)
                result = mod_multiply(result, v);
        }
 
        return result;
    }
 
    // Multiplies many polynomials whose total degree is n in O(n log^2 n).
    template<typename T>
    vector<T> mod_multiply_all(const vector<vector<T>> &polynomials) {
        if (polynomials.empty())
            return {1};
 
        struct compare_size {
            bool operator()(const vector<T> &x, const vector<T> &y) {
                return x.size() > y.size();
            }
        };
 
        priority_queue<vector<T>, vector<vector<T>>, compare_size> pq(polynomials.begin(), polynomials.end());
 
        while (pq.size() > 1) {
            vector<T> a = pq.top(); pq.pop();
            vector<T> b = pq.top(); pq.pop();
            pq.push(mod_multiply(a, b));
        }
 
        return pq.top();
    }
};

NTT<MOD> ntt;


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

map<int64_t, mod_int> large_factorials;

vector<mod_int> special(int(2e7));

const int maxN = 1e9+100;

void preprocess() {
    special[0] = 1;
    int start = maxN;
    for(int i = 1; i < special.size(); i++) {
        special[i] = special[i - 1] * start;
        start--;
    }
}

mod_int segment(int n, int r) {
    int left = maxN - n;
    int right = left + r;
    return special[right] / special[left];
}

mod_int large_choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;

    if(n > MOD && n - r >= MOD) {
        return segment(n, r) * _inv_factorial[r];
    } else if(n > MOD && n - r < MOD) {
        return 0;
    }

    return large_factorials[n] / (large_factorials[r] * large_factorials[n - r]);
}

void generate_factorials(vector<int64_t> & vals) {
    int index = 0;
    mod_int curr_ans = 1;
    const int maxN = MOD;
    for(int i = 1; i <= maxN; i++) {
        curr_ans = curr_ans * mod_int(i);
        if(vals[index] == i) {
            large_factorials[i] = curr_ans;
            index++;
        }
        if(index == vals.size()) {
            return;
        }
    }
}

void run_cases() {
    preprocess();
    int r;
    cin >> r;
    int k; cin >> k;

    vector<int64_t> A(k);
    vector<int64_t> P(k);
    for(auto &u: A)
        cin >> u;
    for(auto &u: P)
        cin >> u;

    for(int i = 0; i < k; i++) {
        mod_int tmp = 1;
        int64_t val = A[i];
        for(int i = 1; i <= r; i++) {
            tmp *= val;
            val--;
        }
        A[i] = int64_t(val);
    }
    vector<vector<mod_int>> polynomials;
    for(int i = 0; i < k; i++) {
        vector<mod_int> val(2);
        val[0] = mod_int(1) - mod_int(P[i]);
        val[1] = mod_int(P[i]) * mod_int(A[i]) * inv_factorial;
        polynomials.push_back(val);
        // debug() << imie(vals);
    }

    debug() << imie(polynomials);


    vector<mod_int> res = ntt.mod_multiply_all(polynomials);
    mod_int ans = 0;
    for(auto u: res) {
        ans += u;
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