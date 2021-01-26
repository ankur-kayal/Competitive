#include <bits/stdc++.h>
#include <cmath>
#include <complex>
#include <functional>
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

//----------------------------------- END DEFINES -------------------------------- 

using cd = complex<double>;

const double PI = acos(-1);

template <class T>
void bit_reversal_sort(vector<T>& a) {
    int n = a.size();
    for(int i=0;i<n;i++) {
        int rev = 0;
        for(int j=0;j<__builtin_ctz(n);j++) {
            if((i & (1 << j)) != 0) {
                rev |= (1 << (__builtin_ctz(n) - j - 1));
            }
        }
        if(rev > i) {
            swap(a[i], a[rev]);
        }
    }
}   

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if(n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for(int i=0;2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));

    for(int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if(invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }

}

void fft_iterative(vector<cd>& a, bool invert) {
    int n = a.size();

    bit_reversal_sort(a);
    for(int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang)); 
        for(int i=0;i<n;i += len) {
            cd w(1);
            for(int j=0;j<len / 2;j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if(invert) {
        for(cd &x: a) {
            x /= n;
        }
    }
}

vector<int64_t> multiply(vector<int64_t> const& a, vector<int64_t> const& b) {
    vector<cd> fa(all(a)), fb(all(b));
    int n = 1;
    while(n < a.size() + b.size()) {
        n <<= 1;
    }
    fa.resize(n);
    fb.resize(n);

    // fft(fa, false);
    // fft(fb, false);

    fft_iterative(fa, false);
    fft_iterative(fb, false);

    for(int i=0;i<n;i++) {
        fa[i] *= fb[i];
    }

    // fft(fa, true);
    fft_iterative(fa, true);

    vector<int64_t> result(n);
    debug() << imie(fa);
    for(int i=0;i<n;i++) {
        result[i] = round(fa[i].real());
    }
    while(result.back() == 0) {
        result.pop_back();
    }
    return result;
}

void run_cases() {
    int n;
    cin >> n;
    vector<int64_t> a(n + 1), b(n + 1);
    trav(u, a) cin >> u;
    trav(u, b) cin >> u;
    reverse(all(a));
    reverse(all(b));
    debug() << imie(a) << '\n' << imie(b);

    vector<int64_t> res = multiply(a,b);
    reverse(all(res));
    for(auto u: res) {
        cout << u << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}