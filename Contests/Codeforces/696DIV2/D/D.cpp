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

bool check(vector<int64_t> a) {
    for(int i=0;i<int(a.size())-1;i++) {
        if(a[i] > a[i + 1]) return 0;
        a[i + 1] -= a[i];
        a[i] = 0;
    }
    return a.back() == 0;
}

void run_cases() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    trav(u, a) cin >> u;
    if(n == 1) {
        cout << "NO" << '\n';
        return;
    }
    if(check(a)) {
        cout << "YES" << '\n';
        return;
    }
    swap(a[0], a[1]);
    if(check(a)) {
        cout << "YES" << '\n';
        return;
    }
    swap(a[0], a[1]);
    swap(a[n-1], a[n-2]);
    if(check(a)) {
        cout << "YES" << '\n';
        return;
    }
    swap(a[n-1], a[n-2]);

    vector<int64_t> p(n), s(n);
    vector<int64_t> b = a;
    p[0] = b[0];

    for(int i=1;i<n;i++) {
        if(p[i-1] == -1 or b[i-1] > b[i]) {
            p[i] = -1;
        }
        else {
            b[i] -= b[i-1];
            b[i-1] = 0;
            p[i] = b[i];
        }
    }

    b = a;
    s[n-1] = b[n-1];
    for(int i=n-2;i>=0;i--) {
        if(s[i+1] == -1 || b[i+1] > b[i]) {
            s[i] = -1;
        }
        else {
            b[i] -= b[i+1];
            b[i+1] = 0;
            s[i] = b[i];
        }
    }

    for(int i=1;i+2<n;i++) {
        vector<int64_t> c = {p[i-1], a[i], a[i+1], s[i+2]};
        if(p[i-1] == -1 || s[i+2] == -1) {
            continue;
        }
        swap(c[1], c[2]);
        if(check(c)) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}