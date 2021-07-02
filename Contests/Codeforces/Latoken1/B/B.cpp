#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int64_t INF64 = 1e18;


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
    vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int64_t ans = A[0];

    for(int i = 1; i < N; i++) {
        if(i == N - 1) {
            ans += A[i];
        } 

        ans += abs(A[i] - A[i - 1]);
    }

    debug() << imie(ans);

    int64_t moves = 0;

    for(int i = 0; i < N; i++) {
        int64_t threshold = 0;
        if(i - 1 >= 0) {
            threshold = max(threshold, A[i - 1]);
        }
        if(i + 1 < N) {
            threshold = max(threshold, A[i + 1]);
        }
        int64_t diff = max(int64_t(0), A[i] - threshold);
        if(diff > 0) {
            moves += diff;
        }
        A[i] -= diff;
        ans -= diff;
    }

    int64_t ans2 = A[0] + moves;
    for(int i = 1; i < N; i++) {
        if(i == N - 1) {
            ans2 += A[i];
        } 

        ans2 += abs(A[i] - A[i - 1]);
    }
    debug() << imie(A);
    debug() << imie(ans) imie(ans2) imie(moves);
    // assert(ans == ans2);




    cout << ans2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}