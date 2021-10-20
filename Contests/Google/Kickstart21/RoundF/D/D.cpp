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

void run_cases() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> L(N), R(N), A(N);

    for(int i = 0; i < N; i++) {
        cin >> L[i] >> R[i] >> A[i];
    }

    vector<vector<int>> adj(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    vector<vector<int>> ways;

    do {

        vector<bool> marked(N);
        marked[order[0]] = true;
        vector<int> tmp = {order[0]};

        int magic = A[order[0]];

        for(int i = 1; i < N; i++) {
            if(magic == K) {
                break;
            }
            if(magic > K) {
                break;
            }
            bool found = false;
            for(int j = 0; j < N; j++) {
                if(marked[j]) {
                    for(int child: adj[j]) {
                        if(child == order[i]) {
                            found = true;
                            break;
                        }
                    }
                }
                if(found) {
                    break;
                }
            }
            if(found && (L[order[i]] <= magic && magic <= R[order[i]])) {
                magic += A[order[i]];
                marked[order[i]] = true;
            } else {
                break;
            }
            tmp.push_back(order[i]);
        }

        if(magic == K) {
            ways.push_back(tmp);
        }

    } while(next_permutation(order.begin(), order.end()));

    sort(ways.begin(), ways.end());

    ways.resize(unique(ways.begin(), ways.end()) - ways.begin());

    cout << ways.size() << '\n';
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