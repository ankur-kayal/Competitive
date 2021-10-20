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
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &u: a)
        cin >> u;

    vector<vector<int>> ans;

    vector<int> tmp = a;

    sort(tmp.begin(), tmp.end());

    for(int i = 0; i < n; i++) {
        if(a[i] != tmp[i]) {
            auto l = a.begin() + i;
            auto r = l;
            int d = 0;
            for(; r != a.end(); r++) {
                d++;
                if(*r == tmp[i]) {
                    r++;
                    break;
                }
            }

            rotate(l, l + d - 1, r);

            ans.push_back({i + 1, i + d, d - 1});
        }

        // debug() << imie(a);
    }


    cout << ans.size() << '\n';

    for(auto u: ans) {
        for(auto v: u) {
            cout << v << " ";
        }
        cout << '\n';
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