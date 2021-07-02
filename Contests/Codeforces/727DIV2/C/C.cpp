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
    int64_t N, K, X;
    cin >> N >> K >> X;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    sort(A.begin(), A.end());

    vector<int64_t> diffs;

    for(int i = 0; i < N - 1; i++) {
        int64_t diff = A[i + 1] - A[i];
        diff = (diff + X - 1) / X - 1;
        if(diff > 0)
        diffs.push_back(diff);
    }

    sort(diffs.begin(), diffs.end());

    debug() << imie(diffs);

    int grps = diffs.size() + 1;

    debug() << imie(grps);

    for(int i = 0; i < diffs.size(); i++) {
        if(K < diffs[i]) {
            break;
        }
        K -= diffs[i];
        grps--;
    }

    cout << grps << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}