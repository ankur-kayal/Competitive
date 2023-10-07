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

    bool upper = false;
    for(auto u: S) {
        if(u >= 'A' && u <= 'Z') {
            upper = true;
        }
    }

    bool lower = false;
    for(auto u: S) {
        if(u >= 'a' && u <= 'z') {
            lower = true;
        }
    }

    bool num = false;
    for(auto u: S) {
        if(u >= '0' && u <= '9') {
            num = true;
        }
    }

    bool special = false;
    for(auto u: S) {
        if(u == '#' || u == '@' || u == '*' || u == '&') {
            special = true;
        }
    }

    if(!special) {
        S += '@';
    }
    if(!upper) {
        S += 'A';
    }
    if(!lower) {
        S += 'a';
    }
    if(!num) {
        S += '0';
    }

    while(S.length() < 7) {
        S += 'a';
    }

    cout << S << '\n';

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