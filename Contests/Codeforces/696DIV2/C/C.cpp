#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert

//----------------------------------- END DEFINES -------------------------------- 

void run_cases() {
    int n;
    cin >> n;
    vector<int64_t> a(2 * n);
    trav(u, a) cin >> u;

    sort(all(a));
    vector<pair<int,int>> ans(n);
    int target = a.back();
    ans[0].first = target;
    a.pop_back();
    for(auto u: a) {
        multiset<int> uni;
        for(auto v: a) {
            uni.insert(v);
        }
        ans[0] = mp(target, u);
        uni.erase(uni.find(u));
        bool ok = true;
        int tmp = target;
        for(int i=1;i<n;i++){
            auto it = prev(uni.end());
            int big = *it;
            uni.erase(uni.find(big));
            if(uni.count(tmp - big)) {
                ans[i] = mp(big, tmp - big);
                uni.erase(uni.find(tmp - big));
                tmp = big;
            }
            else {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << "YES" << '\n';
            cout << ans[0].first + ans[0].second << '\n';
            for(auto u: ans) {
                cout << u.first << " " << u.second << '\n';
            }
            return;
        }
        debug() << imie(ans);
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}