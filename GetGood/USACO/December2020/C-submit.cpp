#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

const int inf = 2e9;

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


    for(auto u: north) {
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
            else if(m2 > m1 and y1 + m1 >= y_intersection) {
                ans[index2] = min(ans[index2], manhatten(f, mp(x2,y2)));
            }
        }
    }

    for(auto u: east) {
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
        }
    }
    for(auto u: ans) {
        cout << (u == inf ? "Infinity" : to_string(u)) << '\n';
    }
}