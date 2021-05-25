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
    vector<int> score(2, 0);
    set<int> matched;
    set<int> unmatched;
    vector<int> pos;
    int zeros = 0;
    for(int i=0;i<N;i++) {
        if(S[i] == '0') {
            pos.push_back(i);
            zeros++;
        }
    }

    for(auto u: pos) {
        if(unmatched.count(N - u - 1)) {
            unmatched.erase(N - u - 1);
            matched.insert(N - u - 1);
            matched.insert(u);
        } else {
            unmatched.insert(u);
        }
    }

    bool special = false;

    if((N & 1) && unmatched.count(N / 2)) {
        unmatched.erase(N / 2);
        special = true;
    }

    string tmp = S;
    reverse(tmp.begin(), tmp.end());
    if(tmp == S) {
        if(special && pos.size() != 1) {
            score[1] = 1;
        } else {
            score[0] = 1;
        }

        assert(score[0] != score[1]);

        if(score[0] == score[1]) {
            cout << "DRAW\n";
        } else if(score[0] > score[1]) {
            cout << "BOB\n";
        } else {
            cout << "ALICE\n";
        }
        return;
    }

    debug() << imie(matched) imie(unmatched) imie(special);

    if(matched.empty()) {
        if(unmatched.empty() && special) {
            cout << "BOB\n";
        } else if(unmatched.size() == 1) {
            if(special)
                cout << "DRAW\n";
            else
                cout << "ALICE\n";
        }
        else {
            cout << "ALICE\n";
        }
        return;
    }

    cout << "ALICE\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}