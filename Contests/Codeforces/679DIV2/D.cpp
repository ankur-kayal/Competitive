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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int n;
    cin >> n;
    vector<int> ans;
    vector<pair<char, int>> queries;
    for(int i=0;i<2*n;i++) {
        char ch;
        int val;
        cin >> ch;
        if(ch == '+') {
            queries.emplace_back(ch, 0);
        }
        else {
            cin >> val;
            queries.emplace_back(ch, val);
        }
    }

    reverse(queries.begin(), queries.end());
    vector<int> tmp;
    debug() << imie(queries);
    int extra_life = 0;
    bool game_over = false;
    for(auto u: queries) {
        char ch;
        int val;
        tie(ch, val) = u;
        if(ch == '-') {
            if(tmp.size() == 0 or tmp.back() > val) {
                tmp.push_back(val);
                extra_life--;
            }
            else if(tmp.back() < val) {
                if(extra_life > 0) {
                    extra_life--;
                    tmp.push_back(val);
                }
                else {
                    game_over = true;
                }
            }
        }
        else {
            extra_life++;
            if(tmp.size() == 0) {
                game_over = true;
                break;
            }
            else {
                ans.push_back(tmp.back());
                tmp.pop_back();
            }
        }
        debug() << imie(tmp) imie(extra_life);
    }

    if(!game_over) {
        reverse(ans.begin(), ans.end());
        cout << "YES" << '\n';
        for(auto u: ans) {
            cout << u << " ";
        }
    }    
    else {
        cout << "NO\n";
    }  
}