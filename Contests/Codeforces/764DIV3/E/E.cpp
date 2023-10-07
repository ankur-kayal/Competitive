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
    int N, M;
    cin >> N >> M;

    map<pair<char, char>, vector<int>> range;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 1; j < M; j++) {
            range[{s[j - 1], s[j]}] = {j, j + 1, i + 1};
        }
    }

    debug() << imie(range);

    string S;
    cin >> S;

    debug() << imie(S);

    bool ok = true;

    vector<vector<int>> answer;

    for(int i = 0; i < M; i += 2) {
        if(range.count({S[i - 1], S[i]})) {
            answer.push_back(range[{S[i - 1], S[i]}]);
        } else {
            cout << -1 << '\n';
            return;
        }
    }

    cout << answer.size() << '\n';
    for(auto u: answer) {
        for(auto v: u) {
            cout << v << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}