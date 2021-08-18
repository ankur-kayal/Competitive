#include <algorithm>
#include <bits/stdc++.h>
#include <regex>
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

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;
    vector<int> S = A;
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    debug() << imie(S);

    int partitions = 1;

    for(int i = 0; i < N - 1; i++) {
        if(A[i] > A[i + 1]) {
            partitions++;
        } else {
            int small_index = lower_bound(S.begin(), S.end(), A[i]) - S.begin();
            int large_index = lower_bound(S.begin(), S.end(), A[i + 1]) - S.begin();
            debug() << imie(small_index) imie(large_index);
            if(large_index - small_index > 1) {
                partitions++;
            }
        }
    }

    cout << (partitions <= K ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}