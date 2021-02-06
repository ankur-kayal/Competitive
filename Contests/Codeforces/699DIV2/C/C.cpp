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
#define nl '\n'

//----------------------------------- END DEFINES -------------------------------- 

void run_cases() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    trav(u, a) cin >> u;
    trav(u, b) cin >> u;
    trav(u, c) cin >> u;
    vector<int> ans(m);
    vector<vector<int>> recolor(n + 1);
    vector<vector<int>> index(n + 1);
    multiset<int> available;
    multiset<int> have;
    for(int i=0;i<n;i++) {
        index[b[i]].push_back(i);
        if(a[i] != b[i]) {
            recolor[b[i]].push_back(i);
            available.insert(b[i]);
        }
        have.insert(b[i]);
    }
    // debug() << imie(index);
    // debug() << imie(have);
    for(int i=0;i<m;i++) {
        int target = c[i];
        if(available.count(target)) {
            ans[i] = recolor[target].back();
            recolor[target].pop_back();
            available.erase(available.find(target));
        }
        else {
            if(available.size() > 0) {
                ans[i] = recolor[*available.begin()].back();
            }
            // debug() << imie()
            else if(have.count(c[m-1])) {
                // debug() << imie(i + 1) imie(b[n-1]);
                ans[i] = index[c[m-1]].back();
            }
            else {
                cout << "NO" << nl;
                return;
            }
        }
    }
    vector<int> newcolor;
    for(auto u: a) {
        newcolor.push_back(u);
    }
    for(int i=0;i<m;i++) {
        newcolor[ans[i]] = c[i];
    }
    // debug() << imie(ans) imie(newcolor);

    if(newcolor == b) {
       cout << "YES" << '\n';
        for(auto u: ans) {
            cout << u + 1 << " ";
        }
        cout << nl; 
    }
    else {
        cout << "NO" << nl;
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