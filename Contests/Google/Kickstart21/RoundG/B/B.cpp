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

int64_t manhattan(pair<int,int> point1, pair<int,int> point2) {
    return abs(point1.first - point2.first) + abs(point1.second - point2.second);
}

int64_t distance(int x, int y, vector<int> point) {
    int x1 = point[0];
    int y1 = point[1];
    int x2 = point[2];
    int y2 = point[3];

    if(x1 <= x && x <= x2 && y1 <= y && y <= y2) {
        return 0;
    }

    if(x1 <= x && x <= x2) {
        return min(abs(y - y1), abs(y - y2));
    }

    if(y1 <= y && y <= y2) {
        return min(abs(x - x1), abs(x - x2));
    }

    return min({manhattan({x, y}, {x1, y1}), manhattan({x, y}, {x1, y2}), manhattan({x, y}, {x2, y1}), manhattan({x, y}, {x2, y2})});

}

void run_cases() {
    int K;
    cin >> K;

    vector<vector<int>> points(K, vector<int>(4));
    vector<int> x, y;
    for(int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x.push_back(x1);
        x.push_back(x1);
        x.push_back(x2);
        x.push_back(x2);

        y.push_back(y1);
        y.push_back(y1);
        y.push_back(y2);
        y.push_back(y2);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << x[x.size() / 2 - 1] << " " << y[y.size() / 2 - 1] << '\n';
    // debug() << imie(x) << '\n' << imie(y);
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