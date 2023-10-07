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

int pro(int N) {
    int ans = 1;
    for(auto u: to_string(N)) {
        ans *= (u - '0');
    }
    return ans;
}

int sum(int N) {
    int ans = 0;
    for(auto u: to_string(N)) {
        ans += (u - '0');
    }
    return ans;
}

vector<int> numbers;

vector<unordered_map<int64_t, unordered_map<int64_t, int64_t>>> dp_cache(13);

void precompute2() {
    int64_t pro = 1;
    int64_t sum = 0;
    unordered_map<int64_t, unordered_map<int64_t, int64_t>> dp;
    dp[pro][sum] = 1;


    for(int i = 0; i < 13; i++) {
        dp_cache[i] = dp;
        unordered_map<int64_t, unordered_map<int64_t, int64_t>> newDp;
        if(i == 0) {
            for(int d = 1; d <= 9; d++) {
                for(auto [product, v]: dp) {
                    for(auto [add, cnt]: v) {
                        newDp[product * d][add + d] += cnt;
                    }
                }
            }
        } else {
            for(int d = 0; d <= 9; d++) {
                for(auto [product, v]: dp) {
                    for(auto [add, cnt]: v) {
                        newDp[product * d][add + d] += cnt;
                    }
                }
            }
        }

        dp = newDp;
    }

    dp_cache[12] = dp;
}



int64_t solve(vector<bool> type, vector<int> digits) {
    int N = digits.size();
    reverse(type.begin(), type.end());
    reverse(digits.begin(), digits.end());

    int same = 0;
    for(int i = 0; i < N; i++) {
        if(!type[i] && digits[i] == 9) {
            same++;
        }
    }


    unordered_map<int64_t, unordered_map<int64_t, int64_t>> dp = dp_cache[same];

    for(int i = same; i < N; i++) {
        unordered_map<int64_t, unordered_map<int64_t, int64_t>> newDp;
        if(i == N - 1) {
            for(int d = 1; d <= digits[i]; d++) {
                for(auto [product, v]: dp) {
                    for(auto [add, cnt]: v) {
                        newDp[product * d][add + d] += cnt;
                    }
                }
            }
        } else {
            for(int d = 0; d <= digits[i]; d++) {
                for(auto [product, v]: dp) {
                    for(auto [add, cnt]: v) {
                        newDp[product * d][add + d] += cnt;
                    }
                }
            }
        }

        dp = newDp;
    }


    int64_t ans = 0;
    for(auto [product, v]: dp) {
        for(auto [add, cnt]: v) {
            if(product % add == 0) {
                ans += cnt;
            }
        }
    }
    debug() << imie(ans);
    return ans;
}

vector<int64_t> cache(13);
void precompute() {
    for(int l = 1; l < 13; l++) {
        vector<bool> type(l);
        vector<int> digits(l, 9);
        cache[l] = solve(type, digits);
    }
}


int64_t compute(int64_t N) {
    if(N == 0) {
        return 0;
    }

    string NS = to_string(N);
    debug() << imie(NS);

    int64_t ans = 0;

    for(int l = 1; l < NS.length(); l++) {
        ans += cache[l];
    }

    debug() << imie(ans);
    

    vector<bool> type(NS.length());
    vector<int> digits(NS.length(), 9);

    for(int i = 0; i < NS.length(); i++) {
        if(NS[i] == '0') {
            type[i] = true;
            digits[i] = NS[i] - '0';
            continue;
        }
        if(i == 0 && NS[i] == '1') {
            type[i] = true;
            digits[i] = NS[i] - '0';
            continue;
        }


        digits[i] = (NS[i] - '0') - 1;
        ans += solve(type, digits);
        digits[i]++;
        type[i] = true;      
    }

    ans += solve(type, digits);

    return ans;
}

void run_cases() {
    int64_t A, B;
    cin >> A >> B;

    cout << compute(B) - compute(A - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    precompute2();
    precompute();
    debug() << imie(cache);

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}