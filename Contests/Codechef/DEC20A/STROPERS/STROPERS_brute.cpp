#include <bits/stdc++.h>
using namespace std;

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

#define mp make_pair

// length of the string, no of 1, zero gap, 0 in front
set<pair<pair<int,int>,pair<int,int>>> ans;

void process(string &s) {
    int l = s.length();
    int cnt = 0;
    int ones = 0;
    vector<int> diffs;
    for(int i=0;i<l;i++) {
        if(s[i] == '0') {
            cnt++;
        }
        else {
            diffs.push_back(i);
            cnt = 0;
            ones++;
        }
    }
    if(ones == 0) {
        ans.insert(mp(mp(l, ones), mp(l, l)));

        // debug() << imie(l);
        return;
    }
    if(ones == 1) {
        ans.insert(mp(mp(l, ones), mp(0, diffs[0] - 0)));
        // debug() << imie(0);
        return;
    }
    // debug() << imie(diffs);
    int zero_gap = 1e9;
    for(int i=0;i<ones-1;i++) {
        int sub = diffs[i] - i;
        diffs[i] -= sub;
        diffs[i+1] -= sub;
        // debug() << imie(diffs);
    }
    debug() << imie(diffs);

    zero_gap = diffs[ones - 1] - diffs[ones - 2];
    debug() << imie(zero_gap);

    ans.insert(mp(mp(l, ones), mp(zero_gap, 0)));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string test = "0010101010100";
    process(test);
    // test = "0111";
    // process(test);
    // debug() << imie(ans);
    exit(0);

    int t;
    cin >> t;
    while(t--) {
        ans.clear();
        string s;
        cin >> s;
        int n = s.length();



        for(int i=0;i<n;i++) {
            string tmp = "";
            for(int j=i;j<n;j++) {
                tmp += s[j];
                process(tmp);
            }
        }
        // debug() << imie(s);
        // for(auto u: ans) {
        //     debug() << imie(u);
        // }
        cout << ans.size() << '\n';
    }
}