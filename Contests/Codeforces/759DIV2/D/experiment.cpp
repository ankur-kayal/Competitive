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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


/*
a b c
c a b
*/

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);
    iota(A.begin(), A.end(), 1);

    set<vector<int>> unique;

    for(int i = 0; i < 10000000; i++) {
        int x = uid(0, N - 1);
        int y = uid(0, N - 1);
        int z = uid(0, N - 1);
        if(x != y && y != z && z != x) {
            swap(A[x], A[z]);
            swap(A[x], A[y]);

            unique.insert(A);
        }
        
    }


    for(auto u: unique) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(u[i] != i + 1) {
                cnt++;
            }
        }
        if(cnt < 3)
        debug() << imie(u) imie(cnt);
    }

    cout << unique.size() << '\n';


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);


    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}