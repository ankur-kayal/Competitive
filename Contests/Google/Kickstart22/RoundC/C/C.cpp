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
    int N, L;
    cin >> N >> L;

    vector<pair<int,int>> ants;
    for(int i = 0; i < N; i++) {
        int p, d;
        cin >> p >> d;
        ants.emplace_back(p, d);
    }

    deque<pair<int,int>> positions(N);
    for(int i = 0; i < N; i++) {
        positions[i] = {ants[i].first, i + 1};
    }

    sort(positions.begin(), positions.end());

    for(int i = 0; i < N; i++) {
        if(ants[i].second == 1) {
            ants[i].first = L - ants[i].first;
        }
    }

    sort(ants.begin(), ants.end());

    vector<pair<int,int>> ans;

    for(auto [p, d]: ants) {
        if(d == 0) {
            int index = positions.front().second;
            positions.pop_front();
            ans.emplace_back(p, index);
        } else {
            int index = positions.back().second;
            positions.pop_back();
            ans.emplace_back(p, index);
        }
    }

    sort(ans.begin(), ans.end());

    for(auto [_, i]: ans) {
        cout << i << " ";
    }
    cout << '\n';
}   

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}