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
vector<int> a;
vector<int64_t> prefix;
set<int64_t> cache;

const int maxS = 1e9;
void precompute(int start, int end) {
    if(start == end) {
        cache.insert(a[start]);
        return;
    }
    if(start > end) {
        return;
    }
    int small = a[start];
    int big = a[end];
    int mid = (small + big) / 2;
    int l = start;
    int r = end + 1;
    while(r > l + 1) {
        int m = (r + l) / 2;
        if(a[m] <= mid) {
            l = m;
        }
        else {
            r = m;
        }
    }

    int64_t s1 = prefix[l] - prefix[start] + a[start];
    int64_t s2 = prefix[end] - prefix[l];

    // debug() << imie(s1) imie(s2) imie(l) imie(start) imie(end);

    if(s1 <= maxS) {
        cache.insert(s1);
    }
    if(s2 <= maxS) {
        cache.insert(s2);
    }
    if(l == end) {
        return;
    }
    precompute(start, l);
    precompute(l + 1, end);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cache.clear();
        int n,q;
        cin >> n >> q;
        a = vector<int>(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        prefix = vector<int64_t>(n);
        prefix[0] = a[0];
        for(int i=1;i<n;i++) {
            prefix[i] = prefix[i-1] + a[i];
        }
        precompute(0, n-1);
        cache.insert(prefix[n-1]);
        // debug() << imie(cache);
        while(q--) {
            int s;
            cin >> s;

            bool ok = cache.count(s);

            cout << (ok ? "Yes" : "No") << '\n';
        }
    }
}