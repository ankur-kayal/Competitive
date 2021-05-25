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
    int W, E;
    cin >> W >> E;
    map<char,int> cnt;
    map<char, char> ans = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    map<char, char> rev;
    cnt['P'] = 0;
    cnt['R'] = 0;
    cnt['S'] = 0;

    for(auto u: ans) {
        rev[u.second] = u.first;
    }

    for(int i=0;i<60;i++) {
        int max_cnt = -1;
        for(auto u: cnt) {
            max_cnt = max(max_cnt, u.second);
        }
        vector<char> choices;
        for(auto u: cnt) {
            if(u.second == max_cnt) {
                choices.push_back(u.first);
            }
        }
        if(choices.size() == 1) {
            cout << ans[choices[0]];
            cnt[choices[0]]++;
        } else if(choices.size() == 2) {
            char tmp;
            map<char, int> order;
            for(auto u: choices) {
                order[u]++;
                order[ans[u]]++;
            }
            int max_ans = -1;
            for(auto u: order) {
                max_ans = max(max_ans, u.second);
            }
            for(auto u: order) {
                if(u.second == max_ans) {
                    tmp = u.first;
                }
            }
            cout << tmp;
            cnt[rev[tmp]]++;
        } else {
            cout << ans['R'];
            cnt['R']++;
        }
        debug() << imie(cnt);
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    int X;
    cin >> X;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}