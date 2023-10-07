#include <bits/stdc++.h>
#include <unordered_map>
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

    vector<string> S(N);
    for(auto &u: S) {
        cin >> u;
    } 

    unordered_map<string, int> cnt;

    vector<int> included(26);

    for(auto u: S)
        cnt[u]++;

    for(auto u: S) {
        if(u.length() == 3) {
            string req = "";
            req += u[1] + u[0];
            if(cnt[req]) {
                included[u[2] - 'a'] = 1;
            }
        }
    }

    
    for(auto u: S) {
        // check is 1 length string exists
        if(u.length() == 1) {
            cout << "YES\n";
            return;
        }
        // check if 2 length string is palindrome
        if(u.length() == 2 && u[0] == u[1]) {
            cout << "YES\n";
            return;
        }

        // check if 2 length string ab ba exists or not
        if(u.length() == 2) {
            cnt[u]--;
            string req = "";
            req += u[1];
            req += u[0];
            if(cnt[req]) {
                cout << "YES\n";
                return;
            }
            cnt[u]++;
        }

        if(u.length() == 3) {
            string rev = u;
            reverse(rev.begin(), rev.end());
            if(rev == u) {
                cout << "YES\n";
                return;
            }

            string req = "";
            req += u[2];
            req += u[1];
            if(cnt[req]) {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    for(auto u: S) {
        if(u.length() == 3) {
            string len2 = "";
            len2 += u[1];
            len2 += u[0];
            if(cnt[len2] && included[u[2] - 'a']) {
                cout << "YES" << '\n';
                return;
            }
        }
    }


    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}