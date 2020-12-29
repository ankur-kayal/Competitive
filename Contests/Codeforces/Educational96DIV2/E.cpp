#include <bits/stdc++.h>
#include <stdint.h>
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
const int maxN = 3e5;

vector<int64_t> cnt(maxN);

void upd(int i, int64_t delta) {
    while(i < maxN) {
        cnt[i] += delta;
        i += (i & -i);
    }
}

int64_t sum(int i) {
    int64_t res = 0;
    while(i >= 1) {
        res += cnt[i];
        i -= (i & -i);
    }
    return res;
}

int64_t calc(int l, int r=maxN - 10) {
    return sum(r) - sum(l-1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> pos(26, vector<int>());
    for(int i=1;i<=n;i++) {
        int val = s[i-1] - 'a';
        pos[val].push_back(n-i+1);
    }
    debug() << imie(pos);
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        int val = s[i] - 'a';
        a[i] = pos[val].back();
        pos[val].pop_back();
    }

    debug() << imie(a);

    int64_t ans = 0;
    for(auto u : a) {
        ans += calc(u + 1);
        upd(u, 1);
    }

    cout << ans << '\n';
}