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

int64_t gcd(int64_t a, int64_t b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void run_cases() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    if(N == 1) {
        cout << 1 << '\n';
        return;
    }
    
    vector<int64_t> prefix(N + 1);
    for(int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + A[i];
    }

    vector<int64_t> suffix(N + 1);
    for(int i = N - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + A[i];
    }

    vector<int64_t> suffix_gcd;
    suffix_gcd.push_back(0);
    for(int i = N - 1; i >= 0; i--) {
        suffix_gcd.push_back(gcd(suffix_gcd.back(), A[i]));
    }

    // find the gcd of the entire array excluding the current element
    // reduce the current element to the gcd of the current entire array

    int64_t ans = 2e18;

    int64_t prefix_gcd = 0;

    debug() << imie(prefix) << nl << imie(suffix) << nl << imie(suffix_gcd);

    for(int i = 0; i < N; i++) {
        suffix_gcd.pop_back();
        int64_t array_gcd = gcd(prefix_gcd, suffix_gcd.back());
        int64_t count_deno = (prefix[i] + array_gcd + suffix[i + 1]) / array_gcd;
        ans = min(ans, count_deno);
        prefix_gcd = gcd(prefix_gcd, A[i]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}