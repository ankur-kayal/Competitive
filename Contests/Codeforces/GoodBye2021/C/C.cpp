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

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    int ans = N;

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int start = A[i];
            int end = A[j];

            int difference = end - start;
            int number_of_terms = j - i;

            int hcf = gcd(difference, number_of_terms);
            difference /= hcf;
            number_of_terms /= hcf;

            int mul = 0;

            int change = 0;

            for(int k = i; k >= 0; k--) {
                if((i - k) % number_of_terms == 0) {
                    int req = start - mul * difference;
                    if(req != A[k]) {
                        change++;
                    }
                    mul++;
                } else {
                    change++;
                }
            }

            mul = 0;

            for(int k = j; k < N; k++) {
                if((k - j) % number_of_terms == 0) {
                    int req = end + mul * difference;
                    if(req != A[k]) {
                        change++;
                    }
                    mul++;
                } else {
                    change++;
                }
            }

            mul = 0;

            for(int k = i; k <= j; k++) {
                if((k - i) % number_of_terms == 0) {
                    int req = start + mul * difference;
                    if(req != A[k]) {
                        change++;
                    }
                    mul++;
                } else {
                    change++;
                }
            }

            debug() << imie(i) imie(j) imie(change) imie(difference) imie(number_of_terms);

            ans = min(ans, change);
        }
    }

    reverse(A.begin(), A.end());

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int start = A[i];
            int end = A[j];

            int difference = end - start;
            int number_of_terms = j - i;

            int hcf = gcd(difference, number_of_terms);
            difference /= hcf;
            number_of_terms /= hcf;

            int mul = 0;

            int change = 0;

            for(int k = i; k >= 0; k--) {
                if((i - k) % number_of_terms == 0) {
                    int req = start - mul * difference;
                    if(req != A[k]) {
                        change++;
                    }
                    mul++;
                } else {
                    change++;
                }
            }

            mul = 0;

            for(int k = j; k < N; k++) {
                if((k - j) % number_of_terms == 0) {
                    int req = end + mul * difference;
                    if(req != A[k]) {
                        change++;
                    }
                    mul++;
                } else {
                    change++;
                }
            }

            mul = 0;

            for(int k = i; k <= j; k++) {
                if((k - i) % number_of_terms == 0) {
                    int req = start + mul * difference;
                    if(req != A[k]) {
                        change++;
                    }
                    mul++;
                } else {
                    change++;
                }
            }

            debug() << imie(i) imie(j) imie(change) imie(difference) imie(number_of_terms);

            ans = min(ans, change);
        }
    }

    if(N == 1) {
        ans = 0;
    }


    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}