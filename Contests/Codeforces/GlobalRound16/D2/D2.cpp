#include <bits/stdc++.h>
#include <utility>
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
    int n, m;
    cin >> n >> m;

    vector<int> a(n * m);
    for(auto &u: a)
        cin >> u;

    vector<vector<int>> seats(n, vector<int>(m, 0));

    vector<pair<int,int>> order;
    for(int i = 0; i < n * m; i++) {
        order.emplace_back(a[i], -i);
    }

    sort(order.begin(), order.end());

    // debug() << imie(order);

    vector<int> allocated_seats(n * m);

    int prev = -1;
    vector<int> groups;
    vector<int> ids;
    for(int seat = 0; seat < n * m; seat++) {
        int val = order[seat].first;
        if(prev == val) {
            groups.push_back(seat);
            ids.push_back(-order[seat].second);
        } else {
            // debug() << imie(ids) imie(groups);
            sort(groups.begin(), groups.end(), [&](int u, int v) {
                int r1 = u / m;
                int c1 = u % m;
                int r2 = v / m;
                int c2 = v % m;

                return make_pair(r1, -c1) > make_pair(r2, -c2);
            });

            for(int i = 0; i < groups.size(); i++) {
                allocated_seats[ids[i]] = groups[i];
            }

            // debug() << imie(ids) imie(groups);

            prev = val;
            groups.clear();
            groups.push_back(seat);
            ids.clear();
            ids.push_back(-order[seat].second);
        }
    }

    // debug() << imie(groups) imie(ids);

    sort(groups.begin(), groups.end(), [&](int u, int v) {
        int r1 = u / m;
        int c1 = u % m;
        int r2 = v / m;
        int c2 = v % m;

        return make_pair(r1, -c1) > make_pair(r2, -c2);
    });

    // debug() << imie(groups);

    for(int i = 0; i < groups.size(); i++) {
        allocated_seats[ids[i]] = groups[i];
    }

    // debug() << imie(allocated_seats);

    int inconvenience = 0;

    for(auto u: allocated_seats) {
        int row = u / m;
        int col = u % m;
        // debug() << imie(u) imie(row) << imie(col);
        for(int i = 0; i < col; i++) {
            inconvenience += seats[row][i];
        }
        seats[row][col] = 1;
    }

    cout << inconvenience << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}