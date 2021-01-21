#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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

// -ve means right turn, +ve means left turn, 0 means linear
int cross_product(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
    return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);
}


void run_cases() {
    int n;
    cin >> n;
    if(n == 0) {
        exit(0);
    }
    vector<pair<int,int>> pts;
    for(int i=0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        pts.emplace_back(x,y);
    }
    sort(all(pts));
    vector<pair<int,int>>::iterator it;
    it = unique(all(pts));
    pts.resize(distance(pts.begin(), it));

    vector<pair<int,int>> upper_hull, lower_hull;

    

    lower_hull.push_back(pts[0]);
    upper_hull.push_back(pts[0]);
    for(int i=1;i<pts.size();i++) {
        // constructing lower hull
        while(lower_hull.size() > 1 and cross_product(lower_hull[lower_hull.size() - 2], lower_hull[lower_hull.size() - 1], pts[i]) <= 0) {
            lower_hull.pop_back();
        }
        lower_hull.push_back(pts[i]);

        // constructing upper hull
        while(upper_hull.size() > 1 and cross_product(upper_hull[upper_hull.size() - 2], upper_hull[upper_hull.size() - 1], pts[i]) >= 0) {
            upper_hull.pop_back();
        }
        upper_hull.push_back(pts[i]);
    }

    vector<pair<int,int>> ans;
    for(auto u: lower_hull) {
        ans.push_back(u);
    }
    if(ans.size() > 1) ans.pop_back();
    for(int i=upper_hull.size()-1;i>=1;i--) {
        ans.push_back(upper_hull[i]);
    }

    cout << ans.size() << '\n';
    for(auto u: ans) {
        cout << u.first << " " << u.second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    // int tests = 1;
    // cin >> tests;
    for(int test = 1;;test++) {
        run_cases();
    }
}