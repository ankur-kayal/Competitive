#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 5;

#define double long double
 
// https://judge.yosupo.jp/submission/3207
struct base {
    double x, y;
    base() { x = y = 0; }
    base(double x, double y): x(x), y(y) { }
};
inline base operator + (base a, base b) { return base(a.x + b.x, a.y + b.y); }
inline base operator - (base a, base b) { return base(a.x - b.x, a.y - b.y); }
inline base operator * (base a, base b) { return base(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline base conj(base a) { return base(a.x, -a.y); }
int lim = 1;
vector<base> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};
const double PI = acosl(- 1.0);
void ensure_base(int p) {
    if (p <= lim) return;
    rev.resize(1 << p);
    for (int i = 0; i < (1 << p); i++) rev[i] = (rev[i >> 1] >> 1) + ((i & 1)  <<  (p - 1));
    roots.resize(1 << p);
    while (lim < p) {
        double angle = 2 * PI / (1 << (lim + 1));
        for (int i = 1 << (lim - 1); i < (1 << lim); i++) {
            roots[i << 1] = roots[i];
            double angle_i = angle * (2 * i + 1 - (1 << lim));
            roots[(i << 1) + 1] = base(cos(angle_i), sin(angle_i));
        }
        lim++;
    }
}
void fft(vector<base> &a, int n = -1) {
    if (n == -1) n = a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = lim - zeros;
    for (int i = 0; i < n; i++) if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                base z = a[i + j + k] * roots[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
        }
    }
}
//eq = 0: 4 FFTs in total
//eq = 1: 3 FFTs in total
vector<int> multiply(vector<int> &a, vector<int> &b, int eq = 0) {
    int need = a.size() + b.size() - 1;
    int p = 0;
    while ((1 << p) < need) p++;
    ensure_base(p);
    int sz = 1 << p;
    vector<base> A, B;
    if (sz > (int)A.size()) A.resize(sz);
    for (int i = 0; i < (int)a.size(); i++) {
        int x = (a[i] % mod + mod) % mod;
        A[i] = base(x & ((1 << 15) - 1), x >> 15);
    }
    fill(A.begin() + a.size(), A.begin() + sz, base{0, 0});
    fft(A, sz);
    if (sz > (int)B.size()) B.resize(sz);
    if (eq) copy(A.begin(), A.begin() + sz, B.begin());
    else {
        for (int i = 0; i < (int)b.size(); i++) {
            int x = (b[i] % mod + mod) % mod;
            B[i] = base(x & ((1 << 15) - 1), x >> 15);
        }
        fill(B.begin() + b.size(), B.begin() + sz, base{0, 0});
        fft(B, sz);
    }
    double ratio = 0.25 / sz;
    base r2(0,  - 1), r3(ratio, 0), r4(0,  - ratio), r5(0, 1);
    for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        base a1 = (A[i] + conj(A[j])), a2 = (A[i] - conj(A[j])) * r2;
        base b1 = (B[i] + conj(B[j])) * r3, b2 = (B[i] - conj(B[j])) * r4;
        if (i != j) {
            base c1 = (A[j] + conj(A[i])), c2 = (A[j] - conj(A[i])) * r2;
            base d1 = (B[j] + conj(B[i])) * r3, d2 = (B[j] - conj(B[i])) * r4;
            A[i] = c1 * d1 + c2 * d2 * r5;
            B[i] = c1 * d2 + c2 * d1;
        }
        A[j] = a1 * b1 + a2 * b2 * r5;
        B[j] = a1 * b2 + a2 * b1;
    }
    fft(A, sz); fft(B, sz);
    vector<int> res(need);
    for (int i = 0; i < need; i++) {
        long long aa = A[i].x + 0.5;
        long long bb = B[i].x + 0.5;
        long long cc = A[i].y + 0.5;
        res[i] = (aa + ((bb % mod) << 15) + ((cc % mod) << 30)) % mod;
    }
    return res;
}
template <int32_t MOD>
struct modint {
    int32_t value;
    modint() = default;
    modint(int32_t value_) : value(value_) {}
    inline modint<MOD> operator + (modint<MOD> other) const { int32_t c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
    inline modint<MOD> operator - (modint<MOD> other) const { int32_t c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
    inline modint<MOD> operator * (modint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
    inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
    inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
    modint<MOD> pow(uint64_t k) const {
        modint<MOD> x = *this, y = 1;
        for (; k; k >>= 1) {
            if (k & 1) y *= x;
            x *= x;
        }
        return y;
    }
    modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
    inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
    inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
    inline bool operator == (modint<MOD> other) const { return value == other.value; }
    inline bool operator != (modint<MOD> other) const { return value != other.value; }
    inline bool operator < (modint<MOD> other) const { return value < other.value; }
    inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }
 
using mint = modint<mod>;
struct poly {
    vector<mint> a;
    inline void normalize() {
        while ((int)a.size() && a.back() == 0 &&((int)a.size() > 1)) a.pop_back();
    }
    template<class...Args> poly(Args...args): a(args...) { }
    poly(const initializer_list<mint> &x): a(x.begin(), x.end()) { }
    int size() const { return (int)a.size(); }
    inline mint coef(const int i) const { return (i < a.size() && i >= 0) ? a[i] : mint(0); }
    mint operator[](const int i) const { return (i < a.size() && i >= 0) ? a[i] : mint(0); } //Beware!! p[i] = k won't change the value of p.a[i]
    bool is_zero() const {
        for (int i = 0; i < size(); i++) if (a[i] != 0) return 0;
        return 1;
    }
    poly operator + (const poly &x) const {
        int n = max(size(), x.size());
        vector<mint> ans(n);
        for (int i = 0; i < n; i++) ans[i] = coef(i) + x.coef(i);
        while ((int)ans.size() && ans.back() == 0) ans.pop_back();
        return ans;
    }
    poly operator - (const poly &x) const {
        int n = max(size(), x.size());
        vector<mint> ans(n);
        for (int i = 0; i < n; i++) ans[i] = coef(i) - x.coef(i);
        while ((int)ans.size() && ans.back() == 0) ans.pop_back();
        return ans;
    }
    poly operator * (const poly& b) const {
        if (is_zero() || b.is_zero()) return {};
        vector<int> A, B;
        for (auto x : a) A.push_back(x.value);
        for (auto x : b.a) B.push_back(x.value);
        // for (auto x : a) A.push_back(x);
        // for (auto x : b.a) B.push_back(x);
        auto res = multiply(A, B, (A == B));
        vector<mint> ans;
        for (auto x : res) ans.push_back(mint(x));
        while ((int)ans.size() && ans.back() == 0) ans.pop_back();
        return ans;
    }
    poly operator * (const mint& x) const {
        int n = size();
        vector<mint> ans(n);
        for (int i = 0; i < n; i++) ans[i] = a[i] * x;
        return ans;
    }
    poly operator / (const mint &x) const { return (*this) * x.inv(); }
    poly& operator += (const poly &x) { return *this = (*this) + x; }
    poly& operator -= (const poly &x) { return *this = (*this) - x; }
    poly& operator *= (const poly &x) { return *this = (*this) * x; }
    poly& operator *= (const mint &x) { return *this = (*this) * x; }
    poly& operator /= (const mint &x) { return *this = (*this) / x; }
    poly mod_xk(int k) const { return {a.begin(), a.begin() + min(k, size())}; } //modulo by x^k
    poly mul_xk(int k) const { // multiply by x^k
        poly ans(*this);
        ans.a.insert(ans.a.begin(), k, 0);
        return ans;
    }
    poly div_xk(int k) const { // divide by x^k
        return vector<mint>(a.begin() + min(k, (int)a.size()), a.end());
    }
    poly substr(int l, int r) const { // return mod_xk(r).div_xk(l)
        l = min(l, size());
        r = min(r, size());
        return vector<mint>(a.begin() + l, a.begin() + r);
    }
    poly reverse_it(int n, bool rev = 0) const { // reverses and leaves only n terms
        poly ans(*this);
        if (rev) { // if rev = 1 then tail goes to head
            ans.a.resize(max(n, (int)ans.a.size()));
        }
        reverse(ans.a.begin(), ans.a.end());
        return ans.mod_xk(n);
    }
    poly differentiate() const {
        int n = size(); vector<mint> ans(n);
        for (int i = 1; i < size(); i++) ans[i - 1] = coef(i) * i;
        return ans;
    }
    poly inverse(int n) const {  // 1 / p(x) % x^n, O(nlogn)
        assert(!is_zero()); assert(a[0] != 0);
        poly ans{mint(1) / a[0]};
        for (int i = 1; i < n; i *= 2) {
            ans = (ans * mint(2) - ans * ans * mod_xk(2 * i)).mod_xk(2 * i);
        }
        return ans.mod_xk(n);
    }
    pair<poly, poly> divmod_slow(const poly &b) const { // when divisor or quotient is small
        vector<mint> A(a);
        vector<mint> ans;
        while (A.size() >= b.a.size()) {
            ans.push_back(A.back() / b.a.back());
            if (ans.back() != mint(0)) {
                for (size_t i = 0; i < b.a.size(); i++) {
                    A[A.size() - i - 1] -= ans.back() * b.a[b.a.size() - i - 1];
                }
            }
            A.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return {ans, A};
    }
    pair<poly, poly> divmod(const poly &b) const { // returns quotient and remainder of a mod b
        if (size() < b.size()) return {poly{0}, *this};
        int d = size() - b.size();
        if (min(d, b.size()) < 250) return divmod_slow(b);
        poly D = (reverse_it(d + 1) * b.reverse_it(d + 1).inverse(d + 1)).mod_xk(d + 1).reverse_it(d + 1, 1);
        return {D, *this - (D * b)};
    }
    poly operator / (const poly &t) const {return divmod(t).first;}
    poly operator % (const poly &t) const {return divmod(t).second;}
    poly& operator /= (const poly &t) {return *this = divmod(t).first;}
    poly& operator %= (const poly &t) {return *this = divmod(t).second;}
    mint eval(mint x) { // evaluates in single point x
        mint ans(0);
        for (int i = (int)size() - 1; i >= 0; i--) {
            ans *= x;
            ans += a[i];
        }
        return ans;
    }
    poly build(vector<poly> &ans, int v, int l, int r, vector<mint> &vec) { //builds evaluation tree for (x-a1)(x-a2)...(x-an)
        if (l == r) return ans[v] = poly({ -vec[l], 1});
        int mid = (l + r) >> 1;
        return ans[v] = build(ans, 2 * v, l, mid, vec) * build(ans, 2 * v + 1, mid + 1, r, vec);
    }
    vector<mint> eval(vector<poly> &tree, int v, int l, int r, vector<mint> &vec) { // auxiliary evaluation function
        if (l == r) return {eval(vec[l])};
        if (size() < 100) {
            vector<mint> ans(r - l + 1, 0);
            for (int i = l; i <= r; i++) ans[i - l] = eval(vec[i]);
            return ans;
        }
        int mid = (l + r) >> 1;
        auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, mid, vec);
        auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, mid + 1, r, vec);
        A.insert(A.end(), B.begin(), B.end());
        return A;
    }
    //O(nlog^2n)
    vector<mint> eval(vector<mint> x) {// evaluate polynomial in (x_0, ..., x_n-1)
        int n = x.size();
        if (is_zero()) return vector<mint>(n, mint(0));
        vector<poly> tree(4 * n);
        build(tree, 1, 0, n - 1, x);
        return eval(tree, 1, 0, n - 1, x);
    }
};
 
mint fact[N], a[N];
void preprocess() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i);
}
 
poly mult(int l, int r) {
    if (l == r) {
        return poly({a[l] + 1, mod - 2});
    }
    int mid = (l + r) >> 1;
    return mult(l, mid) * mult(mid + 1, r);
}

poly generate(int a, int val) {
    int l = max(1, 239 * a);
    vector<mint> a1(l, 0);
    for(int i=0;i<l;i+=a) {
        a1[i] = val;
    }
    return poly(a1);
}

poly generate2(int a) {
    int l = max(1, 239 * a);
    vector<mint> a1(l);
    for(int i=239;i<l;i+=a) {
        a1[i] = 1;
    }
    return poly(a1);
}

poly gensecond(int n) {
    vector<mint> tmp = {1};
    poly res(tmp);

    for(int i=1;i<=n;i++) {
        res *= generate(1, 1);
    }
    return res;
}
 
int main()
{
    boost;
    preprocess(); //For calculating factorial values % mod
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n;
    //     cin >> n;
    //     mint P = 0, Q = 1;  // P = numerator, Q = denominator, Final_ans = P/Q
    //     int m = INT_MAX;
    //     for (int i = 1; i <= n; i++) {
    //         int num; cin >> num;
    //         a[i] = num;
    //         Q *= (a[i] + 1);
    //         m = min(num , m);
    //     }
    //     if (m < 2) {
    //         cout << 0 << '\n';
    //         continue;
    //     }
    //     m /= 2;
 
    //     // (a1 - 2x + 1)(a2 - 2x + 1)...(an - 2x + 1)
    //     poly G = mult(1, n);  //Using Divide and conquer, FFT  : O(n.(log^2)(n))
 
    //     //Calculation of A(i,m) using exponential generating function :
    //     vector<mint> f1(n + 1);   //   e^x
    //     for (int i = 0; i <= n; i++) f1[i] = mint(1) / fact[i];
 
    //     vector<mint> f2(n + 1); // (e^(nx)-1)/x
    //     mint temp = m;
    //     for (int i = 0; i <= n; i++) {
    //         f2[i] = (temp / fact[i + 1]);
    //         temp *= m;
    //     }
 
    //     vector<mint> f3(n + 1);   //  (e^x-1)/x
    //     for (int i = 0; i <= n; i++) f3[i] = mint(1) / fact[i + 1];
 
    //     poly P1(f1);
    //     poly P2(f2);
    //     poly P3(f3);
 
    //     // A[i] = A(i,m) i.e sum of powers
    //     vector<mint> A = (P1 * P2 * (P3.inverse(n + 1))).a;
    //     for (int i = 0; i <= n ; i++) {
    //         A[i] *= fact[i];
    //     }
 
    //     // P = Numerator = summation(G[i].A(i,m) = Summation (G[i] . A[i])
    //     for (int i = 0; i <= n; i++)
    //         P += (G[i] * A[i]);
 
    //     cout << P / Q << '\n';
    // }
    // return 0;

    // vector<mint> a1(239,0);
    // vector<mint> a2(239,0);
    // vector<mint> a3(239,0);
    // a1[0] = 1;
    // a2[0] = 1;
    // a3[0] = 1;

    // poly A1(a1);
    // poly A2(a2);
    // poly A3(a3);

    // vector<mint> A = (A1 * A2 * A3).a;

    // cerr << A.size() << '\n';

    // mint ans = 0;

    // for(int i=0;i<A.size();i+=239) {
    //     ans += A[i];
    // }

    // cerr << ans << '\n';

    // cerr << 239 * 238 * 237 << '\n';

    int n;
    cin >> n;
    vector<int> a;
    int zeros = 0;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        if(tmp == 0) {
            zeros++;
        }
        else {
            a.push_back(1);
        }
    }

    vector<mint> ans = {1};
    poly A(ans);
    vector<poly> cache;
    for(int i=0;i<int(a.size());i++) {
        A = A * generate(1, 1);
    }

    // P(x)^3 - 3 * P(x^2)*P(x) + 2 * P(x^3)

    vector<mint> tmp = {1};
    poly Extra(tmp);

    // 1 means add, 0 means mult

    // for(int i = 1; i < (1 << int(a.size())); i++) {
    //     if(__builtin_popcount(i) >= 2) {
    //     // {
    //         int ones = __builtin_popcount(i);
    //         vector<mint> mul = {1};
    //         int sum = 0;
    //         poly MUL(mul);
    //         for(int j=0;j<int(a.size());j++) {
    //             if((i & (1 << j)) != 0) {
    //                 sum += a[j];
    //             }   
    //             else {
    //                 MUL = MUL * generate(a[j], 1);
    //             }
    //         }
    //         cerr << "sum now: " << sum << '\n';
    //         int k = ones - 1;
    //         // if(ones & 1) {
    //         //     k *= -1;
    //         // }
    //         sum *= k;
    //         cerr << "sum after: " << sum << '\n';
    //         if(ones & 1){
    //             Extra = Extra - (MUL * generate(sum, 1));
    //         }
    //         else {
    //             Extra = Extra + (MUL * generate(sum, 1));
    //         }
    //     }
    // }

    // A -= Extra;
    int diff = n;
    for(int i=2;i<=n;i++) {
        poly TMP;
        if(i & 1) {
            TMP = generate(i, -1) * gensecond(n - i);
            n--;
        }
        else {
            TMP = generate(i, +1) * gensecond(n - i);
            n--;
        }
        
        for(int i=1;i<=n;i++) {
            A -= TMP;
        }
    }

    vector<mint> last = A.a;

    mint req = 0;
    // int i = 236;
    // int c = 2;
    // while(i < last.size()) {
    //     req += last[i];
    //     // cerr << last[i] << '\n';
    //     i = c * 239 - 3;
    //     c++;
    // }

    for(int i=0;i<last.size();i+=239) {
        req += last[i];
    }

    // cerr << last[236] << '\n';
    // // if(req != 1) {
    // //     req += 3;
    // // }

    int non_zero = n - zeros;
    for(int i=0;i<zeros;i++) {
        req *= (239 - non_zero - i);
    }

    cout << req << '\n';
} 