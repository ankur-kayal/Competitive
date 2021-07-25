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

    int l = 0;
    int64_t ans = 0;
    deque<int> q;
    deque<int> rq;
    auto LISf = [&]() {
        // debug() << imie(q);
        vector<int> dp;
        int n = q.size();
        for(int i = 0; i < n; i++) {
            int x = q.at(i);
            auto it = upper_bound(dp.begin(), dp.end(), x);
            if (it == dp.end()) {
                dp.push_back(x);
            } else {
                *it = x;
            }
        }
        // debug() << imie(q)
        return dp.size();
    };
    auto LISr = [&]() {
        // debug() << imie(q);
        vector<int> dp;
        int n = rq.size();
        for(int i = 0; i < n; i++) {
            int x = rq.at(i);
            auto it = upper_bound(dp.begin(), dp.end(), x);
            if (it == dp.end()) {
                dp.push_back(x);
            } else {
                *it = x;
            }
        }
        // debug() << imie(dp.size());
        return dp.size();
    };
    for(int r = 0; r < N; r++) {
        // add r
        q.push_back(A[r]);
        rq.push_front(A[r]);
        while(LISf() > 2 || LISr() > 2) {
            q.pop_front();
            rq.pop_back();
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