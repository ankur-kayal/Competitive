#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

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
    int N, P;
    cin >> N >> P;

    vector<vector<int64_t>> products(N, vector<int64_t>(P));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < P; j++) {
            cin >> products[i][j];
        }
    }

    map<int64_t, int64_t> dp;
    dp[0] = 0;

    const int64_t INF64 = 2e18;
    int64_t button_presses = INF64;

    for(int i = 0; i < N; i++) {
        vector<int64_t> product_per_customer = products[i];
        

        sort(product_per_customer.begin(), product_per_customer.end());

        map<int64_t, int64_t> newDp;
        int64_t front = product_per_customer.front();
        int64_t back = product_per_customer.back();
        newDp[front] = INF64;
        newDp[back] = INF64;

        int64_t diff = back - front;

        for(auto [key, value] : dp) {
            newDp[front] = min(newDp[front], value + abs(back - key) + diff);
            newDp[back] = min(newDp[back], value + diff + abs(front - key));
        }
        dp = newDp;
    } 

    for(auto [key, value] : dp) {
        button_presses = min(button_presses, value);
    }

    cout << button_presses << '\n';
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