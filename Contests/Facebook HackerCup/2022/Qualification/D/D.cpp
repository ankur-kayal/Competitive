#include <bits/stdc++.h>
#include <time.h>
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

    clock_t start = clock();
    // debug();

    int N, M, Q;
    cin >> N >> M >> Q;

    debug() << imie(N) imie(M) imie(Q);

    vector<vector<pair<int64_t,int64_t>>> adj(N);

    for(int i = 1; i <= M; i++) {
        int64_t a, b, c;
        cin >> a >> b >> c;

        --a, --b;

        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    vector<unordered_map<int64_t, int64_t>> passengers_stage1(N);
    vector<unordered_map<int64_t, int64_t>> passengers_stage2(N);



    for(int i = 0; i < N; i++) {
        for(auto [child, cost]: adj[i]) {
            passengers_stage1[child][i] += cost;
        }
    }

    // for(int i = 0; i < N; i++) {
    //     debug() << imie(i) imie(passengers_stage1[i]);
    // }

    passengers_stage2 = passengers_stage1;

    for(int i = 0; i < N; i++) {
        for(auto [child, cost]: adj[i]) {
            passengers_stage2[child][i] += cost;
            for(auto [from, cost2]: passengers_stage1[i]) {
                passengers_stage2[child][from] += min(cost, cost2);
            }
        }
    }

    // debug();

    // for(int i = 0; i < N; i++) {
    //     debug() << imie(i) imie(passengers_stage2[i]);
    // }

    while(Q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;

        cout << passengers_stage2[b][a] << ' ';
    }

    cout << '\n';

    clock_t end = clock();

    debug() << "\nTime elapsed: " << 1000 * (end - start) / CLOCKS_PER_SEC << "ms\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("d_validation_input.txt", "r", stdin);
    // freopen("d_validation_output.txt", "w", stdout);

    /*For final submit*/
    // freopen("d_final_input.txt", "r", stdin);
    // freopen("d_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}