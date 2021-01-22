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

//----------------------------------- DEFINES -------------------------------- 
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
    string s;
    cin >> s;
    vector<pair<int,int>> pref(n + 1, mp(0,0));
    int s1 = 0;
    vector<int> comp(n + 1,0);
    for(int i=1;i<=n;i++) {
        if(s[i-1] == '-') {
            s1--;
        }
        else {
            s1++;
        }
        comp[i] = s1;
        pref[i] = {max(pref[i-1].first, s1), min(pref[i-1].second, s1)};
    }
    // debug() << imie(pref);
    vector<pair<int,int>> suf(n + 2, mp(0,0));
    int s2 = 0;
    for(int i=n;i>=1;i--) {
        int val = 0;
        if(s[i-1] == '+') {
            val++;
        }
        else {
            val--;
        }
        suf[i] = {max(suf[i+1].first + val, 0), min(suf[i+1].second + val, 0)};
    }
    // debug() << imie(suf);
    // debug() << imie(comp);
    while(m--) {
        int l, r;
        cin >> l >> r;

        int high = pref[l-1].first;
        int low = pref[l-1].second;
        // debug() << imie(high) imie(low);

        high = max(high, comp[l-1] + suf[r+1].first);
        low = min(low, comp[l-1] + suf[r+1].second);

        // debug() << imie(comp[l-1]) imie(high) imie(low);

        cout << high - low + 1 << '\n';
    }

    // exit(0);

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}