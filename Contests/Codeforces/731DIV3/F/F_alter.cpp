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
    vector<int64_t> AD = A;
    for(auto u: A)
        AD.push_back(u);

    auto fun = [&](int i, int j) { return gcd(i, j); };
    SparseTable<int64_t, decltype(fun)> st(AD, fun);

    int l = 0, r = N;

    auto good = [&](int m) -> bool {

        int64_t prev = -1;
        for(int i = 0; i < N; i++) {
            if(prev == -1) {
                prev = st.get(i, i + m - 1);
            } else {
                int64_t curr = st.get(i, i + m - 1);
                if(curr != prev) {
                    return false;
                }
            }
        }


        return true;
    };

    while(r > l + 1) {
        int m = (r + l) / 2;
        if(good(m)) {
            r = m;
        } else {
            l = m;
        }
    }


    cout << r - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}