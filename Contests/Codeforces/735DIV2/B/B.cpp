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

void run_cases() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    // (n - i) * (n - j) - k * (ai | aj)
    // (n^2 - n(i + j) + ij)

    int64_t cutoff = 1000;

    int64_t ans = -2e18;
    int64_t zero = 0;

    for(int64_t i = 0; i < min(cutoff, N); i++) {
        for(int64_t j = i + 1; j < min(cutoff, N); j++) {
            int64_t index1 = max(zero, N - i - 1);
            int64_t index2 = max(zero, N - j - 1);
            // debug() << imie(N) imie(index1) imie(index2);
            ans = max(ans, (index1 + 1) * (index2 + 1) - K * (A[index1] | A[index2]));
        }
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