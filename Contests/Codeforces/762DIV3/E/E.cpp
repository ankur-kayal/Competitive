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

    vector<int> A(N + 1);

    for(int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        A[ai]++;
    }

    bool less_missing = false;

    vector<int> extra;

    int64_t offset = 0;

    set<int> unique;

    for(int i = 0; i <= N; i++) {
        int64_t ans = A[i];

        if(less_missing) {
            cout << -1 << " ";
            continue;
        }

        if(A[i] == 0) {
            cout << offset << " ";
            if(extra.empty()) {
                less_missing = true;
            } else {
                offset += (i - extra.back());
                extra.pop_back();
            }
        } else {
            cout << offset + A[i] << ' ';
        }
        while(A[i] > 1) {
            extra.push_back(i);
            A[i]--;
        }
        // debug() << imie(extra);
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