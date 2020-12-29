#include <bits/stdc++.h>
#include <utility>
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<pair<int,int>> interval;
    vector<pair<int,int>> ori;
    int n;
    cin >> n;
    while(n--) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) {
            interval.push_back(make_pair(l, r));
            ori.push_back(make_pair(l, r));
        }
        else{
            --l;--r;
            bool ok = true;
            pair<int,int> beg = ori[l];
            pair<int,int> end = ori[r];
            for(int i=0;i<ori.size();i++) {
                if(interval[i] == beg) {
                    l = i;
                }
                if(interval[i] == end) {
                    r = i;
                }
            }
            for(int i=l;i<r;i++) {
                if(interval[i].first < interval[i+1].second and interval[i].first > interval[i+1].first) {
                    ok = true;
                }
                else if(interval[i].second < interval[i+1].second and interval[i].second > interval[i+1].first) {
                    ok = true;
                }
                else {
                    ok = false;
                }
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
        sort(interval.begin(), interval.end());
        debug() << imie(interval);
    }
}