#include <bits/stdc++.h>
#include <inttypes.h>
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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<tuple<int,int>> moves;
        int div = n;
        for(int i=n;i>=2;i--) {
            int prev = i - 1;
            if(prev == div) continue;
            if(prev == int(ceil(sqrtl(div)))) {
                moves.emplace_back(div, prev);
                moves.emplace_back(div, prev);
                div = ceil(sqrtl(div));
            }
            else {
                moves.emplace_back(prev, div);
            }
        }

        assert(moves.size() <= n + 5); 
        cout << moves.size() << '\n';
        for(auto u: moves) {
            cout << get<0>(u) << " " << get<1>(u) << '\n';
        }
    }
}