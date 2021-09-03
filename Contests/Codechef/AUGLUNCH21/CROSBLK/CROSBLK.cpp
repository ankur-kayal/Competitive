#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

// usage:
//   auto fun = [&](int i, int j) { return min(i, j); };
//   SparseTable<int, decltype(fun)> st(a, fun);
// or:
//   SparseTable<int> st(a, [&](int i, int j) { return min(i, j); });
template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
    int n;
    vector<vector<T>> mat;
    F func;
 
    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
 
    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};


void run_cases() {
    int N;
    cin >> N;

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    SparseTable<int64_t> rmq(A, [&](int64_t i, int64_t j) { return max(i, j); });

    vector<int> dp(N, N + 100);

    dp[0] = 0;

    for(int i = 1; i < N; i++) {
        int l = -1, r = i;
        while(r > l + 1) {
            int m = (r + l) / 2;
            if(rmq.get(m, i) <= A[i]) {
                r = m;
            } else {
                l = m;
            }
        }
        if(A[r] == A[i]) {
            dp[i] = min(dp[i], dp[r] + 1);
        }
        if(r - 1 >= 0 && A[r - 1] >= A[r]) {
            dp[i] = min(dp[i], dp[r - 1] + 1);
        }
    }

    if(dp[N - 1] >= N) {
        cout << -1 << '\n';
    } else {
        cout << dp[N - 1] << '\n';
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