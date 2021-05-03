#include <bits/stdc++.h>
using namespace std;

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

constexpr int md = @@HERE@@
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

template <typename T>
class NTT {
public:
    using Type = typename decay<decltype(T::value)>::type;

    static Type md;
    static Modular<T> root;
    static int base;
    static int max_base;
    static vector<Modular<T>> roots;
    static vector<int> rev;

    static void clear() {
        root = 0;
        base = 0;
        max_base = 0;
        roots.clear();
        rev.clear();
    }

    static void init() {
        md = T::value;
        assert(md >= 3 && md % 2 == 1);
        auto tmp = md - 1;
        max_base = 0;
        while (tmp % 2 == 0) {
            tmp /= 2;
            max_base++;
        }
        root = 2;
        while (power(root, (md - 1) >> 1) == 1) {
            root++;
        }
        assert(power(root, md - 1) == 1);
        root = power(root, (md - 1) >> max_base);
        base = 1;
        rev = {0, 1};
        roots = {0, 1};
    }

    static void ensure_base(int nbase) {
        if (md != T::value) {
            clear();
        }
        if (roots.empty()) {
            init();
        }
        if (nbase <= base) {
            return;
        }
        assert(nbase <= max_base);
        rev.resize(1 << nbase);
        for (int i = 0; i < (1 << nbase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        }
        roots.resize(1 << nbase);
        while (base < nbase) {
            Modular<T> z = power(root, 1 << (max_base - 1 - base));
            for (int i = 1 << (base - 1); i < (1 << base); i++) {
                roots[i << 1] = roots[i];
                roots[(i << 1) + 1] = roots[i] * z;
            }
            base++;
        }
    }

    static void fft(vector<Modular<T>> &a) {
        int n = (int) a.size();
        assert((n & (n - 1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) {
                swap(a[i], a[rev[i] >> shift]);
            }
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    Modular<T> x = a[i + j];
                    Modular<T> y = a[i + j + k] * roots[j + k];
                    a[i + j] = x + y;
                    a[i + j + k] = x - y;
                }
            }
        }
    }

    static vector<Modular<T>> multiply(vector<Modular<T>> a, vector<Modular<T>> b) {
        if (a.empty() || b.empty()) {
            return {};
        }
        int eq = (a == b);
        int need = (int) a.size() + (int) b.size() - 1;
        int nbase = 0;
        while ((1 << nbase) < need) nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        a.resize(sz);
        b.resize(sz);
        fft(a);
        if (eq) b = a; else fft(b);
        Modular<T> inv_sz = 1 / static_cast<Modular<T>>(sz);
        for (int i = 0; i < sz; i++) {
            a[i] *= b[i] * inv_sz;
        }
        reverse(a.begin() + 1, a.end());
        fft(a);
        a.resize(need);
        return a;
    }
};

template <typename T> typename NTT<T>::Type NTT<T>::md;
template <typename T> Modular<T> NTT<T>::root;
template <typename T> int NTT<T>::base;
template <typename T> int NTT<T>::max_base;
template <typename T> vector<Modular<T>> NTT<T>::roots;
template <typename T> vector<int> NTT<T>::rev;

template <typename T>
vector<Modular<T>> inverse(const vector<Modular<T>>& a) {
    assert(!a.empty());
    int n = (int) a.size();
    vector<Modular<T>> b = {1 / a[0]};
    while ((int) b.size() < n) {
        vector<Modular<T>> x(a.begin(), a.begin() + min(a.size(), b.size() << 1));
        x.resize(b.size() << 1);
        b.resize(b.size() << 1);
        vector<Modular<T>> c = b;
        NTT<T>::fft(c);
        NTT<T>::fft(x);
        Modular<T> inv = 1 / static_cast<Modular<T>>((int) x.size());
        for (int i = 0; i < (int) x.size(); i++) {
            x[i] *= c[i] * inv;
        }
        reverse(x.begin() + 1, x.end());
        NTT<T>::fft(x);
        rotate(x.begin(), x.begin() + (x.size() >> 1), x.end());
        fill(x.begin() + (x.size() >> 1), x.end(), 0);
        NTT<T>::fft(x);
        for (int i = 0; i < (int) x.size(); i++) {
            x[i] *= c[i] * inv;
        }
        reverse(x.begin() + 1, x.end());
        NTT<T>::fft(x);
        for (int i = 0; i < ((int) x.size() >> 1); i++) {
            b[i + ((int) x.size() >> 1)] = -x[i];
        }
    }
    b.resize(n);
    return b;
}

template <typename T>
vector<Modular<T>> inverse_old(vector<Modular<T>> a) {
    assert(!a.empty());
    int n = (int) a.size();
    if (n == 1) {
        return {1 / a[0]};
    }
    int m = (n + 1) >> 1;
    vector<Modular<T>> b = inverse(vector<Modular<T>>(a.begin(), a.begin() + m));
    int need = n << 1;
    int nbase = 0;
    while ((1 << nbase) < need) {
        ++nbase;
    }
    NTT<T>::ensure_base(nbase);
    int size = 1 << nbase;
    a.resize(size);
    b.resize(size);
    NTT<T>::fft(a);
    NTT<T>::fft(b);
    Modular<T> inv = 1 / static_cast<Modular<T>>(size);
    for (int i = 0; i < size; ++i) {
        a[i] = (2 - a[i] * b[i]) * b[i] * inv;
    }
    reverse(a.begin() + 1, a.end());
    NTT<T>::fft(a);
    a.resize(n);
    return a;
}

template <typename T>
vector<Modular<T>> operator*(const vector<Modular<T>>& a, const vector<Modular<T>>& b) {
    if (a.empty() || b.empty()) {
        return {};
    }
    if (min(a.size(), b.size()) < 150) {
        vector<Modular<T>> c(a.size() + b.size() - 1, 0);
        for (int i = 0; i < (int) a.size(); i++) {
            for (int j = 0; j < (int) b.size(); j++) {
                c[i + j] += a[i] * b[j];
            }
        }
        return c;
    }
    return NTT<T>::multiply(a, b);
}

template <typename T>
vector<Modular<T>>& operator*=(vector<Modular<T>>& a, const vector<Modular<T>>& b) {
    return a = a * b;
}

template <typename T>
vector<Modular<T>> mod_multiply_all(const vector<vector<Modular<T>>> &polynomials) {
    if (polynomials.empty()) {
        return {1};
    }

    struct compare_size {
        bool operator()(const vector<Modular<T>> &x, const vector<Modular<T>> &y) {
            return static_cast<int>(x.size()) > static_cast<int>(y.size());
        }
    };

    priority_queue<vector<Modular<T>>, vector<vector<Modular<T>>>, compare_size> pq;
    for(auto &poly : polynomials) {
        pq.push(poly);
    }
    while(pq.size() > 1) {
        vector<Modular<T>> a = pq.top(); pq.pop();
        vector<Modular<T>> b = pq.top(); pq.pop();
        a *= b;
        pq.push(a);
    }
    return pq.top();
}

template <typename T>
vector<Modular<T>> mod_power(const vector<Modular<T>> &v, int exponent) {
    assert(exponent >= 0);
    vector<Modular<T>> result = {1};

    if (exponent == 0) {
        return result;
    }

    for(int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
        result *= result;

        if(exponent >> k & 1) {
            result *= v;
        }
    }

    return result;
}