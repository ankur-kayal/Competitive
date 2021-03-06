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
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int64_t, int64_t>> P(N);
    for(int i=0;i<N;i++) {
        int64_t pi;
        cin >> pi;
        P[i] = {pi, i};
    }

    sort(P.begin(), P.end());

    debug() << imie(P);

    int start = 0;

    while(M > 0) {
        set<int> candidates;
        int64_t val = -1;
        bool ok = false;
        for(int i=start;i<N;i++) {
            if(val == -1 || P[i].first == val) {
                candidates.insert(P[i].second);
                val = P[i].first;
            } else {
                if(candidates.count(0)) {
                    if(candidates.size() <= M) {
                        cout << "YES\n";
                    } else {
                        cout << "MAYBE\n";
                    }
                    return;
                }
                break;
            }
        }
        if(candidates.count(0)) {
            if(candidates.size() <= M) {
                cout << "YES\n";
            } else {
                cout << "MAYBE\n";
            }
            return;
        }
        M -= candidates.size();
        start += candidates.size();

    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}