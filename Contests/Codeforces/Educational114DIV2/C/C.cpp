#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int64_t> A(N);

    for(auto &u: A)
        cin >> u;

    sort(A.begin(), A.end());

    int64_t sum = accumulate(A.begin(), A.end(), 0LL);

    int m;
    cin >> m;

    auto solve = [&](int64_t hero_attack, int64_t total_hero_attack, int64_t dragon_defence, int64_t dragon_attack){
        int64_t ans = 0;

        ans += max(int64_t(0), dragon_defence - hero_attack);

        int64_t total_defence = total_hero_attack - hero_attack;

        ans += max(int64_t(0), dragon_attack - total_defence);

        return ans;
    };

    while(m--) {
        int64_t x, y;
        cin >> x >> y;

        auto it = lower_bound(A.begin(), A.end(), x);

        int64_t ans = solve(*it, sum, x, y);

        if(it != A.begin()) {
            ans = min(ans, solve(*prev(it), sum, x, y));
        }

        if(next(it) != A.end()) {
            ans = min(ans, solve(*next(it), sum, x, y));
        }

        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}