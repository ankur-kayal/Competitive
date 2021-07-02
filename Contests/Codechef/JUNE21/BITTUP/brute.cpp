#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

vector<int> ans(1000);
vector<vector<vector<int>>> cache(1000);

vector<int> a;

void compute() {
    int A = a[0];
    for(auto u: a) {
        A &= u;
    }
    if(A == 0) {
        ans[accumulate(a.begin(), a.end(), 0)]++;
        cache[accumulate(a.begin(), a.end(), 0)].push_back(a);
    }
}

void solve(int index, int val, int n) {
    if(index == n) {
        // debug() << imie(a);
        compute();
        return;
    }
    for(int i=0;i<=val;i++) {
        a.push_back(i);
        solve(index + 1, val, n);
        a.pop_back();
    }
} 


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
    ans.assign(1000, 0);
    int n, k;
    cin >> n >> k;

    debug() << imie(n) imie(k);

    cout << "TEST" << '\n';
    solve(0, (1 << k) - 1, n);

    int64_t res = 0;

    for(int i=1000-1;i>=0;i--) {
        if(ans[i] != 0) {
            debug() << imie(cache[i]);
        }
        res += ans[i];

    }

    cout << res << '\n';

    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}