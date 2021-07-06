#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

template<typename T, int N>
struct Matrix {

    static const uint64_t CUTOFF = uint64_t(15000000180000000540LL);
    array<array<T, N>, N> values;

    Matrix() {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                values[i][j] = 0;
            }
        }
    }

    template<typename U>
    Matrix(const vector<vector<U>> &v) {
        init(v);
    }

    template<typename U>
    void init(const vector<vector<U>> &v) {
        assert(v.size() == N);

        for(int i=0;i<N;i++) {
            assert(v[i].size() == N);

            for(int j=0;j<N;j++) {
                values[i][j] = v[i][j];
            }
        }
    }

    array<T,N>& operator[](int index) {
        assert(index >= 0 && index < N);
        return values[index];
    }

    const array<T,N>& operator[](int index) const {
        assert(index >= 0 && index < N);
        return values[index];
    }

    void make_identity() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                values[i][j] = i == j ? 1 : 0;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix product;

        for(int i=0;i<N;i++) {
            for(int k=0;k<N;k++) {
                uint64_t result = 0;
 
                for(int j=0;j<N;j++) {
                    result += uint64_t(values[i][j]) * uint64_t(other[j][k]);
                    if(result > CUTOFF) {
                        product[i][k] += result;
                        result = 0;
                    }
                }
                product[i][k] += result;
            }
        }
        

        return product;
    }

    Matrix& operator*=(const Matrix &other) {
        return *this = *this * other;
    }

    Matrix operator+(const Matrix &other) const {
        Matrix addition;

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                addition[i][j] = values[i][j] + other[i][j];
            }
        }
        return addition;
    }

    Matrix& operator+=(const Matrix &other) {
        return *this = *this + other;
    }

    Matrix operator-(const Matrix &other) const {
        Matrix subtraction;

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                subtraction[i][j] = values[i][j] - other[i][j];
            }
        }
        return subtraction;
    }

    Matrix& operator-=(const Matrix &other) {
        return *this = *this - other;
    }

    void print() const {
        cerr << "[";
        for(int i=0;i<N;i++) {
            if(i == 0)
                cerr << "[";
            else
                cerr <<" [";
            for(int j=0;j<N;j++) {
                cerr << values[i][j];
                if(j != N-1) {
                    cerr << ", ";
                }
            }
            if(i != N-1)
                cerr << "],\n";
            else
                cerr << "]";
        }
        cerr << "]\n";
    }    
};

template<typename T, int N>
Matrix<T, N> power(Matrix<T, N> &a, int64_t p) {
    assert(p >= 0); // exponent must be >= 0
    
    Matrix<T, N> m = a;
    Matrix<T, N> result;
    result.make_identity();

    while(p > 0) {
        if(p & 1) {
            result *= m;
        }

        p /= 2;

        if(p > 0)
            m *= m;
    }
    return result;
}

template<typename T, int N>
Matrix<T, N> gp_series_sum(Matrix<T, N> &a, int64_t n) {
    Matrix<T, N> result;
    Matrix<T, N> result1;
    Matrix<T, N> I;
    result1.make_identity();
    I.make_identity();
    vector<int64_t> pows;
    while(n > 0) {
        pows.push_back(n);
        n /= 2;
    }
    reverse(pows.begin(), pows.end());
    for(auto u: pows) {
        result *= (I + result1);
        result1 *= result1;
        if(u & 1) {
            result1 *= a;
            result += result1;
        }
    }
    return result;
}

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
 
extern const int MOD = int(1e9) + 7;
using mod_int = _m_int<MOD>;


void run_cases() {
    int64_t N, M, K;
    cin >> N >> M >> K;

    Matrix<mod_int, 31> base;
    Matrix<mod_int, 31> ans;

    // for(int i = 0; i <= M; i++) {
    //     ans[0][]
    // }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}