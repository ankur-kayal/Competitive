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
    int N, M, K;
    cin >> N >> M >> K;

    if(M == 1 && K > 0) {
        cout << "NO\n";
        return;
    }

    int horizontal = K;
    int vertical = N * M  / 2 - K;

    vector<vector<char>> ans(N, vector<char>(M, '#'));

    if(N % 2 == 1) {
        horizontal -= M / 2;
        bool flip = 0;
        char c1 = 'a';
        char c2 = 'b';
        for(int i = 0; i < M; i += 2) {
            if(flip) {
                ans[N - 1][i] = c2;
                ans[N - 1][i + 1] = c2;
            } else {
                ans[N - 1][i] = c1;
                ans[N - 1][i + 1] = c1;
            }
            flip = !flip;
        }
    } else if(M % 2 == 1) {
        vertical -= N / 2;
        bool flip = 0;
        char c1 = 'c';
        char c2 = 'd';
        for(int i = 0; i < N; i += 2) {
            if(flip) {
                ans[i][M - 1] = c2;
                ans[i + 1][M - 1] = c2;
            } else {
                ans[i][M - 1] = c1;
                ans[i + 1][M - 1] = c1;
            }
            flip = !flip;
        }
    }

    if(horizontal >= 0 && vertical >= 0 && horizontal % 2 == 0) {
        cout << "YES\n";
        
        char h[] = {'e', 'f', 'g', 'h'};
        char c[] = {'i', 'j', 'k', 'l'};

        // first fill all horizontal ones
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(horizontal == 0) {
                    break;
                }
                if(ans[i][j] == '#') {
                    bool cond1 = true;
                    bool cond2 = true;
                    if(i - 1 >= 0 && (ans[i - 1][j] == h[0] || ans[i - 1][j + 1] == h[0])) {
                        cond1 = false;
                    }
                    if(j - 1 >= 0 && ans[i][j - 1] == h[0]) {
                        cond2 = false;
                    }
                    debug() << imie(i) imie(j) imie(cond1) imie(cond2);
                    if(cond1 && cond2) {
                        ans[i][j] = h[0];
                        ans[i][j + 1] = h[0];
                        ans[i + 1][j] = h[1];
                        ans[i + 1][j + 1] = h[1];
                    } else {
                        ans[i][j] = h[1];
                        ans[i][j + 1] = h[1];
                        ans[i + 1][j] = h[0];
                        ans[i + 1][j + 1] = h[0];
                    }
                    horizontal -= 2;
                }
            }
        }

        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < M; j++) {
        //         if(vertical == 0) {
        //             break;
        //         }
        //         if(ans[i][j] == '#') {

        //             bool cond1 = true;
        //             bool cond2 = true;
        //             if(j - 1 >= 0 && ans[i][j - 1] == c[0]) {
        //                 cond1 = false;
        //             }
        //             if(i - 2 >= 0 && ans[i - 2][j] == c[0]) {
        //                 cond2 = false;
        //             }
        //             debug() << imie(i) imie(j) imie(cond1) imie(cond2);
        //             if(cond1 && cond2) {
        //                 ans[i][j] = c[0];
        //                 ans[i + 1][j] = c[0];
        //                 ans[i][j + 1] = c[1];
        //                 ans[i + 1][j + 1] = c[1];
        //             } else {
        //                 ans[i][j] = c[1];
        //                 ans[i + 1][j] = c[1];
        //                 ans[i][j + 1] = c[0];
        //                 ans[i + 1][j + 1] = c[0];
        //             }
        //         }
        //     }
        // }

        for(int i = N - 1; i >= 0; i--) {
            for(int j = M - 1; j >= 0; j--) {
                if(vertical == 0) {
                    break;
                }
                if(ans[i][j] == '#') {
                    bool cond1 = true;
                    bool cond2 = true;

                    if(j + 1 < M && ans[i][j + 1] == c[0]) {
                        cond1 = false;
                    }
                    if(i + 1 < N && ans[i + 1][j] == c[0]) {
                        cond2 = false;
                    }

                    debug() << imie(i) imie(j) imie(cond1) imie(cond2);

                    if(cond1 && cond2) {
                        ans[i][j] = c[0];
                        ans[i - 1][j] = c[0];
                        ans[i][j - 1] = c[1];
                        ans[i - 1][j - 1] = c[1];
                    } else {
                        ans[i][j] = c[1];
                        ans[i - 1][j] = c[1];
                        ans[i][j - 1] = c[0];
                        ans[i - 1][j - 1] = c[0];
                    }
                }
            }
        }

        for(auto u: ans) {
            debug() << imie(u);
        }
        for(auto u: ans) {
            for(auto v: u) {
                cout << v;
            }
            cout << '\n';
        }
    } else {
        cout << "NO\n";
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