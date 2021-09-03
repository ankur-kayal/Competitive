#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

static const int INF = 1e9+7;


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
    int64_t M;
    cin >> N;
    cin >> M;


    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    vector<int64_t> sum(N + 1);
    for(int i = 0; i < N; i++) {
        sum[i + 1] = (sum[i] + A[i]) % M;;
    }

    auto parity = [&](int l, int r) {
        return sum[l] == sum[r];
    };

    int ans = INF;

    for(int mask = 0; mask < N; mask++) {
        for(int submask = mask; submask >= 0; submask = mask & (submask - 1)) {
            int r = N - mask;
            int l = submask;
            if(l < r && parity(l, r)) {
                ans = min(ans, __builtin_popcount(mask));
            } 
            if(submask == 0) {
                break;
            }
        }
    }  

    cout << (ans == INF ? -1 : ans) << '\n';  
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}