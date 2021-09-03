#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

namespace atcoder {

    namespace internal {

        std::vector<int> sa_naive(const std::vector<int>& s) {
            int n = int(s.size());
            std::vector<int> sa(n);
            std::iota(sa.begin(), sa.end(), 0);
            std::sort(sa.begin(), sa.end(), [&](int l, int r) {
                if (l == r) return false;
                while (l < n && r < n) {
                    if (s[l] != s[r]) return s[l] < s[r];
                    l++;
                    r++;
                }
                return l == n;
            });
            return sa;
        }

        std::vector<int> sa_doubling(const std::vector<int>& s) {
            int n = int(s.size());
            std::vector<int> sa(n), rnk = s, tmp(n);
            std::iota(sa.begin(), sa.end(), 0);
            for (int k = 1; k < n; k *= 2) {
                auto cmp = [&](int x, int y) {
                    if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
                    int rx = x + k < n ? rnk[x + k] : -1;
                    int ry = y + k < n ? rnk[y + k] : -1;
                    return rx < ry;
                };
                std::sort(sa.begin(), sa.end(), cmp);
                tmp[sa[0]] = 0;
                for (int i = 1; i < n; i++) {
                    tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
                }
                std::swap(tmp, rnk);
            }
            return sa;
        }

        // SA-IS, linear-time suffix array construction
        // Reference:
        // G. Nong, S. Zhang, and W. H. Chan,
        // Two Efficient Algorithms for Linear Time Suffix Array Construction
        template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
        std::vector<int> sa_is(const std::vector<int>& s, int upper) {
            int n = int(s.size());
            if (n == 0) return {};
            if (n == 1) return {0};
            if (n == 2) {
                if (s[0] < s[1]) {
                    return {0, 1};
                } else {
                    return {1, 0};
                }
            }
            if (n < THRESHOLD_NAIVE) {
                return sa_naive(s);
            }
            if (n < THRESHOLD_DOUBLING) {
                return sa_doubling(s);
            }

            std::vector<int> sa(n);
            std::vector<bool> ls(n);
            for (int i = n - 2; i >= 0; i--) {
                ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
            }
            std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
            for (int i = 0; i < n; i++) {
                if (!ls[i]) {
                    sum_s[s[i]]++;
                } else {
                    sum_l[s[i] + 1]++;
                }
            }
            for (int i = 0; i <= upper; i++) {
                sum_s[i] += sum_l[i];
                if (i < upper) sum_l[i + 1] += sum_s[i];
            }

            auto induce = [&](const std::vector<int>& lms) {
                std::fill(sa.begin(), sa.end(), -1);
                std::vector<int> buf(upper + 1);
                std::copy(sum_s.begin(), sum_s.end(), buf.begin());
                for (auto d : lms) {
                    if (d == n) continue;
                    sa[buf[s[d]]++] = d;
                }
                std::copy(sum_l.begin(), sum_l.end(), buf.begin());
                sa[buf[s[n - 1]]++] = n - 1;
                for (int i = 0; i < n; i++) {
                    int v = sa[i];
                    if (v >= 1 && !ls[v - 1]) {
                        sa[buf[s[v - 1]]++] = v - 1;
                    }
                }
                std::copy(sum_l.begin(), sum_l.end(), buf.begin());
                for (int i = n - 1; i >= 0; i--) {
                    int v = sa[i];
                    if (v >= 1 && ls[v - 1]) {
                        sa[--buf[s[v - 1] + 1]] = v - 1;
                    }
                }
            };

            std::vector<int> lms_map(n + 1, -1);
            int m = 0;
            for (int i = 1; i < n; i++) {
                if (!ls[i - 1] && ls[i]) {
                    lms_map[i] = m++;
                }
            }
            std::vector<int> lms;
            lms.reserve(m);
            for (int i = 1; i < n; i++) {
                if (!ls[i - 1] && ls[i]) {
                    lms.push_back(i);
                }
            }

            induce(lms);

            if (m) {
                std::vector<int> sorted_lms;
                sorted_lms.reserve(m);
                for (int v : sa) {
                    if (lms_map[v] != -1) sorted_lms.push_back(v);
                }
                std::vector<int> rec_s(m);
                int rec_upper = 0;
                rec_s[lms_map[sorted_lms[0]]] = 0;
                for (int i = 1; i < m; i++) {
                    int l = sorted_lms[i - 1], r = sorted_lms[i];
                    int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
                    int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
                    bool same = true;
                    if (end_l - l != end_r - r) {
                        same = false;
                    } else {
                        while (l < end_l) {
                            if (s[l] != s[r]) {
                                break;
                            }
                            l++;
                            r++;
                        }
                        if (l == n || s[l] != s[r]) same = false;
                    }
                    if (!same) rec_upper++;
                    rec_s[lms_map[sorted_lms[i]]] = rec_upper;
                }

                auto rec_sa =
                    sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

                for (int i = 0; i < m; i++) {
                    sorted_lms[i] = lms[rec_sa[i]];
                }
                induce(sorted_lms);
            }
            return sa;
        }

    }  // namespace internal

    std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
        assert(0 <= upper);
        for (int d : s) {
            assert(0 <= d && d <= upper);
        }
        auto sa = internal::sa_is(s, upper);
        return sa;
    }

    template <class T> std::vector<int> suffix_array(const std::vector<T>& s) {
        int n = int(s.size());
        std::vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
        std::vector<int> s2(n);
        int now = 0;
        for (int i = 0; i < n; i++) {
            if (i && s[idx[i - 1]] != s[idx[i]]) now++;
            s2[idx[i]] = now;
        }
        return internal::sa_is(s2, now);
    }

    std::vector<int> suffix_array(const std::string& s) {
        int n = int(s.size());
        std::vector<int> s2(n);
        for (int i = 0; i < n; i++) {
            s2[i] = s[i];
        }
        return internal::sa_is(s2, 255);
    }

    // Reference:
    // T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,
    // Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its
    // Applications
    template <class T>
    std::vector<int> lcp_array(const std::vector<T>& s,
                               const std::vector<int>& sa) {
        int n = int(s.size());
        assert(n >= 1);
        std::vector<int> rnk(n);
        for (int i = 0; i < n; i++) {
            rnk[sa[i]] = i;
        }
        std::vector<int> lcp(n - 1);
        int h = 0;
        for (int i = 0; i < n; i++) {
            if (h > 0) h--;
            if (rnk[i] == 0) continue;
            int j = sa[rnk[i] - 1];
            for (; j + h < n && i + h < n; h++) {
                if (s[j + h] != s[i + h]) break;
            }
            lcp[rnk[i] - 1] = h;
        }
        return lcp;
    }

    std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
        int n = int(s.size());
        std::vector<int> s2(n);
        for (int i = 0; i < n; i++) {
            s2[i] = s[i];
        }
        return lcp_array(s2, sa);
    }

    // Reference:
    // D. Gusfield,
    // Algorithms on Strings, Trees, and Sequences: Computer Science and
    // Computational Biology
    template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
        int n = int(s.size());
        if (n == 0) return {};
        std::vector<int> z(n);
        z[0] = 0;
        for (int i = 1, j = 0; i < n; i++) {
            int& k = z[i];
            k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
            while (i + k < n && s[k] == s[i + k]) k++;
            if (j + z[j] < i + z[i]) j = i;
        }
        z[0] = n;
        return z;
    }

    std::vector<int> z_algorithm(const std::string& s) {
        int n = int(s.size());
        std::vector<int> s2(n);
        for (int i = 0; i < n; i++) {
            s2[i] = s[i];
        }
        return z_algorithm(s2);
    }

}  // namespace atcoder

int longestCommonSubstring(string &a, string &b) {

    vector<int> s;
    int m = 2;
    vector<string> paths = {a, b};

    vector<int> id;
    for(int i = 0; i < m; i++) {
        for(auto city: paths[i]) {
            s.push_back(city);
            id.push_back(i);
        }
        s.push_back(240 + i);
        id.push_back(i + 1);
    }

    int ans = 0;

    auto sa = atcoder::suffix_array(s);
    auto lcp = atcoder::lcp_array(s, sa);

    int l = 0;
    int c = 0;
    for(int r = 1; r < s.size(); r++) {
        if(id[sa[r]] != id[sa[r - 1]]) {
            ans = max(ans, lcp[r - 1]);
        }
    }

    return ans;
}

class DSU {
    public:
    vector<int> p;
    int n;
 
    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
 
    inline int find(int x) {
        return (x == p[x] ? x : (p[x] = find(p[x])));
    }
 
    inline bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;
 
    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }
 
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
 
    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }
 
    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_low.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }
 
    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }
 
    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};

void run_cases() {
    int N;
    cin >> N;

    vector<string> A(N);
    for(auto &u: A)
        cin >> u;

    // pre-processing starts here
    vector<int> s;
    int m = N;

    vector<int> id;
    for(int i = 0; i < m; i++) {
        for(auto city: A[i]) {
            s.push_back(city);
            id.push_back(i);
        }
        s.push_back(240 + i);
        id.push_back(i);
    }

    int ans = 0;

    auto sa = atcoder::suffix_array(s);
    auto lcp = atcoder::lcp_array(s, sa);

    RMQ<int> rmq(lcp);

    vector<vector<int>> indices(N);
    for(int i = 0; i < sa.size(); i++) {
        indices[id[sa[i]]].push_back(i);
    }

    // pre-processing ends here

    auto longestCommonSubstring = [&](int i, int j) -> int {
        vector<int> &a = indices[i];
        vector<int> &b = indices[j];

        int n = a.size();
        int m = b.size();

        int ans = 0;

        int starta = 0, startb = 0;
        while(starta < n && startb < m) {
            if(a[starta] < b[startb]) {
                ans = max(ans, rmq.query_value(a[starta], b[startb]));
                starta++;
            } else {
                ans = max(ans, rmq.query_value(b[startb], a[starta]));
                startb++;
            }
        }
        return ans;
    };

    vector<array<int, 3>> edges;

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int u = i, v = j;
            int weight = longestCommonSubstring(i, j);
            edges.push_back({weight, u, v});
        }
    }

    sort(edges.rbegin(), edges.rend());

    DSU dsu(N);

    int maximum = 0;

    for(auto &[weight, u, v]: edges) {
        if(dsu.unite(u, v)) {
            maximum += weight;
        }
    }

    cout << maximum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}