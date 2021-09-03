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
    int64_t n;
    cin >> n;

    auto solve = [](int64_t n, int64_t target) -> int {
        int times = 0;

        string N = to_string(n);
        string M = to_string(target);

        int matched = 0;

        int i = 0, j = 0;

        while(i < N.length() && j < M.length()) {
            if(N[i] == M[j]) {
                i++;
                j++;
                matched++;
            } else {
                i++;
            }
        }

        times = N.length() + M.length() - 2 * matched;

        return times;


    };

    /*
    67108864
    687194767
    */

    int ans = n;

    for(int i = 0; i <= 62; i++) {

        // debug() << imie(n) imie(1LL << i) imie(solve(n, 1LL << i));

        ans = min(ans, solve(n, 1LL << i));
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