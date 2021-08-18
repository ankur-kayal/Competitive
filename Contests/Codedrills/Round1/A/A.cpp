#include <bits/stdc++.h>
#include <numeric>
#include <queue>
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
    int64_t N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    int64_t ans = 0;

    for(int i = 0; i < N; i++) {
        int K;
        cin >> K;

        int cnt = 1;
        vector<int64_t> A(K);
        for(auto &u: A)
            cin >> u;

        vector<int> parts;

        for(int j = 0; j < K - 1; j++) {
            if(A[j] <= A[j + 1]) {
                cnt++;
                
            } else {
                debug() << imie(cnt);
                parts.push_back(cnt);
                pq.push(cnt);
                cnt = 1;
            }
        }
        parts.push_back(cnt);
        sort(parts.begin(), parts.end());
        debug() << imie(parts);
        parts.pop_back();
        ans += accumulate(parts.begin(), parts.end(), 0LL);
        debug() << imie(cnt);
        pq.push(cnt);
    }
    debug() << imie(ans);
    while(pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += (a + b);
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