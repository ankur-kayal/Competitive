#include <bits/stdc++.h>
#include <numeric>
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

const int INF = 1e9 + 7;

bool overlap(const pair<int,int> &part1, const pair<int,int> &part2) {
    auto x = min(part1, part2);
    auto y = max(part1, part2);

    // debug() << imie(x) imie(y);

    if(x.second >= y.first) {
        return true;
    }

    return false;
}

void run_cases() {
    int N, K;
    cin >> N >> K;

    vector<int> B(N);
    for(auto &u: B) {
        cin >> u;
    }

    if(accumulate(B.begin(), B.end(), 0LL) < K) {
        cout << -1 << '\n';
        return;
    }

    vector<vector<pair<int,int>>> segments(K + 1);

    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        for(int j = i; j < N; j++) {
            sum += B[j];
            if(sum <= K) {
                segments[sum].emplace_back(i, j);
            } else {
                break;
            }
        }
    }

    // for(int i = 0; i <= K; i++) {
    //     debug() << imie(i) imie(segments[i]);
    // }

    int cost = INF;
    for(auto segment: segments[K]) {
        cost = min(cost, segment.second - segment.first + 1);
    }

    if(cost == 1) {
        cout << 1 << '\n';
        return;
    }


    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        for(int j = i; j < N; j++) {
            sum += B[j];
            int need = K - sum;
            if(need < 0) {
                break;
            }

            // debug() << imie(sum) imie(need);

            for(auto &segment: segments[need]) {
                if(!overlap({i, j}, segment)) {
                    cost = min(cost, j - i + 1 + segment.second - segment.first + 1);
                }
            }
        }
        if(cost == 2) {
            break;
        }
    }

    if(cost == INF) {
        cost = -1;
    }

    cout << cost << '\n';
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