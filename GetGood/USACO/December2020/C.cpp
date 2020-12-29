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

// const int inf = 2e9;
const int inf = 200;

int manhatten(pair<int,int> a, pair<int,int> b) {
    int dist = (a.first - b.first) + (a.second - b.second);

    return (dist < 0 ? inf : dist);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<pair<int,int>,char>> cows(n);
    vector<pair<pair<int,int>, int>> east, north;
    vector<int> ans(n, inf);

    for(int i=0;i<n;i++) {
        char ch;
        int x,y;
        cin >> ch >> x >> y;
        if(ch == 'E') {
            east.push_back(mp(mp(x,y), i));
        }
        else {
            north.push_back(mp(mp(x,y), i));
        }
    }


    sort(east.begin(), east.end(), [&](pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
        return a.first.second < b.first.second;
    });
    sort(north.begin(), north.end(), [&](pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
        return a.first.first < b.first.first;
    });
    debug() << imie(east);
    debug() << imie(north);


    for(auto u: north) {
        // auto u = cows[i];
        int index1 = u.second;
        int x1 = u.first.first;
        int y1 = u.first.second; 
        for(auto v: east) {
            int index2 = v.second;
            int x2 = v.first.first;
            int y2 = v.first.second;

            int x_intersection = x1;
            int y_intersection = y2;
            auto f = mp(x_intersection, y_intersection);
            int m1 = min(ans[index1], manhatten(f, mp(x1, y1)));
            int m2 = min(ans[index2], manhatten(f, mp(x2, y2)));
            if(m1 > m2) {
                ans[index1] = min(ans[index1], manhatten(f, mp(x1, y1)));
            }
            else if(m2 > m1 and y1 + m1 > y_intersection) {
                ans[index2] = min(ans[index2], manhatten(f, mp(x2,y2)));
            }
            debug() << imie(u) imie(v) imie(ans[index1]) imie(ans[index2]);
        }
    }

    debug() << imie(ans);

    for(auto u: east) {
        // auto u = cows[i];
        int index1 = u.second;
        int x1 = u.first.first;
        int y1 = u.first.second; 
        for(auto v: north) {
            int index2 = v.second;
            int x2 = v.first.first;
            int y2 = v.first.second;

            int x_intersection = x2;
            int y_intersection = y1;
            auto f = mp(x_intersection, y_intersection);
            int m1 = min(ans[index1], manhatten(f, mp(x1, y1)));
            int m2 = min(ans[index2], manhatten(f, mp(x2, y2)));
            if(m1 > m2 and y2 + m2 == y_intersection) {
                ans[index1] = min(ans[index1], manhatten(f, mp(x1, y1)));
            }
            // else {
            //     ans[index2] = min(ans[index2], manhatten(f, mp(x2,y2)));
            // }
            debug() << imie(u) imie(v) imie(ans[index1]);
        }
    }

    /*for(int i=0;i<n;i++) {
        auto u = cows[i];
        char direction1 = u.second;
        int x1 = u.first.first;
        int y1 = u.first.second; 
        int tmp = inf; 
        for(int j=0;j<n;j++) {
            auto v = cows[j];
            char direction2 = v.second;
            int x2 = v.first.first;
            int y2 = v.first.second;

            if(direction1 != direction2) {
                int x_intersection, y_intersection;
                if(direction1 == 'E') {
                    y_intersection = y1;
                    x_intersection = x2;
                } 

                else {
                    y_intersection = y2;
                    x_intersection = x1;
                }  
                auto f = mp(x_intersection, y_intersection);
                if(min(ans[i], manhatten(f, mp(x1, y1))) > min(ans[j], manhatten(f, mp(x2,y2)))) {
                    tmp = min(tmp, manhatten(f, mp(x1, y1)));
                }
                debug() << imie(u) imie(v) imie(f) imie(tmp);
            }
        }
        debug() << '\n';
        if(ans[i] == inf)
            ans[i] = min(tmp, ans[i]);
        else {
            ans[i] = max(tmp, ans[i]);
        }
    }*/
    

    for(auto u: ans) {
        cout << (u == inf ? "Infinity" : to_string(u)) << '\n';
    }
}