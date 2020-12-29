#include <algorithm>
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

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<pair<int,int>> path;
        int x = 0, y = 0;
        for(auto u: s) {
            if(u == 'U') {
                y++;
            }
            if(u == 'D') {
                y--;
            }
            if(u == 'R') {
                x++;
            }
            if(u == 'L') {
                x--;
            }
            path.push_back({x,y});
        }

        debug() << imie(path);
        bool found = false;
        for(auto u: path) {
            pair<int,int> obstacle = u;
            pair<int,int> end = {0, 0};
            pair<int,int> start = {0, 0};

            for(auto u: s) {
                if(u == 'U') {
                    end.second++;
                    if(end == obstacle) {
                        end.second--;
                    }
                }
                if(u == 'D') {
                    end.second--;
                    if(end == obstacle) {
                        end.second++;
                    }
                }
                if(u == 'R') {
                    end.first++;
                    if(end == obstacle) {
                        end.first--;
                    }
                }
                if(u == 'L') {
                    end.first--;
                    if(end == obstacle) {
                        end.first++;
                    }
                }
            }
            if(end == start) {
                cout << u.first << " " << u.second << '\n';
                found = true;
                break;
            }
        }
        if(!found) {
            cout << 0 << " " << 0 << '\n';
        }
 
    }
}