#include <bits/stdc++.h>
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

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
 
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
 
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
 
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

void run_cases() {
    int N, E;
    cin >> N >> E;

    vector<int> A(N);

    for(auto &u: A) {
        cin >> u;
    }

    vector<vector<int>> partitions(E);
    for(int i = 0; i < E; i++) {
        for(int j = i; j < N; j += E) {
            if(A[j] == 1) {
                partitions[i].push_back(0);
            } else if(prime[A[j]]) {
                partitions[i].push_back(1);
            } else {
                partitions[i].push_back(2);
            }
        }
    }

    for(auto u: partitions) {
        debug() << imie(u);
    }

    vector<vector<int>> prefix_sums(E);
    for(int i = 0; i < E; i++) {
        int SZ = partitions[i].size();

        prefix_sums[i] = vector<int>(SZ + 1);
        for(int j = 0; j < SZ; j++) {
            prefix_sums[i][j + 1] = prefix_sums[i][j] + partitions[i][j];
        }
    }

    for(auto u: prefix_sums) {
        debug() << imie(u);
    }

    auto get_range_sum = [&](int i, int l, int r) {
        return prefix_sums[i][r + 1] - prefix_sums[i][l];
    };

    int64_t ans = 0;


    for(int i = 0; i < E; i++) {
        for(int j = 0; j < partitions[i].size(); j++) {
            int l = j;
            int r = partitions[i].size();


            while(r > l + 1) {
                int m = (l + r) / 2;
                if(get_range_sum(i, j, m) > 0) {
                    r = m;
                } else {
                    l = m;
                }
            }

            int ll = l - 1;
            int rr = partitions[i].size();

            while(rr > ll + 1) {
                int m = (ll + rr) / 2;
                if(get_range_sum(i, l, m) < 2) {
                    ll = m;
                } else {
                    rr = m;
                }
            }


            if(ll >= l && get_range_sum(i, l, ll) == 1) {
                ans += (ll - l);

            }
            debug() << imie(i) imie(j) imie(l) imie(ll) imie(ans);

        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    sieve(1e6 + 7);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}