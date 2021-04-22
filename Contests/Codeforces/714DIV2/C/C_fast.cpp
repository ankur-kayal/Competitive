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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 

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
#define Reminder __FILE__ "(" $Line ") : Warning: "

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

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U& x) {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U& x) {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }

    const Type& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
    Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
    template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
    template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    Modular operator++(int) { Modular result(*this); *this += 1; return result; }
    Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
          "divl %4; \n\t"
          : "=a" (d), "=d" (m)
          : "d" (xh), "a" (xl), "r" (mod())
        );
        value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }

    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

    template <typename U>
    friend const Modular<U>& abs(const Modular<U>& v) { return v; }

    template <typename U>
    friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

    template <typename U>
    friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

private:
    Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
    return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
    return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    while ((int) fact.size() < n + 1) {
        fact.push_back(fact.back() * (int) fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}

struct mod_matrix_fixed_size {
    static const int SIZE = 10;
 
    Mint values[SIZE][SIZE];
 
    mod_matrix_fixed_size() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                values[i][j] = 0;
    }
 
    template<typename T>
    mod_matrix_fixed_size(const vector<vector<T>> &v) {
        init(v);
    }
 
    template<typename T>
    void init(const vector<vector<T>> &v) {
        assert(v.size() == SIZE);
 
        for (int i = 0; i < SIZE; i++) {
            assert(v[i].size() == SIZE);
 
            for (int j = 0; j < SIZE; j++)
                values[i][j] = v[i][j];
        }
    }
 
    Mint *operator[](int index) { return values[index]; }
    const Mint *operator[](int index) const { return values[index]; }
 
    void make_identity() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                values[i][j] = i == j ? 1 : 0;
    }
 
    mod_matrix_fixed_size operator*(const mod_matrix_fixed_size &other) const {
        mod_matrix_fixed_size product;
 
        for (int i = 0; i < SIZE; i++)
            for (int k = 0; k < SIZE; k++) {
                uint64_t result = 0;
 
                for (int j = 0; j < SIZE; j++)
                    result += uint64_t(values[i][j]) * uint64_t(other[j][k]);
 
                product[i][k] = result;
            }
 
        return product;
    }
 
    mod_matrix_fixed_size& operator*=(const mod_matrix_fixed_size &other) {
        return *this = *this * other;
    }
 
    mod_matrix_fixed_size power(int64_t p) const {
        assert(p >= 0);
        mod_matrix_fixed_size m = *this;
        mod_matrix_fixed_size result;
        result.make_identity();
 
        while (p > 0) {
            if (p & 1)
                result *= m;
 
            p >>= 1;
 
            if (p > 0)
                m *= m;
        }
 
        return result;
    }
 
    void print() const {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                cout << values[i][j] << (j < SIZE - 1 ? ' ' : '\n');
    }
};

const int maxM = 2e5 + 100;
array<mod_matrix_fixed_size, maxM> precompute; 

void run_cases() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    mod_matrix_fixed_size ans;

    // vector<vector<Mint>> dp(m + 1, vector<Mint>(10));
    while(n > 0) {
        int d = n % 10;
        ans[0][d] += 1;
        n /= 10;
    }
    // for(int i=1;i<=m;i++) {
    //     dp[i][0] += dp[i-1][9];
    //     dp[i][1] += dp[i-1][9] + dp[i-1][0];
    //     dp[i][2] += dp[i-1][1];
    //     dp[i][3] += dp[i-1][2];
    //     dp[i][4] += dp[i-1][3];
    //     dp[i][5] += dp[i-1][4];
    //     dp[i][6] += dp[i-1][5];
    //     dp[i][7] += dp[i-1][6];
    //     dp[i][8] += dp[i-1][7];
    //     dp[i][9] += dp[i-1][8];
    // }

    // Matrix<Mint, 10> base;
    // base[9][0] = 1;
    // base[9][1] = 1;
    // for(int i=0;i<=8;i++) {
    //     base[i][i + 1] = 1;
    // }
    ans = ans * precompute[m];
    // for(int i=0;i<=m;i++) {
    //     debug() << imie(i) imie(dp[i]);
    // }

    Mint res = 0;
    for(int i=0;i<10;i++) {
        res += ans[0][i];
    }

    cout << res << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    mod_matrix_fixed_size base;
    base[9][0] = 1;
    base[9][1] = 1;
    for(int i=0;i<=8;i++) {
        base[i][i + 1] = 1;
    }

    precompute[0].make_identity();
    for(int i=1;i<=200000;i++) {
        precompute[i] = precompute[i-1] * base;
    }

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}