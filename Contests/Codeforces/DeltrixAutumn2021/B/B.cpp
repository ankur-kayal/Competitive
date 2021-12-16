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
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    int abc = 0;
    for(int i = 0; i < N - 2; i++) {
        if(S.substr(i, 3) == "abc") {
            abc++;
        }
    }

    while(Q--) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        if(pos - 2 >= 0) {
            string before = S.substr(pos - 2, 3);
            if(before == "abc") {
                abc--;
            }
        }
        if(pos + 2 < N) {
            string before = S.substr(pos, 3);
            if(before == "abc") {
                abc--;
            }
        }
        if(pos - 1 >= 0 && pos + 1 < N) {
            string before = S.substr(pos - 1, 3);
            if(before == "abc") {
                abc--;
            }
        }

        S[pos] = c;

        if(pos - 2 >= 0) {
            string before = S.substr(pos - 2, 3);
            if(before == "abc") {
                abc++;
            }
        }
        if(pos + 2 < N) {
            string before = S.substr(pos, 3);
            if(before == "abc") {
                abc++;
            }
        }
        if(pos - 1 >= 0 && pos + 1 < N) {
            string before = S.substr(pos - 1, 3);
            if(before == "abc") {
                abc++;
            }
        }

        cout << abc << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}