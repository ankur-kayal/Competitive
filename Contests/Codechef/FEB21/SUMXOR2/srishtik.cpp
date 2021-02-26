// possible ntt template and good neal modint template
#include <bits/stdc++.h>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int MOD = 998244353;


// this NTT template is taken from legendary grandmaster neal



struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    static int mod_inv(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const {
        return val;
    }

    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }

    mod_int inv() const {
        return mod_inv(val);
    }

    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};

namespace NTT {
    vector<mod_int> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    mod_int root;

    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }

    int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return max(n, 1);
    }

    // Given n (a power of two), finds k such that n == 1 << k.
    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }

    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<mod_int> &values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);

            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
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

        if ((int) roots.size() >= n)
            return;

        int length = get_length(roots.size());
        roots.resize(n);

        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th primitive roots of MOD.
        while (1 << length < n) {
            // z is a 2^(length + 1)-th primitive root of MOD.
            mod_int z = root.pow(max_size >> (length + 1));

            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * z;
            }

            length++;
        }
    }

    void fft_iterative(int N, vector<mod_int> &values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);

        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    mod_int even = values[start + i];
                    mod_int odd = values[start + n + i] * roots[n + i];
                    values[start + n + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }

    const int FFT_CUTOFF = 150;

    vector<mod_int> mod_multiply(vector<mod_int> left, vector<mod_int> right) {
        int n = left.size();
        int m = right.size();

        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(n + m - 1, 0);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) ((int) left[i]) * ((int) right[j]);

                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= MOD;
                }

            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;

            return vector<mod_int>(result.begin(), result.end());
        }

        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);

        bool equal = left == right;
        fft_iterative(N, left);

        if (equal)
            right = left;
        else
            fft_iterative(N, right);

        mod_int inv_N = mod_int(N).inv();

        for (int i = 0; i < N; i++)
            left[i] *= right[i] * inv_N;

        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);
        return left;
    }

    vector<mod_int> mod_power(const vector<mod_int> &v, int exponent) {
        assert(exponent >= 0);
        vector<mod_int> result = {1};

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);

            if (exponent >> k & 1)
                result = mod_multiply(result, v);
        }

        return result;
    }

    vector<mod_int> mod_multiply_all(const vector<vector<mod_int>> &polynomials) {
        if (polynomials.empty())
            return {1};

        struct compare_size {
            bool operator()(const vector<mod_int> &x, const vector<mod_int> &y) {
                return x.size() > y.size();
            }
        };

        priority_queue<vector<mod_int>, vector<vector<mod_int>>, compare_size> pq;

        for (auto &poly : polynomials)
            pq.push(poly);

        while (pq.size() > 1) {
            vector<mod_int> a = pq.top(); pq.pop();
            vector<mod_int> b = pq.top(); pq.pop();
            pq.push(mod_multiply(a, b));
        }

        return pq.top();
    }
}

const int N = 2e5;

mod_int fact[N+1]; 

mod_int power(mod_int x,int y){
    mod_int res=1;
    while(y>0){
        if(y%2>0) {
            res = res * x;
        }
        y>>=1;
        x = x*x;
    }
    return res;
}

mod_int nCr(int n,int r){
    if(r>n) return 0;
    if(r<0) return 0;
    mod_int ans = fact[n];
    ans = ans * power(fact[n-r],MOD-2);
    ans = ans * power(fact[r],MOD-2);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fact[0]=1;
    for(int i=1;i<=N;i++) fact[i] = fact[i-1] * i;
    int n,q; cin>>n;
    vector<int> hashTable(30,0);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        for(int j=0;j<30;j++){
            if(x&(1LL<<j)) hashTable[j]++;
        }
    }
    vector<vector<mod_int>> ans(n+1,vector<mod_int>(30,0));
    for(int b=0;b<30;b++){
        int h = hashTable[b];
        vector<vector<mod_int>> polynomials(2);
        polynomials[0].resize(h+1); polynomials[0][0]=0;
        for(int i=1;i<=h;i++){
            if(i%2==0) polynomials[0][i]=0;
            else polynomials[0][i] = nCr(h,i);
        }
        mod_int temp=0;
        polynomials[1].resize(n+1);
        for(int i=0;i<=n;i++){
            temp = temp + nCr(n-h,i);
            polynomials[1][i]=temp;
        }
        vector<mod_int> result = NTT::mod_multiply_all(polynomials);
        for(int i=1;i<=n;i++){
            ans[i][b] = result[i] * (1LL<<b);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<30;j++){
            ans[i][j] = ans[i][j] + ans[i][j-1];
        }
    }
    cin>>q;
    while(q--){
        int m; cin>>m;
        cout<<ans[m][29]<<endl;
    }
    return 0;
}