#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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

    string S;
    cin >> S;

    vector<vector<int>> occurances(N + 1, vector<int>(26, 0));

    for(int i = 0; i < N; i++) {
        occurances[i + 1] = occurances[i];
        occurances[i + 1][S[i] - 'A']++;
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int L, R, K;
        cin >> L >> R >> K;

        vector<int> sub = occurances[R];

        for(int i = 0; i < 26; i++) {
            sub[i] -= occurances[L - 1][i];
        }

        if(R - L + 1 < K) {
            cout << "NO\n";
        } else {

            if(*max_element(sub.begin(), sub.end()) > K) {
                cout << "NO\n";
            } else if(*max_element(sub.begin(), sub.end()) == K) { 
                string ans = "";

                int index = 0;

                while(index < 26) {
                    if(sub[index] == 0) {
                        index++;
                        continue;
                    }

                    ans += char(index + 'A');
                    sub[index]--;
                }

                reverse(ans.begin(), ans.end());

                cout << "YES\n";

                cout << ans << '\n';
            } else {
                string second_half = "";
                string first_half = "";

                int index = 0;
                while(K > 0) {
                    if(sub[index] == 0) {
                        index++;
                        continue;
                    }

                    second_half += char(index + 'A');
                    sub[index]--;
                    K--;
                }

                while(index < 26) {
                    if(sub[index] == 0) {
                        index++;
                        continue;
                    }

                    first_half += char(index + 'A');
                    sub[index]--;
                }

                reverse(first_half.begin(), first_half.end());

                cout << "YES\n";
                cout << first_half + second_half << '\n';
            }
        }
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