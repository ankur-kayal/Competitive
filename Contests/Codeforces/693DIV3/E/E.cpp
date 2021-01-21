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
    int n;
    cin >> n;
    vector<pair<int,int>> dims;
    for(int i=0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        dims.emplace_back(x,y);
    }
    // {{height, width}, id} for stand
    // {{width, height}, id} for lie
    vector<pair<pair<int,int>, int>> stand, lie;
    for(int i=0;i<n;i++) {
        stand.push_back({{dims[i].first, dims[i].second}, i});
        lie.push_back({{dims[i].second, dims[i].first}, i});
    }

    sort(all(stand)); sort(all(lie));

    vector<pair<int,int>> scomp(n);
    scomp[0] = {stand[0].first.second , stand[0].second};
    for(int i=1;i<n;i++) {
        scomp[i] = min(scomp[i-1], {stand[i].first.second , stand[i].second});
    }

    vector<pair<int,int>> lcomp(n);
    lcomp[0] = {lie[0].first.second , lie[0].second};
    for(int i=1;i<n;i++) {
        lcomp[i] = min(lcomp[i-1], {lie[i].first.second , lie[i].second});
    }
    debug() << imie(stand) << '\n' << imie(lie);
    debug() << imie(scomp) << '\n' << imie(lcomp);


    vector<int> ans(n, -2);

    for(int i=0;i<n;i++) {

        int h = dims[i].first;
        int w = dims[i].second;

        // check stand
        if(stand[0].first.first < h) {
            int l = 0;
            int r = n;
            while(r > l + 1) {
                int m = (l + r) / 2;
                int val = stand[m].first.first;
                if(val < h) {
                    l = m;
                }
                else {
                    r = m;
                }
            }
            if(scomp[l].first < w) {
                ans[i] = scomp[l].second;
            }
        }

        // check lie

        if(lie[0].first.first < h) {
            int l = 0;
            int r = n;
            while(r > l + 1) {
                int m = (r + l) / 2;
                int val = lie[m].first.first;
                if(val < h) {
                    l = m;
                }
                else{
                    r = m;
                }
            }
            if(lcomp[l].first < w) {
                ans[i] = lcomp[l].second;
            }
        }

    }

    for(auto u: ans) {
        cout << u + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}