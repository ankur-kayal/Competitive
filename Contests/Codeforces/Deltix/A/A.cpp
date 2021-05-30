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
    int N,M;
    cin >> N >> M;
    string s;
    cin >> s;
    vector<int> val(N + 2, N + 100);
    for(int i=1;i<=N;i++) {
        if(s[i - 1] == '1') {
            val[i] = 0;
        }
    }

    for(int i=1;i<=N;i++) {
        val[i] = min(val[i], val[i - 1] + 1);
    }
    // debug() << imie(val);
    for(int i=N;i>=1;i--) {
        val[i] = min(val[i], val[i + 1] + 1);
    }
    // debug() << imie(val);

    for(int i=1;i<=N;i++) {
        if(val[i] == 0) {
            cout << 1;
        } else if(val[i - 1] != val[i + 1] && min(val[i - 1], val[i + 1]) < M) {
            cout << 1;
        } else{
            cout << 0;
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}