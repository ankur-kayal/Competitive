#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    map<pair<int,int>, int> cache;

    vector<array<int, 3>> segments;
    for(int i = 0; i < N; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        segments.push_back({l, r, c});
    }

    pair<int,int> left = {segments[0][0], segments[0][2]};
    pair<int,int> right = {-segments[0][1], segments[0][2]};

    pair<int,int> ans = {segments[0][1] - segments[0][0] + 1, -segments[0][2]};

    for(int i = 0; i < N; i++) {
        int l = segments[i][0];
        int r = segments[i][1];
        int c = segments[i][2];

        cache[{l, r}] = c;

        left = min(left, {l, c});
        right = min(right, {-r, c});

        int current_cost = left.second + right.second;
        int total_elements = -right.first - left.first + 1;

        if(cache.count({left.first, -right.first})) {
            current_cost = min(current_cost, cache[{left.first, -right.first}]);
        }

        ans = max(ans, {total_elements, -current_cost});

        cout << -ans.second << '\n';
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