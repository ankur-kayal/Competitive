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

class DSU {
    public:
    vector<int> p;
    int n;
 
    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
 
    inline int find(int x) {
        return (x == p[x] ? x : (p[x] = find(p[x])));
    }
 
    inline bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

void run_cases() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> P(M, vector<int>(N));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> P[i][j];
        }
    }

    auto good = [&](int m) {
        int number_of_shops = 0;

        vector<int> shops(M);
        iota(shops.begin(), shops.end(), 0);
        vector<int> cnt(M);

        DSU dsu(M);

        for(int i = 0; i < N; i++) {
            vector<int> current_shops;
            for(int j = 0; j < M; j++) {
                if(P[j][i] >= m) {
                    current_shops.push_back(j);
                    cnt[j]++;
                }
            }

            if(current_shops.empty()) {
                return false;
            }
            for(int j = 1; j < current_shops.size(); j++) {
                dsu.unite(current_shops[j], current_shops[j - 1]);
            }
        }

        for(int i = 0; i < M; i++) {
            if(cnt[i] > 0 && dsu.find(i) == i) {
                number_of_shops++;
            }
        }

        debug() << imie(m) imie(shops);

        return number_of_shops <= N - 1;
    };

    int l = 1, r = 1e9 + 7;
    while(r > l + 1) {
        int m = (l + r) / 2;

        if(good(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}