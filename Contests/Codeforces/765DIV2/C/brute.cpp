#include <bits/stdc++.h>
#include <inttypes.h>
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
    int N, L, K;
    cin >> N >> L >> K;

    vector<int64_t> D(N);
    for(auto &u: D)
        cin >> u;

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    int64_t ans = 1e18;

    int minE = N - K;

    for(int mask = 0; mask < (1 << N); mask++) {
        if(__builtin_popcount(mask) >= N - K && (mask & 1)) {
            vector<int64_t> nD;
            vector<int64_t> nA;
            for(int i = 0; i < N; i++) {
                if(mask >> i & 1) {
                    nD.push_back(D[i]);
                    nA.push_back(A[i]);
                }
            }
            nD.push_back(L);
            int64_t tmp = 0;
            for(int i = 1; i < nD.size(); i++) {
                tmp += nA[i - 1] * (nD[i] - nD[i - 1]);
            }
            ans = min(ans, tmp);

            debug() << imie(nD) imie(nA) imie(tmp);
        }
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