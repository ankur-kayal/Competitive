#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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

//https://judge.yosupo.jp/submission/3207
// const int N = 100005;
const int mod = 998244353;
struct base
{
    double x, y;
    base() { x = y = 0; }
    base(double x, double y) : x(x), y(y) {}
};
inline base operator+(base a, base b) { return base(a.x + b.x, a.y + b.y); }
inline base operator-(base a, base b) { return base(a.x - b.x, a.y - b.y); }
inline base operator*(base a, base b) { return base(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline base conj(base a) { return base(a.x, -a.y); }
int lim = 1;
vector<base> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};
const double PI = acosl(-1.0);
void ensure_base(int p)
{
    if (p <= lim)
        return;
    rev.resize(1 << p);
    for (int i = 0; i < (1 << p); i++)
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (p - 1));
    roots.resize(1 << p);
    while (lim < p)
    {
        double angle = 2 * PI / (1 << (lim + 1));
        for (int i = 1 << (lim - 1); i < (1 << lim); i++)
        {
            roots[i << 1] = roots[i];
            double angle_i = angle * (2 * i + 1 - (1 << lim));
            roots[(i << 1) + 1] = base(cos(angle_i), sin(angle_i));
        }
        lim++;
    }
}
void fft(vector<base> &a, int n = -1)
{
    if (n == -1)
        n = a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = lim - zeros;
    for (int i = 0; i < n; i++)
        if (i < (rev[i] >> shift))
            swap(a[i], a[rev[i] >> shift]);
    for (int k = 1; k < n; k <<= 1)
    {
        for (int i = 0; i < n; i += 2 * k)
        {
            for (int j = 0; j < k; j++)
            {
                base z = a[i + j + k] * roots[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
        }
    }
}
//eq = 0: 4 FFTs in total
//eq = 1: 3 FFTs in total
vector<int> multiply(vector<int> &a, vector<int> &b, int eq = 0)
{
    int need = a.size() + b.size() - 1;
    int p = 0;
    while ((1 << p) < need)
        p++;
    ensure_base(p);
    int sz = 1 << p;
    vector<base> A, B;
    if (sz > (int)A.size())
        A.resize(sz);
    for (int i = 0; i < (int)a.size(); i++)
    {
        int x = (a[i] % mod + mod) % mod;
        A[i] = base(x & ((1 << 15) - 1), x >> 15);
    }
    fill(A.begin() + a.size(), A.begin() + sz, base{0, 0});
    fft(A, sz);
    if (sz > (int)B.size())
        B.resize(sz);
    if (eq)
        copy(A.begin(), A.begin() + sz, B.begin());
    else
    {
        for (int i = 0; i < (int)b.size(); i++)
        {
            int x = (b[i] % mod + mod) % mod;
            B[i] = base(x & ((1 << 15) - 1), x >> 15);
        }
        fill(B.begin() + b.size(), B.begin() + sz, base{0, 0});
        fft(B, sz);
    }
    double ratio = 0.25 / sz;
    base r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
    for (int i = 0; i <= (sz >> 1); i++)
    {
        int j = (sz - i) & (sz - 1);
        base a1 = (A[i] + conj(A[j])), a2 = (A[i] - conj(A[j])) * r2;
        base b1 = (B[i] + conj(B[j])) * r3, b2 = (B[i] - conj(B[j])) * r4;
        if (i != j)
        {
            base c1 = (A[j] + conj(A[i])), c2 = (A[j] - conj(A[i])) * r2;
            base d1 = (B[j] + conj(B[i])) * r3, d2 = (B[j] - conj(B[i])) * r4;
            A[i] = c1 * d1 + c2 * d2 * r5;
            B[i] = c1 * d2 + c2 * d1;
        }
        A[j] = a1 * b1 + a2 * b2 * r5;
        B[j] = a1 * b2 + a2 * b1;
    }
    fft(A, sz);
    fft(B, sz);
    vector<int> res(need);
    for (int i = 0; i < need; i++)
    {
        long long aa = A[i].x + 0.5;
        long long bb = B[i].x + 0.5;
        long long cc = A[i].y + 0.5;
        res[i] = (aa + ((bb % mod) << 15) + ((cc % mod) << 30)) % mod;
    }
    return res;
}
template <int32_t MOD>
struct modint
{
    int32_t value;
    modint() = default;
    modint(int32_t value_) : value(value_) {}
    inline modint<MOD> operator+(modint<MOD> other) const
    {
        int32_t c = this->value + other.value;
        return modint<MOD>(c >= MOD ? c - MOD : c);
    }
    inline modint<MOD> operator-(modint<MOD> other) const
    {
        int32_t c = this->value - other.value;
        return modint<MOD>(c < 0 ? c + MOD : c);
    }
    inline modint<MOD> operator*(modint<MOD> other) const
    {
        int32_t c = (int64_t)this->value * other.value % MOD;
        return modint<MOD>(c < 0 ? c + MOD : c);
    }
    inline modint<MOD> &operator+=(modint<MOD> other)
    {
        this->value += other.value;
        if (this->value >= MOD)
            this->value -= MOD;
        return *this;
    }
    inline modint<MOD> &operator-=(modint<MOD> other)
    {
        this->value -= other.value;
        if (this->value < 0)
            this->value += MOD;
        return *this;
    }
    inline modint<MOD> &operator*=(modint<MOD> other)
    {
        this->value = (int64_t)this->value * other.value % MOD;
        if (this->value < 0)
            this->value += MOD;
        return *this;
    }
    inline modint<MOD> operator-() const { return modint<MOD>(this->value ? MOD - this->value : 0); }
    modint<MOD> pow(uint64_t k) const
    {
        modint<MOD> x = *this, y = 1;
        for (; k; k >>= 1)
        {
            if (k & 1)
                y *= x;
            x *= x;
        }
        return y;
    }
    modint<MOD> inv() const { return pow(MOD - 2); } // MOD must be a prime
    inline modint<MOD> operator/(modint<MOD> other) const { return *this * other.inv(); }
    inline modint<MOD> operator/=(modint<MOD> other) { return *this *= other.inv(); }
    inline bool operator==(modint<MOD> other) const { return value == other.value; }
    inline bool operator!=(modint<MOD> other) const { return value != other.value; }
    inline bool operator<(modint<MOD> other) const { return value < other.value; }
    inline bool operator>(modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD>
modint<MOD> operator*(int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD>
modint<MOD> operator*(int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD>
ostream &operator<<(ostream &out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;
struct poly
{
    vector<mint> a;
    inline void normalize()
    {
        while ((int)a.size() && a.back() == 0)
            a.pop_back();
    }
    template <class... Args>
    poly(Args... args) : a(args...) {}
    poly(const initializer_list<mint> &x) : a(x.begin(), x.end()) {}
    int size() const { return (int)a.size(); }
    inline mint coef(const int i) const { return (i < a.size() && i >= 0) ? a[i] : mint(0); }
    mint operator[](const int i) const { return (i < a.size() && i >= 0) ? a[i] : mint(0); } //Beware!! p[i] = k won't change the value of p.a[i]
    bool is_zero() const
    {
        for (int i = 0; i < size(); i++)
            if (a[i] != 0)
                return 0;
        return 1;
    }
    poly operator+(const poly &x) const
    {
        int n = max(size(), x.size());
        vector<mint> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = coef(i) + x.coef(i);
        while ((int)ans.size() && ans.back() == 0)
            ans.pop_back();
        return ans;
    }
    poly operator-(const poly &x) const
    {
        int n = max(size(), x.size());
        vector<mint> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = coef(i) - x.coef(i);
        while ((int)ans.size() && ans.back() == 0)
            ans.pop_back();
        return ans;
    }
    poly operator*(const poly &b) const
    {
        if (is_zero() || b.is_zero())
            return {};
        vector<int> A, B;
        for (auto x : a)
            A.push_back(x.value);
        for (auto x : b.a)
            B.push_back(x.value);
        auto res = multiply(A, B, (A == B));
        vector<mint> ans;
        for (auto x : res)
            ans.push_back(mint(x));
        while ((int)ans.size() && ans.back() == 0)
            ans.pop_back();
        return ans;
    }
    poly operator*(const mint &x) const
    {
        int n = size();
        vector<mint> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = a[i] * x;
        return ans;
    }
    poly operator/(const mint &x) const { return (*this) * x.inv(); }
    poly &operator+=(const poly &x) { return *this = (*this) + x; }
    poly &operator-=(const poly &x) { return *this = (*this) - x; }
    poly &operator*=(const poly &x) { return *this = (*this) * x; }
    poly &operator*=(const mint &x) { return *this = (*this) * x; }
    poly &operator/=(const mint &x) { return *this = (*this) / x; }
    poly mod_xk(int k) const { return {a.begin(), a.begin() + min(k, size())}; } //modulo by x^k
    poly mul_xk(int k) const
    { // multiply by x^k
        poly ans(*this);
        ans.a.insert(ans.a.begin(), k, 0);
        return ans;
    }
    poly div_xk(int k) const
    { // divide by x^k
        return vector<mint>(a.begin() + min(k, (int)a.size()), a.end());
    }
    poly substr(int l, int r) const
    { // return mod_xk(r).div_xk(l)
        l = min(l, size());
        r = min(r, size());
        return vector<mint>(a.begin() + l, a.begin() + r);
    }
    poly reverse_it(int n, bool rev = 0) const
    { // reverses and leaves only n terms
        poly ans(*this);
        if (rev)
        { // if rev = 1 then tail goes to head
            ans.a.resize(max(n, (int)ans.a.size()));
        }
        reverse(ans.a.begin(), ans.a.end());
        return ans.mod_xk(n);
    }
    poly differentiate() const
    {
        int n = size();
        vector<mint> ans(n);
        for (int i = 1; i < size(); i++)
            ans[i - 1] = coef(i) * i;
        return ans;
    }
    poly inverse(int n) const
    { // 1 / p(x) % x^n, O(nlogn)
        assert(!is_zero());
        assert(a[0] != 0);
        poly ans{mint(1) / a[0]};
        for (int i = 1; i < n; i *= 2)
        {
            ans = (ans * mint(2) - ans * ans * mod_xk(2 * i)).mod_xk(2 * i);
        }
        return ans.mod_xk(n);
    }
    pair<poly, poly> divmod_slow(const poly &b) const
    { // when divisor or quotient is small
        vector<mint> A(a);
        vector<mint> ans;
        while (A.size() >= b.a.size())
        {
            ans.push_back(A.back() / b.a.back());
            if (ans.back() != mint(0))
            {
                for (size_t i = 0; i < b.a.size(); i++)
                {
                    A[A.size() - i - 1] -= ans.back() * b.a[b.a.size() - i - 1];
                }
            }
            A.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return {ans, A};
    }
    pair<poly, poly> divmod(const poly &b) const
    { // returns quotient and remainder of a mod b
        if (size() < b.size())
            return {poly{0}, *this};
        int d = size() - b.size();
        if (min(d, b.size()) < 250)
            return divmod_slow(b);
        poly D = (reverse_it(d + 1) * b.reverse_it(d + 1).inverse(d + 1)).mod_xk(d + 1).reverse_it(d + 1, 1);
        return {D, *this - (D * b)};
    }
    poly operator/(const poly &t) const { return divmod(t).first; }
    poly operator%(const poly &t) const { return divmod(t).second; }
    poly &operator/=(const poly &t) { return *this = divmod(t).first; }
    poly &operator%=(const poly &t) { return *this = divmod(t).second; }
    mint eval(mint x)
    { // evaluates in single point x
        mint ans(0);
        for (int i = (int)size() - 1; i >= 0; i--)
        {
            ans *= x;
            ans += a[i];
        }
        return ans;
    }
    poly build(vector<poly> &ans, int v, int l, int r, vector<mint> &vec)
    { //builds evaluation tree for (x-a1)(x-a2)...(x-an)
        if (l == r)
            return ans[v] = poly({-vec[l], 1});
        int mid = l + r >> 1;
        return ans[v] = build(ans, 2 * v, l, mid, vec) * build(ans, 2 * v + 1, mid + 1, r, vec);
    }
    vector<mint> eval(vector<poly> &tree, int v, int l, int r, vector<mint> &vec)
    { // auxiliary evaluation function
        if (l == r)
            return {eval(vec[l])};
        if (size() < 100)
        {
            vector<mint> ans(r - l + 1, 0);
            for (int i = l; i <= r; i++)
                ans[i - l] = eval(vec[i]);
            return ans;
        }
        int mid = l + r >> 1;
        auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, mid, vec);
        auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, mid + 1, r, vec);
        A.insert(A.end(), B.begin(), B.end());
        return A;
    }
    //O(nlog^2n)
    vector<mint> eval(vector<mint> x)
    { // evaluate polynomial in (x_0, ..., x_n-1)
        int n = x.size();
        if (is_zero())
            return vector<mint>(n, mint(0));
        vector<poly> tree(4 * n);
        build(tree, 1, 0, n - 1, x);
        return eval(tree, 1, 0, n - 1, x);
    }
};

vector<mint> fact(1, 1);
vector<mint> inv_fact(1, 1);

mint C(int n, int k) {
    if(k < 0 || k > n) {
        return 0;
    }
    while((int) fact.size() < n + 1) {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(mint(1) / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n-k];

}

const int maxN = 2e5+10;

vector<vector<mint>> memo(maxN, vector<mint>(30, 0));
vector<int> cntBits(30, 0);

void calculate_factorials() {
    while((int) fact.size() < maxN) {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(mint(1) / fact.back());
    }
}

void preprocess(int n) {
    for(int i=1;i<=n;i++) {
        for(int bit = 0;bit < 30; bit++) {
            int cnt = cntBits[bit];
            for(int j = 1;j <= min(cnt, i); j += 2) {
                memo[i][bit] += C(cnt, j) * C(n - cnt, i - j);
            }
            memo[i][bit] *= (1 << bit);
        }
    }
}

/*
0 3 6 7 8 8 2 2 0 0 0 0 0 0 0 0 
9 502744279 100815631 121755358 1 450730920 447150503 550380287 1 655538614 551093848 266172242 1 693049506 897428720 752606214 
0 2 6 8 8 8 0 0 
16 574160085 86583719 384780647 2 729658871 911660636 307889091 
0 1 4 7 8 8 0 0 
28 981717182 346334874 662181212 4 800843811 651909483 549990826 
*/


void preprocess2(int n) {
    calculate_factorials();
    for(int bit = 0; bit < 30; bit++) {
        if(!cntBits[bit]) continue;

        int cnt = cntBits[bit];

        vector<mint> poly1(cnt + 1, 0);
        for(int i=1;i<=cnt;i+=2) {
            poly1[i] = C(cnt, i);
        }

        mint tmp = C(n - cnt, 0);

        vector<mint> poly2(n + 1, 0);
        poly2[0] = tmp;
        for(int i=1;i<=n;i++) {
            tmp += C(n - cnt, i);
            poly2[i] = tmp;
        }

        poly P1(poly1);
        poly P2(poly2);

        // poly1 *= poly2;
        poly1 = (P1 * P2).a;
        // poly1 = multiply(poly1, poly2);
        // debug() << imie(poly1) << nl << imie(poly2);

        for(int i=1;i<=n;i++) {
            memo[i][bit] = poly1[i] * (1 << bit);
        }
    } 
}

void run_cases() {
    int n;
    cin >> n;
    vector<int> a(n);
    trav(u, a) cin >> u;
    for(auto u: a) {
        for(int bit = 0;bit < 30;bit++) {
            if((u & (1 << bit)) != 0) {
                cntBits[bit]++;
            }
        }
    }

    preprocess2(n);


    vector<mint> ans(n + 1);
    for(int i=1;i<=n;i++) {
        for(int bit = 0; bit < 30; bit++) {
            ans[i] += memo[i][bit];
        }
    }
    // debug() << imie(ans);

    int Q;
    cin >> Q;
    while(Q--) {
        int m;
        cin >> m;
        cout << ans[m] << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    auto start = high_resolution_clock::now();

    int tests = 1;
    // cin >> tests;
    // preprocess();

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }

    auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<milliseconds>(stop - start); 
   
    // cout << duration.count() << endl; 
    debug() << imie(duration.count());
}

