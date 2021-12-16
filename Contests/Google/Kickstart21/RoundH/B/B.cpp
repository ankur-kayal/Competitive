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
    int N;
    cin >> N;

    string S;
    cin >> S;

    /*
    U = 0
    R = 1
    Y = 2
    B = 3

    O = 1, 2
    P = 1, 3
    G = 2, 3
    A = 1, 2, 3
    */

    vector<vector<int>> codes(N);

    for(int i = 0; i < N; i++) {
        if(S[i] == 'U') {
            codes[i] = {0};
        }
        if(S[i] == 'R') {
            codes[i] = {1};
        }
        if(S[i] == 'Y') {
            codes[i] = {2};
        }
        if(S[i] == 'B') {
            codes[i] = {3};
        }
        if(S[i] == 'O') {
            codes[i] = {1, 2};
        }
        if(S[i] == 'P') {
            codes[i] = {1, 3};
        }
        if(S[i] == 'G') {
            codes[i] = {2, 3};
        }
        if(S[i] == 'A') {
            codes[i] = {1, 2, 3};
        }
    }

    int moves = 0;

    for(int code = 1; code <= 3; code++) {
        int segment = 0;
        for(int i = 0; i < N; i++) {
            bool present = false;
            for(auto u: codes[i]) {
                if(u == code) {
                    present = true;
                }
            }
            if(present) {
                segment++;
            } else {
                if(segment > 0) {
                    moves++;
                }
                segment = 0;
            }
        }
        if(segment > 0) {
            moves++;
        }
    }

    cout << moves << '\n';
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