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

vector<pair<int,vector<int>>> cache;
void evaluate(vector<int> &a) {
    int n = a.size();
    vector<int> prefix(n);
    prefix[0] = a[0];
    for(int i=1;i<n;i++) {
        prefix[i] = prefix[i-1] + a[i];
    }
    int cnt = 0;
    for(auto u: prefix) {
        if(u > 0) {
            cnt++;
        }
    }
    cache.push_back(make_pair(cnt, a));
}

void recurse(int index, vector<int>& a, int n) {
    a.push_back(index);
    if(index != n) {
        recurse(index + 1, a, n);
    }
    else {
        evaluate(a);
    }
    a.pop_back();
    a.push_back(-index);
    if(index != n) {
        recurse(index + 1, a, n);
    }
    else {
        evaluate(a);
    }
    a.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> ans;
    recurse(1, ans, n);

    sort(cache.begin(), cache.end());
    for(auto u: cache) {
        int cnt = u.first;
        vector<int> res = u.second;
        debug() << imie(cnt) imie(res);
    }

}