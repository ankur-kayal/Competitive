#include <algorithm>
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
    int N;
    cin >> N;
    vector<int> gap(N);
    for(auto &u: gap) {
        cin >> u;
    }

    debug() << imie(gap);

    int ans = 0;

    vector<int> dp(100100, 0);
    dp[0] = 1;
    for(int i = 1; i < 100000; i++) {
        for(auto u: gap) {
            if(i - u >= 0) {
                dp[i] = max(dp[i], dp[i - u]);
            }
        }
    }

    const int maxN = 100000;

    for(int i = 0; i < maxN; i++) {
        bool ok = true;
        vector<int> A(maxN, 1);
        // iota(A.begin(), A.end(), 1);

        A[i] = 0;

        for(int u: gap) {
            int j;
            for(int k = u; k < maxN; k++) {
                int tmp = A[k];

                for(j = k; j >= u && A[j - u] > tmp; j -= u) {
                    A[j] = A[j - u];
                }
                A[j] = tmp;
            }

            // debug() << imie(A) imie(i);
        }

        // debug() << imie(A);

        if(!is_sorted(A.begin(), A.end())) {
            if(dp[i] == 1) {
                debug() << imie(i);
            }
        } else {          
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}