#include <bits/stdc++.h>
using namespace std;


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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        int N;
        cin >> N;
        vector<int> A(N), P(N);
        for(auto &u: A)
            cin >> u;
        for(auto &u: P)
            cin >> u;

        vector<vector<int>> types(2, vector<int>(N));
        types[0] = A;
        for(auto &u: P) {
            --u;
        }

        for(int i=0;i<N;i++) {
            types[1][P[i]] = A[i];
        }

        int Q;
        cin >> Q;
        while(Q--) {
            int ch;
            cin >> ch;
            debug() << imie(ch);
            if(ch == 1) {
                swap(types[0], types[1]);
                vector<int> B(N);
                for(int i=0;i<N;i++) {
                    B[P[i]] = A[i]; 
                }
                A = B;
                
            } else if(ch == 2) {
                int x, y;
                cin >> x >> y;
                --x, --y;
                // makes swaps intelligently
                swap(types[0][x], types[0][y]);
                swap(types[1][P[x]], types[1][P[y]]);
                swap(A[x], A[y]);
            } else {
                int x;
                cin >> x;
                --x;
                cout << types[0][x] << '\n';
            }
            debug() << imie(A)  << '\n' << imie(types[0]) << '\n' << imie(types[1]) << '\n';
        }
    }
}