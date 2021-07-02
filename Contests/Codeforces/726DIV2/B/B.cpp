#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int64_t manhattan(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void run_cases() {
    int64_t N, M;
    cin >> N >> M;
    int64_t i, j;
    cin >> i >> j;

    int64_t dist = -1;
    pair<int64_t,int64_t> one = {-1, -1};
    pair<int64_t, int64_t> two = {-1, -1};

    vector<pair<int64_t, int64_t>> points = {{1, 1}, {1, M}, {N, 1}, {N, M}};

    for(auto u: points) {
        for(auto v: points) {
            int64_t tmp = manhattan(u, v) + manhattan({i, j}, u) + manhattan({i, j}, v);
            // debug() << imie(u) imie(v) imie(tmp);
            if(tmp > dist) {
                one = u;
                two = v;
                dist = tmp;
            }
        }
    }

    cout << one.first << " " << one.second << ' ';
    cout << two.first << " " << two.second << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}