#include <algorithm>
#include <bits/stdc++.h>
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
    int64_t N;
    cin >> N;

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    sort(A.begin(), A.end());
    debug() << imie(A);

    int64_t sum = accumulate(A.begin(), A.end(), 0LL);

    int64_t low = A[(N - 1) / 2] - 1;
    int64_t high = *max_element(A.begin(), A.end());

    vector<int> B;
    for(int i = (N - 1) / 2; i < N; i++) {
        B.push_back(A[i]);
    }

    debug() << imie(B);

    vector<int64_t> prefix_sums(B.size() + 1);
    for(int i = 0; i < B.size(); i++) {
        prefix_sums[i + 1] = prefix_sums[i] + B[i];
    }

    while(high > low + 1) {
        int64_t mid = (low + high) / 2;

        int64_t mean_operations = mid * N - sum;
        int64_t median_operations = 0;

        int64_t l = -1, r = B.size();
        while(r > l + 1) {
            int64_t m = (l + r) / 2;
            if(B[m] < mid) {
                l = m;
            } else {
                r = m;
            }
        }

        median_operations = (l + 1) * mid - prefix_sums[l + 1];
        assert(median_operations >= 0);

        if(median_operations <= mean_operations) {
            high = mid;
        } else {
            low = mid;
        }
    }

    int64_t answer = high * N - sum;
    debug() << imie(high);

    assert(answer >= 0);

    cout << answer << '\n';
}   

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}