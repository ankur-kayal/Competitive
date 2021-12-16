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
    /*
    01 - 2
    12 - 3
    23 - 4
    34 - 5
    45 - 6
    56 - 7
    67 - 8
    78 - 9
    89 - 0
    90 - 1
    */

    /*
    01122334455667788990
    2345678910
    23 45 67 89 10
    468010
    46820
    */

    int N;
    cin >> N;

    string S;
    cin >> S;

    map<string, string> cache = {{"01", "2"}, {"12", "3"}, {"23", "4"}, {"34", "5"}, {"45", "6"}, 
    {"56", "7"}, {"67", "8"}, {"78", "9"}, {"89", "0"}, {"90", "1"}};

    vector<string> initial;
    vector<char> final;
    for(int i = 0; i < 10; i++) {
        string value = to_string(i) + to_string((i + 1) % 10);
        initial.push_back(value);
        final.push_back(char('0' + (i + 2) % 10));
    }

    for(int i = 0; i < N; i++) {
        
    }

    vector<char> value(N);
    vector<bool> used(N, false);
    vector<int> before(N, -1), after(N, -1);

    for(int i = 0; i < N; i++) {
        value[i] = S[i];
        if(i - 1 >= 0) {
            before[i] = i - 1;
        }
        if(i + 1 < N) {
            after[i] = i + 1;
        }
    }

    vector<vector<int>> positions(10);

    // debug() << imie(cache);

    while(true) {
        bool operation = false;
        for(auto [old_key, new_key] : cache) {
            for(int i = 0; i < )
        }
        if(old == S) {
            break;
        }
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