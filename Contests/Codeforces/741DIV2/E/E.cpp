#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define nl '\n'


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

template<typename T, bool maximum_mode = false>
struct RMQ {
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
 
    int n = 0;
    vector<vector<T>> range_min;
 
    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }
 
    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }
 
    void build(const vector<T> &values) {
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_min.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);
 
        if (n > 0)
            range_min[0] = values;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }
 
    T query_value(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};
 
template<typename T_string = string>
struct suffix_array {
    int n = 0;
    T_string str;
    vector<int> suffix;
    vector<int> rank;
    vector<int> lcp;
    RMQ<int> rmq;
 
    suffix_array() {}
 
    suffix_array(const T_string &_str, bool build_rmq = true) {
        build(_str, build_rmq);
    }
 
    void build(const T_string &_str, bool build_rmq = true) {
        str = _str;
        n = int(str.size());
        suffix.resize(n);
 
        for (int i = 0; i < n; i++)
            suffix[i] = i;
 
        bool large_alphabet = false;
 
        for (int i = 0; i < n; i++)
            if (str[i] < 0 || str[i] >= 128)
                large_alphabet = true;
 
        // Sort each suffix by the first character.
        if (large_alphabet) {
            sort(suffix.begin(), suffix.end(), [&](int a, int b) {
                return str[a] < str[b];
            });
        } else {
            vector<int> freq(128, 0);
 
            for (int i = 0; i < n; i++)
                freq[str[i]]++;
 
            for (int c = 1; c < 128; c++)
                freq[c] += freq[c - 1];
 
            for (int i = 0; i < n; i++)
                suffix[--freq[str[i]]] = i;
        }
 
        // Compute the rank of each suffix. Tied suffixes share the same rank.
        rank.resize(n);
        rank[suffix[0]] = 0;
 
        for (int i = 1; i < n; i++)
            rank[suffix[i]] = str[suffix[i]] == str[suffix[i - 1]] ? rank[suffix[i - 1]] : i;
 
        vector<int> next_index(n);
        vector<int> values(n);
        bool done = false;
 
        for (int len = 1; len < n && !done; len *= 2) {
            // next_index[i] = the next index to use for a suffix of rank i. We insert them in order of the rank of the
            // suffix that comes len characters after the current suffix.
            for (int i = 0; i < n; i++)
                next_index[i] = i;
 
            // Compute the suffix array for 2 * len. Suffixes of length <= len are prioritized first.
            for (int i = n - len; i < n; i++)
                values[next_index[rank[i]]++] = i;
 
            for (int i = 0; i < n; i++) {
                int prev = suffix[i] - len;
 
                if (prev >= 0)
                    values[next_index[rank[prev]]++] = prev;
            }
 
            swap(suffix, values);
 
            // Compute the rank array for 2 * len.
            values[suffix[0]] = 0;
            done = true;
 
            for (int i = 1; i < n; i++) {
                int s = suffix[i], prev = suffix[i - 1];
 
                if (s + len < n && prev + len < n && rank[s] == rank[prev] && rank[s + len] == rank[prev + len]) {
                    values[s] = values[prev];
                    done = false;
                } else {
                    values[s] = i;
                }
            }
 
            swap(rank, values);
        }
 
        compute_lcp();
 
        if (build_rmq)
            rmq.build(lcp);
    }
 
    void compute_lcp() {
        lcp.assign(n, 0);
        int match = 0;
 
        for (int i = 0; i < n; i++) {
            if (rank[i] == 0)
                continue;
 
            int a = suffix[rank[i]] + match;
            int b = suffix[rank[i] - 1] + match;
 
            while (a < n && b < n && str[a++] == str[b++])
                match++;
 
            // lcp[r] = the longest common prefix length of the suffixes starting at suffix[r] and at suffix[r - 1].
            // Note that lcp[0] is always 0.
            lcp[rank[i]] = match;
            match = max(match - 1, 0);
        }
    }
 
    int get_lcp_from_ranks(int a, int b) const {
        if (a == b)
            return n - suffix[a];
 
        if (a > b)
            swap(a, b);
 
        return rmq.query_value(a + 1, b + 1);
    }
 
    int get_lcp(int a, int b) const {
        if (a >= n || b >= n)
            return 0;
 
        if (a == b)
            return n - a;
 
        return get_lcp_from_ranks(rank[a], rank[b]);
    }
 
    // Compares the substrings starting at `a` and `b` up to `length` in O(1).
    int compare(int a, int b, int length = -1) const {
        if (length < 0)
            length = n;
 
        if (a == b)
            return 0;
 
        int common = get_lcp(a, b);
 
        if (common >= length)
            return 0;
 
        if (a + common >= n || b + common >= n)
            return a + common >= n ? -1 : 1;
 
        return str[a + common] < str[b + common] ? -1 : (str[a + common] == str[b + common] ? 0 : 1);
    }
};

void run_cases() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    suffix_array<string> sa(S);

    vector<pair<int,int>> sub; // start of substring, length of substring
    int id = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            sub.emplace_back(i, j - i + 1);
        }
    }
    int n = sub.size();
    vector<int> ids(n);
    vector<pair<pair<int,int>, int>> pairs(n);
    for(int i = 0; i < n; ++i) {
        pairs[i] = {sub[i], i};
    }

    // debug() << imie(pairs);

    auto sort_compare = [&](pair<int,int> &a, pair<int,int> &b) {
        int len = min(a.second, b.second);
        int i = a.first;
        int j = b.first;

        int lcp = sa.get_lcp(i, j);

        if(lcp == 0) {
            return S[i] < S[j];
        }

        int nexti, nextj;

        int length_to_check = min(len, lcp) + 1;

        if(length_to_check > a.second) {
            nexti = 0;
        } else {
            nexti = S[i + length_to_check - 1];
        }

        if(length_to_check > b.second) {
            nextj = 0;
        } else {
            nextj = S[j + length_to_check - 1];
        }
        // debug() << imie(a) imie(b) imie(nexti) imie(nextj) imie(lcp);
        return nexti < nextj;
    };

    // return;

    auto equal = [&](pair<int,int> &a, pair<int,int> &b) {
        int len = min(a.second, b.second);
        int i = a.first;
        int j = b.first;

        int lcp = sa.get_lcp(i, j);

        if(lcp == 0) {
            return S[i] == S[j];
        }

        int nexti, nextj;

        int length_to_check = min(len, lcp) + 1;

        if(length_to_check > a.second) {
            nexti = 0;
        } else {
            nexti = S[i + length_to_check - 1];
        }

        if(length_to_check > b.second) {
            nextj = 0;
        } else {
            nextj = S[j + length_to_check - 1];
        }
        // debug() << imie(a) imie(b) imie(nexti) imie(nextj) imie(lcp);
        return nexti == nextj;
    };

    sort(pairs.begin(), pairs.end(), [&](auto &a, auto &b) {
        return sort_compare(a.first, b.first);
    });

    // debug() << imie(pairs);
    // return;
    int nxt = 0;
    for(int i = 0; i < n; ++i) {
        
        if(i > 0 && !equal(pairs[i - 1].first, pairs[i].first)) nxt++;
        ids[pairs[i].second] = nxt;
    }

    // debug() << imie(ids);

    vector<int> dp;
    for(auto u: ids) {
        auto it = lower_bound(dp.begin(), dp.end(), u);
        if(it == dp.end()) {
            dp.push_back(u);
        } else {
            *it = u;
        }
    }

    cout << dp.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}