#include <bits/stdc++.h>
#include <string>
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
    string s;
    cin >> s;
    vector<int64_t> facts = {1, 1};
    for(int i=2;i<=11;i++) {
        facts.push_back(facts.back() * i);
    }

    vector<int> contains;
    vector<int> may;
    vector<int> forbidden;
    for(int i=0;i<10;i++) {
        if(s[i] == 'o') {
            contains.push_back(i);
        }
        else if(s[i] == '?') {
            may.push_back(i);
        } else {
            forbidden.push_back(i);
        }
    }
    // debug() << imie(forbidden);

    auto valid = [&](string s) ->bool {

        for(auto u: contains) {
            char c = u + '0';
            // debug() << imie(c);
            if(count(s.begin(), s.end(), c) == 0) {
                return false;
            }
        }
        for(auto u: forbidden) {
            char c = u + '0';
            if(count(s.begin(), s.end(), c) >= 1) {
                return false;
            }
        }
        return true;
    };

    // debug() << imie(valid("0021"));

    int64_t ans = 0;
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            for(int k=0;k<10;k++) {
                for(int l=0;l<10;l++) {
                    string pin = to_string(i) + to_string(j) + to_string(k) + to_string(l);
                    if(valid(pin)) {
                        // debug() << imie(pin);
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}