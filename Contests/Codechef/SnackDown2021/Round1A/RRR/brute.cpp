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
    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> matches;

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            matches.emplace_back(i, j);
        }
    }

    int bits = matches.size();

    vector<int> scores(N);

    for(int mask = 0; mask < (1 << bits); mask++) {
        vector<int> current_scores(N);
        for(int bit = 0; bit < bits; bit++) {
            if(mask >> bit & 1) {
                current_scores[matches[bit].second]++;
            } else {
                current_scores[matches[bit].first]++;
            }
        }
        sort(current_scores.rbegin(), current_scores.rend());
        for(int i = 0; i < N; i++) {
            scores[i] = max(scores[i], current_scores[i]);
        }
    }

    cout << 2 * scores[K - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}