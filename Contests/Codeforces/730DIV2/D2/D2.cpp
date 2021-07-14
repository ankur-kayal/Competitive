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

vector<int> kbit(int a, int k) {
    if(a == 0) {
        return vector<int>{0};
    }
    vector<int> ans;

    while(a > 0) {
        ans.push_back(a % k);
        a /= k;
    }


    return ans;
}

int kbitxor(int a, int b, int k) {
    auto kbita = kbit(a, k);
    auto kbitb = kbit(b, k);

    int n = kbita.size();
    int m = kbitb.size();
    int mlen = max(n, m);
    kbita.resize(mlen);
    kbitb.resize(mlen);

    vector<int> res = kbita;
    for(int i = 0; i < mlen; i++) {
        res[i] = (kbita[i] + kbitb[i]) % k;
    }
    debug() << imie(kbita) << nl << imie(kbitb) << nl << imie(res);
    int mul = 1;
    int ans = 0;
    for(auto u: res) {
        ans += mul * u;
        mul *= k;
    }
    return ans;
}

int kbitxori(int a, int b, int k) {
    auto kbita = kbit(a, k);
    auto kbitb = kbit(b, k);

    int n = kbita.size();
    int m = kbitb.size();
    int mlen = max(n, m);
    kbita.resize(mlen);
    kbitb.resize(mlen);

    vector<int> res = kbita;
    for(int i = 0; i < mlen; i++) {
        res[i] = (kbita[i] - kbitb[i] + k) % k;
    }
    debug() << imie(kbita) << nl << imie(kbitb) << nl << imie(res);
    int mul = 1;
    int ans = 0;
    for(auto u: res) {
        ans += mul * u;
        mul *= k;
    }
    return ans;
}

void run_cases() {
    int n, k;
    cin >> n >> k;

    int rolling_xor = 0;

    for(int ans = 0; ans < n; ans++) {
        // int query = rolling_xor ^ ans;
        int query = kbitxor(rolling_xor, ans, k);
        debug() << imie(rolling_xor) imie(ans) imie(query);
        if(ans & 1) {
            query = kbitxori(rolling_xor, ans, k);
        }
        cout << query << endl;
        int r;
        cin >> r;
        if(r == 1) {
            break;
        }
        // rolling_xor ^= query;
        rolling_xor = kbitxori(query, rolling_xor, k);
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