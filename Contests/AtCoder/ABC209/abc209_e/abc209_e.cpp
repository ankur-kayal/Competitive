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
    map<string, vector<int>> prefix;
    map<string, vector<int>> suffix;
    vector<vector<int>> adj(N);
    vector<string> words(N);
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        words[i] = s;
        prefix[s.substr(0, 3)].push_back(i);
        suffix[s.substr(s.length() - 3, 3)].push_back(i);
    }

    vector<int> indeg(N);
    for(int i = 0; i < N; i++) {
        string word = words[i];
        string suf = word.substr(word.length() - 3, 3);
        for(auto j: prefix[suf]) {
            adj[j].push_back(i);
            indeg[i]++;
        }
    }

    vector<int> parity(N, false);


    // do stuff to change parity as needed

    for(auto u: parity) {
        if(u == 0) {
            cout << "Takahashi";
        } else if(u == 1) {
            cout << "Aoki";
        } else {
            cout << "Draw";
        }
        cout << '\n';
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