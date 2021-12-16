#include <algorithm>
#include <bits/stdc++.h>
#include <exception>
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

const int64_t INF64 = 2e18;

void run_cases() {
    int N;
    cin >> N;

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    int64_t ans = INF64;

    sort(A.begin(), A.end());

    if(N <= 3) {
        if(N == 2) {
            cout << 0 << '\n';
        } else {
            cout << min(A[1] - A[0], A[2] - A[1]) << '\n';
        }
    } else {
        // fix start of first range to 0 and end of second range to N - 2
        int l = 1, r = N - 2;

        vector<int64_t> prefix_sums(N + 1);
        for(int i = 0; i < N; i++) {
            prefix_sums[i + 1] = prefix_sums[i] + A[i];
        }

        auto get_sum = [&](int l, int r) -> int64_t {
            if(l > r) {
                return 0;
            }
            return prefix_sums[r + 1] - prefix_sums[l];
        };

        while(r > l) {
            int64_t difference1 = A[r] - A[0];
            int64_t difference2 = A[N - 1] - A[l];

            ans = min(ans, abs(difference2 - difference1));

            if(difference1 > difference2) {
                r--;
            } else {
                l++;
            }
        }

        debug() << imie(ans) imie(A);

        // maybe divide the array into two halfs and change all values of the two halfs to the same values?
        for(int partition = 0; partition < N - 1; partition++) {
            int median_position_of_first_half = partition / 2;

            int64_t sum1 = 0;

            int64_t first_left = max(0, median_position_of_first_half);
            int64_t first_right = max(0, partition - median_position_of_first_half);
            int64_t first_median = A[median_position_of_first_half];

            sum1 = first_left * first_median - get_sum(0, median_position_of_first_half - 1);
            sum1 += get_sum(median_position_of_first_half + 1, partition) - first_right * first_median;

            int64_t sum2 = 0;

            int median_position_of_second_half = (partition + N) / 2;
            int64_t second_left = max(0, median_position_of_second_half - partition);
            int64_t second_right = max(0, N - median_position_of_second_half);
            int64_t second_median = A[median_position_of_second_half];

            sum2 += second_left * second_median - get_sum(partition + 1, median_position_of_second_half - 1);
            sum2 += get_sum(median_position_of_second_half + 1, N - 1) - second_right * second_median;

            debug() << imie(first_median) imie(first_left) imie(first_right);
            debug() << imie(second_median) imie(second_left) imie(second_right);
            debug() << imie(sum1) imie(sum2) imie(partition);
            debug() << '\n';

            ans = min(ans, sum1 + sum2);
        }

        cout << ans << '\n';
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