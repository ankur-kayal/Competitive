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

void run_cases(int k) {
    // int k;
    // cin >> k;
    vector<int64_t> elements(2 * k + 1);
    for(int i=1;i<=2 * k + 1;i++) {
        elements[i-1] = k + i * i;
    }
    vector<int64_t> hcfs(k);
    for(int i=0;i<k;i++) {
        hcfs[i] = gcd(elements[i], elements[i+1]);
    }
    // debug() << imie(hcfs);
    int64_t ans = accumulate(hcfs.begin(), hcfs.end(), 0LL);
    int64_t ans2 = 0;
    for(int i=1;i<=2*k;i++) {
        ans2 += gcd(k + i*i, 2 * i + 1);
    } 
    debug() << imie(k) imie(ans);
    // debug() << imie(ans2 - k * 6) imie(k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases(test);
    }
}