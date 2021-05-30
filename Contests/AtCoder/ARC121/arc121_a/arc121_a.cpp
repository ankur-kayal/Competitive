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

int64_t calc(vector<int64_t> &a, vector<int64_t> &b) {
    int64_t res = 0;
    for(int64_t i=0;i<(int64_t)a.size();i++) {
        res = max(res, abs(a[i]-b[i]));
    }
    return res;
}

struct Edge {
    int64_t u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

void run_cases() {
    int64_t n,d;
    cin >> n;
    d = 2;

    if(n <= 5000) {
        vector<vector<int64_t>> pts(n, vector<int64_t>(2));
        for(int i=0;i<n;i++) {
            cin >> pts[i][0] >> pts[i][1];
        }
        vector<int> weight;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                weight.push_back(calc(pts[i], pts[j]));
            }
        }
        sort(weight.rbegin(), weight.rend());
        cout << weight[1] << '\n';
        return;
    }

    vector<vector<int64_t>> pts(n,vector<int64_t>(5,0));

    for(int64_t i=0;i<n;i++) {
        for(int64_t j=0;j<5;j++) {
            pts[i][j] = 0;
        }
    }

    for(int64_t i=0;i<n;i++) {
        for(int64_t j=0;j<d;j++) {
            cin >> pts[i][j];
        }
    }

    // find the central point of partition for each dimention

    vector<int64_t> central(5,0);
    for(int64_t i=0;i<n;i++) {
        for(int64_t j=0;j<5;j++) {
            central[j] += pts[i][j];
        }
    }

    for(int64_t i=0;i<5;i++) {
        central[i] /= n;
    }

    vector<vector<int64_t>> quadrant(32, vector<int64_t>(5,0));
    vector<int64_t> qpt(32,-1);
    for(int64_t i=0;i<32;i++) {
        for(int64_t j=0;j<5;j++) {
            quadrant[i][j] = central[j];
        }
    }

    for(int64_t i=0;i<n;i++) {
        int64_t score = 0;
        for(int64_t j=0;j<5;j++) {
            if(pts[i][j] <= central[j]) {
                score += (1<<j);
            }
        }
        if(calc(quadrant[score], central) < calc(pts[i], central)) {
            qpt[score] = i;
            quadrant[score] = pts[i];
        }
    }

    vector<Edge> edges;

    for(int64_t i=0;i<n;i++) {
        for(int64_t j=0;j<32;j++) {
            if(qpt[j] != -1 and i != qpt[j]) {
                Edge tmp;
                tmp.u = i;
                tmp.v = qpt[j];
                tmp.weight = calc(pts[i], pts[qpt[j]]);
                edges.push_back(tmp);
            }
        }
    }

    vector<int64_t> ans;
    set<pair<int,int>> cnt;
    for(auto edge: edges) {
        if(cnt.count({edge.u, edge.v}) || cnt.count({edge.v, edge.u})) {
            continue;
        } else {
            ans.push_back(edge.weight);
            cnt.insert({edge.u, edge.v});
            cnt.insert({edge.v, edge.u});
        }
    }

    sort(ans.rbegin(), ans.rend());
    assert(ans.size() >= 2);

    cout << ans[1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}