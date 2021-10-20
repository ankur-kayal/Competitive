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
    int N, M;
    cin >> N >> M;

    vector<int> S(M);

    for(auto &u: S)
        cin >> u;

    sort(S.begin(), S.end());

    int64_t ans = 0;

    vector<int> changed, unchanged(S.begin(), S.end());

    for(int i = 0; i < N; i++) {
        vector<int> order(M);
        for(auto &u: order) {
            cin >> u;
        }

        sort(order.begin(), order.end());
        sort(changed.begin(), changed.end());
        sort(unchanged.begin(), unchanged.end());

        vector<int> new_changed(M);

        // first match every changed present in the order

        auto it = set_intersection(changed.begin(), changed.end(), order.begin(), order.end(), new_changed.begin());
        new_changed.resize(it - new_changed.begin());

        // reduce the order accordingly 

        vector<int> new_order(M);

        it = set_difference(order.begin(), order.end(), changed.begin(), changed.end(), new_order.begin());

        new_order.resize(it - new_order.begin());

        order = new_order;

        // find new unchanged

        vector<int> new_unchanged(M);

        it = set_intersection(order.begin(), order.end(), unchanged.begin(), unchanged.end(), new_unchanged.begin());

        new_unchanged.resize(it - new_unchanged.begin());

        new_order = vector<int>(M);

        it = set_difference(order.begin(), order.end(), unchanged.begin(), unchanged.end(), new_order.begin());

        new_order.resize(it - new_order.begin());

        ans += new_order.size() - (unchanged.size() - new_unchanged.size());

        unchanged = new_unchanged;

        for(auto u: new_order) {
            new_changed.push_back(u);
        }

        changed = new_changed;

    }
    cout << ans << '\n';    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("a_validation_input.txt", "r", stdin);
    // freopen("a_validation_output.txt", "w", stdout);

    /*For final submit*/
    // freopen("a_final_input.txt", "r", stdin);
    // freopen("a_final_output.txt", "w", stdout);

    /*For practice submit*/
    freopen("a_practice_input.txt", "r", stdin);
    freopen("a_practice_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}