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
    int N, K;
    cin >> N >> K;

    deque<int> A(N), B(N);
    for(auto &u: A) {
        cin >> u;
    }

    for(auto &u: B) {
        cin >> u;
    }

    int moves = 0;

    while(A.front() != B.front()) {
        A.push_back(A.front());
        moves++;
        A.pop_front();
    }

    for(int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            cout << "NO" << '\n';
            // debug() << false;
            return;
        }
    }

    bool ok = true;

    int min_cycle = 2;
    int max_cycle = N;

    if (K == 0 && moves > 0) {
        ok = false;
    }

    if (moves == 0) {
        if (K == 1) {
            ok = false;
        }
        if (N == 2 && K % 2 == 1) {
            ok = false;
        }
    } else {
        if (N == 2 && K % 2 == 0) {
            ok = false;
        }
    }

    // debug() << imie(ok);

    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("a1_validation_input.txt", "r", stdin);
    // freopen("a1_validation_output.txt", "w", stdout);

    /*For final submit*/
    freopen("a1_final_input.txt", "r", stdin);
    freopen("a1_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}