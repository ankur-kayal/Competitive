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

bool valid(string S) {
    for(int i = 0; i <= int(S.length() - 5); i++) {
        string req = S.substr(i, 5);
        string rev = req;
        reverse(rev.begin(), rev.end());
        if(req == rev) {
            return false;
        }
    }

    for(int i = 0; i <= int(S.length() - 6); i++) {
        string req = S.substr(i, 6);
        string rev = req;
        reverse(rev.begin(), rev.end());
        if(req == rev) {
            return false;
        }
    }

    return true;
}

void run_cases() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> questions;
    for(int i = 0; i < N; i++) {
        if(S[i] == '?') {
            questions.push_back(i);
        }
    }

    int toFill = questions.size();

    for(int mask = 0; mask < (1 << toFill); mask++) {
        string P = S;
        for(int bit = 0; bit < toFill; bit++) {
            if(mask >> bit & 1) {
                P[questions[bit]] = '1';
            } else {
                P[questions[bit]] = '0';
            }
        }

        if(valid(P)) {
            cout << "POSSIBLE" << '\n';
            return;
        } 
    }

    cout << "IMPOSSIBLE" << '\n';

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