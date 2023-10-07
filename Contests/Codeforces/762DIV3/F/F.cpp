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
    int N, M, K;
    cin >> N >> M >> K;

    
    vector<int> sz(M);
    int index = 0;
    for(int i = 0; i < N; i++) {
        sz[index]++;
        index = (index + 1) % (M);
    }

    vector<int> b(N);

    debug() << imie(sz);

    for(int times = 0; times < K; times++) {
        vector<pair<int,int>> people;
        for(int i = 1; i <= N; i++) {
            people.push_back({b[i - 1], i});
        }
        sort(people.begin(), people.end());
        vector<vector<int>> groups(M);
        int i = 0;
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < sz[j]; k++)
                groups[j].push_back(people[i++].second);
        }

        for(auto u: groups) {
            cout << u.size() << " ";
            for(auto v: u) {
                cout << v << " ";
            }
            cout << '\n';
        }

        for(int i = 0; i < M; i++) {
            if(sz[i] == (N + M - 1) / M) {
                for(auto pi: groups[i]) {
                    b[pi - 1]++;
                }
            }
        }

        debug() << imie(b);
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}