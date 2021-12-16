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
    int N, K;
    cin >> N >> K;

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    vector<int64_t> left, right;
    for(auto u: A) {
        if(u <= 0) {
            left.push_back(abs(u));
        } else {
            right.push_back(u);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    vector<int> scores;

    while(!left.empty()) {
        scores.push_back(left.back());
        for(int i = 0; i < K; i++) {
            if(!left.empty()) {
                left.pop_back();
            }
        }
    }

    while(!right.empty()) {
        scores.push_back(right.back());
        for(int i = 0; i < K; i++) {
            if(!right.empty()) {
                right.pop_back();
            }
        }
    }

    sort(scores.begin(), scores.end());

    int64_t ans = 2 * accumulate(scores.begin(), scores.end(), 0LL) - scores.back();

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