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

// usage:
//   auto fun = [&](int i, int j) { return min(i, j); };
//   RMQ<int, decltype(fun)> st(a, fun);
// or:
//   RMQ<int> st(a, [&](int i, int j) { return min(i, j); });

template<typename T, class F = function<T(const T&, const T&)>>
class RMQ {

public:
    int n;
    vector<vector<T>> mat;
    F func;

    RMQ(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for(int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for(int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query(int from, int to) const {
        assert(0 <= from && from <= to and to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        auto fun = [&](int i, int j) { return min(i,j);};
        RMQ<int,decltype(fun)> rmq(a,fun);
        vector<int> prefixMaxes(n), suffixMaxes(n);
        prefixMaxes[0] = a[0];
        suffixMaxes[n - 1] = a[n - 1];
        for(int i = 1; i < n; i++) {
            prefixMaxes[i] = max(prefixMaxes[i - 1], a[i]);
        }
        for(int i = n - 2; i >= 0; i--) {
            suffixMaxes[i] = max(suffixMaxes[i + 1], a[i]);
        } 
        unordered_map<int,int> lastTimeSuffixMaxIs, firstTimeSuffixMaxIs;
        for(int i=0;i<n;i++) {
            lastTimeSuffixMaxIs[suffixMaxes[i]] = i;
        }

        for(int i=n-1;i>=0;i--) {
            firstTimeSuffixMaxIs[suffixMaxes[i]] = i;
        }

        for(int l = 0; l + 2 < n; l++) {
            int val = prefixMaxes[l];
            int min = max(l + 2, firstTimeSuffixMaxIs[val]);
            int max = lastTimeSuffixMaxIs[val];
            while(min <= max) {
                int mid = (min + max) / 2;
                if(rmq.query(l + 1, mid - 1) == val) {
                    cout << "YES" << '\n';
                    int midSize = mid - l - 1;
                    int rightSize = n - mid;
                    cout << l + 1 << " " << midSize << " " << rightSize << '\n';
                    goto done;
                }
                else if(rmq.query(l + 1, mid - 1) < val) {
                    max = mid - 1;
                }
                else {
                    min = mid + 1;
                }
            }
        }

        cout << "NO" << '\n';
        done:

        continue;
    }

}