#include <bits/stdc++.h>
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
    int n,m;
    cin >> n >> m;
    vector<int64_t> a(n), b(n);
    trav(u, a) cin >> u;
    trav(u, b) cin >> u;
    vector<int> one, two;
    for(int i=0;i<n;i++) {
        if(b[i] == 1) {
            one.push_back(a[i]);
        }
        else {
            two.push_back(a[i]);
        }
    }

    sort(rall(one)); sort(rall(two));
    
    vector<int64_t> pref1, pref2;
    pref1.push_back(0);
    pref2.push_back(0);
    for(auto u: one) {
        pref1.push_back(pref1.back() + u);
    }
    for(auto u: two) {
        pref2.push_back(pref2.back() + u);
    }

    if(pref1.back() + pref2.back() < m) {
        cout << -1 << '\n';
    }

    else {
        debug() << imie(pref1) imie(pref2);
        debug() << imie(one) imie(two);
        int ans = 1e9;
        int len1 = pref1.size();
        for(int i=0;i<len1;i++) {
            int64_t val1 = pref1[i];
            int64_t target = m - val1;
            int tmp = i;
            bool ok = target <= 0;
            if(target >= 0) {
                int len2 = pref2.size();
                if(pref2.back() >= target) {
                    int r = len2;
                    int l = -1;
                    while(r > l + 1) {
                        int m = (l + r) / 2;
                        if(pref2[m] >= target) {
                            r = m;
                        }
                        else {
                            l = m;
                        }
                    }
                    tmp += r * 2;
                    ok = true;
                }
            }
            if(ok) {
                ans = min(ans, tmp);
            }
            debug() << imie(ok) imie(ans);
        }
        cout << ans << '\n';
    }


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}