#include <algorithm>
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
    int N;
    cin >> N;

    vector<int> H(N);
    for(auto &u: H) 
        cin >> u;

    debug() << imie(H);

    int l = 0, r = 1e9 + 7;

    auto good = [&](int target) {
        vector<int> current = H;

        vector<int> values(N);
        vector<int> add(N);

        for(int i = N - 1; i >= 2; i--) {
            int extra = min(max(add[i] + H[i] - target, 0), H[i]);

            // debug() << imie(extra) imie(H[i]) imie(add[i]);

            int d = extra / 3;

            current[i] -= 3 * d;
            current[i - 1] += d;
            current[i - 2] += 2 * d;
            add[i - 1] += d;
            add[i - 2] += 2 * d;
        }

        // debug() << imie(current) imie(target);

        return *min_element(current.begin(), current.end()) >= target;
    };

    while(r > l + 1) {
        int m = l + (r - l) / 2;

        if(good(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}