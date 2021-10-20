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
    int64_t N, K;
    cin >> N >> K;

    vector<int64_t> positions(K);
    for(auto &u: positions) {
        cin >> u;

    }

    int64_t last = N;


    sort(positions.rbegin(), positions.rend());

    deque<int> dq;
    for(auto u: positions) {
        dq.push_back(u);
    }

    int ans = 0;

    int cat_position = 0;

    while(!dq.empty()) {
        debug() << imie(dq);
        while(!dq.empty()) {
            if(dq.back() <= cat_position) {
                dq.pop_back();
            } else {
                break;
            }
        }
        if(dq.empty()) {
            break;
        }

        int steps = last - dq.front();
        dq.pop_front();
        N -= steps;

        if(N < 0) {
            break;
        }

        ans++;
        cat_position += steps;
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