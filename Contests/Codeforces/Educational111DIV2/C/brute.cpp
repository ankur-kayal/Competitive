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
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    int64_t ans = 0;

    auto d = [&](pair<int,int> p, pair<int,int> q) {
        return abs(p.first - q.first) + abs(p.second - q.second);
    };
    auto valid = [&](vector<pair<int,int>> &a) {
        if(a.size() < 3) {
            return true;
        }
        for(int i = 0; i < a.size(); i++) {
            for(int j = i + 1; j < a.size(); j++) {
                for(int k = j + 1; k < a.size(); k++) {
                    if(d(a[i], a[k]) == d(a[i], a[j]) + d(a[j], a[k])) {
                        return false;
                    }
                }
            }
        }
        return true;
    };
    int l = 0;
    vector<pair<int,int>> q;
    for(int r = 0; r < N; r++) {
        // add r
        q.emplace_back(A[r], r + 1);
        while(!valid(q)) {
            q.erase(q.begin());
            l++;
        }
        debug() << imie(l) imie(r);
        ans += (r - l + 1);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}