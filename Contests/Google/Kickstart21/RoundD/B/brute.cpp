#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t N, C;
    cin >> N >> C;
    const int64_t maxL = 1e4;
    vector<int64_t> sum(maxL + 10);
    for(int i = 0; i < N; i++) {
        int64_t L, R;
        cin >> L >> R;
        assert(1 <= L && L <= maxL);
        assert(1 <= R && R <= maxL);
        sum[L + 1]++;
        sum[R]--;
    }
    priority_queue<int64_t> pq;
    for(int i = 1; i <= maxL; i++) {
        sum[i] += sum[i - 1];
        if(sum[i] == 0) continue;
        pq.push(sum[i]);
    }
    int64_t ans = N;
    while(C > 0 && !pq.empty()) {
        ans += pq.top();
        pq.pop();
        C--;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}