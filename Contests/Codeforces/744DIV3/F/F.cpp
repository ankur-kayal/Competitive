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
    int N, D;
    cin >> N >> D;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    vector<int> vis(N, false);

    auto next_index = [&](int index) {
        index += D;
        index %= N;
        return index;
    };

    int res = 0;

    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            int index = i;
            vector<int> vals;
            while(!vis[index]) {
                vis[index] = true;
                vals.push_back(A[index]);
                index = next_index(index);
            }

            vector<int> tmp = vals;
            for(auto u: vals) {
                tmp.push_back(u);
            }

            int cnt = 0;
            int ans = 0;
            for(auto u: tmp) {
                if(u == 1) {
                    cnt++;
                    ans = max(ans, cnt);
                } else {
                    cnt = 0;
                }
            }

            if(cnt == tmp.size()) {
                cout << -1 << '\n';
                return;
            }
            res = max(res, ans);
        }
    }

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}