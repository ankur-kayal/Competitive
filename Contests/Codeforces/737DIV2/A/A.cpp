#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
#include <numeric>
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
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    sort(A.begin(), A.end());

    int64_t sum = accumulate(A.begin(), A.end(), 0LL);

    int64_t left_sum = A[0], right_sum = sum - A[0];
    double ans = left_sum + double(right_sum) / (N - 1);
    debug() << imie(ans);
    int lc = 1, rc = N - 1;
    for(int i = 1; i < N - 1; i++) {
        lc++;
        rc--;
        left_sum += A[i];
        right_sum -= A[i];
        debug() << imie(left_sum) imie(right_sum);
        double inter = double(left_sum) / lc + double(right_sum) / rc;
        debug() << imie(inter);
        ans = max(ans, double(left_sum) / lc + double(right_sum) / rc);
        debug() << imie(ans);
    }

    cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}