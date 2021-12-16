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
    int N;
    cin >> N;

    vector<int> parents(N);
    for(auto &u: parents) {
        cin >> u;
    }
    for(auto &u: parents) {
        u--;
    }

    vector<int> perm(N);
    for(auto &u: perm) {
        cin >> u;
    }

    for(auto &u: perm) {
        u--;
    }

    debug() << imie(parents) << '\n' << imie(perm);

    vector<int> vertex_dist(N, -1);
    vector<int64_t> vertex_dist_from_root(N, -1);
    vector<int64_t> dist;

    for(int i = 0; i < N; i++) {
        debug() << imie(i);
        int current_vertex = perm[i];
        if(vertex_dist_from_root[parents[current_vertex]] == -1) {
            if(parents[current_vertex] == current_vertex) {
                vertex_dist[current_vertex] = 0;
                vertex_dist_from_root[current_vertex] = 0;
                dist.push_back(0);
            } else {
                cout << -1 << '\n';
                return;
            }
        } else {
            int64_t last_dist = dist.back();
            int64_t parent_dist = vertex_dist_from_root[parents[current_vertex]];
            vertex_dist[current_vertex] = last_dist - parent_dist + 1;
            vertex_dist_from_root[current_vertex] = parent_dist + vertex_dist[current_vertex];
            dist.push_back(vertex_dist_from_root[current_vertex]);
        }
    }


    for(int i = 0; i < N; i++) {
        cout << vertex_dist[i] << ' ';
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