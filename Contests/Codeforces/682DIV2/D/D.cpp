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

void solve(vector<int> &a, int n) {
    int max_moves = static_cast<int>(a.size());
    cout << "YES" << '\n';
    vector<tuple<int,int,int>> moves;

    int i = 1;
    while(i + 2 <= n) {
        moves.emplace_back(i, i + 1, i + 2);
        i += 2;
    }
    i = n - 2;
    while(i - 2 >= 0) {
        moves.emplace_back(i, i - 1, i - 2);
        i -= 2;
    }

    assert(int(moves.size()) <= max_moves);
    cout << moves.size() << '\n';
    for(auto u: moves) {
        cout << get<0>(u) << " " << get<1>(u) << " " << get<2>(u) << '\n'; 
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    int xor_all = 0;
    for(auto u: a) {
        xor_all = xor_all xor u;
    }

    if(n & 1) {
        solve(a, n);
    }
    else if(n % 2 == 0 and xor_all == 0) {
        solve(a, n-1);
    }
    else {
        cout << "NO" << '\n';
    }
}