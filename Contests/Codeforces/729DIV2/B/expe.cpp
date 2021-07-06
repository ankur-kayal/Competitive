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
    int64_t a, b;
    cin >> a >> b;
    vector<int64_t> bad = {1};
   set<int64_t> processed;
    for(int i = 0; i < 100000; i++) {
        if(processed.count(bad[i])) continue;
        int64_t val1 = bad[i] * a;
        int64_t val2 = bad[i] + b;
        if(!processed.count(val1)){
            if(val1 < 1e9)
            bad.push_back(val1);
        }
        if(!processed.count(val2)) {
            if(val2 < 1e9)
            bad.push_back(val2);
        }
        processed.insert(bad[i]);
    }

    sort(bad.begin(), bad.end());
    bad.resize(unique(bad.begin(), bad.end()) - bad.begin());

    debug() << imie(bad);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    freopen("log.txt", "w", stderr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}