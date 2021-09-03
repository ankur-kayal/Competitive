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
    string S;
    cin >> S;

    string vowels = "AEIOU";

    int64_t minimumSeconds = 1e16;

    const int64_t INF64 = 1e16;

    vector<vector<int64_t>> dist(26, vector<int64_t>(26, INF64));

    int K;
    cin >> K;

    for(int i = 0; i < K; i++) {
        char a, b;
        cin >> a >> b;
        dist[a - 'A'][b - 'A'] = 1;
        // debug() << imie(a) imie(b);
    }

    for(int k = 0; k < 26; k++) {
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // for(auto u: dist) {
    //     debug() << imie(u);
    // }

    for(char i = 'A'; i <= 'Z'; i++) {
        int64_t ans = 0;
        for(auto u: S) {
            if(u != i)
                ans += dist[u - 'A'][i - 'A'];
        }
        minimumSeconds = min(ans, minimumSeconds);
    }

    cout << (minimumSeconds >= INF64 ? -1 : minimumSeconds) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("a2_validation_input.txt", "r", stdin);
    // freopen("a2_validation_output.txt", "w", stdout);

    /*For final submit*/
    // freopen("a2_final_input.txt", "r", stdin);
    // freopen("a2_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}