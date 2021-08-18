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

    vector<set<int>> adj(N + 1);
    for(int i = 0; i < N - 1; i++) {
        adj[i].insert(i + 1);
    }

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(a == 0) {
            adj[i].insert(N);
        } else {
            adj[N].insert(i);
        }
    }

    for(int start = 0; start < N - 1; start++) {
        int nxt = (start + 1) % N;
        if(adj[start].count(N) && adj[N].count(nxt)) {
            debug() << imie(start);
            for(int city = 0; city <= start; city++) {
                cout << city + 1 << " ";
            }
            cout << N + 1 << ' ';
            for(int city = start + 1; city < N; city++) {
                cout << city + 1 << " ";
            }
            cout << '\n';
            return;
        }
    }

    if(adj[N - 1].count(N)) {
        for(int i = 0; i <= N; i++) {
            cout << i + 1 << " ";
        }

        cout << '\n';
    } else if(adj[N].count(0)) {
        cout << N + 1 << " ";
        for(int i = 0; i < N; i++) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}