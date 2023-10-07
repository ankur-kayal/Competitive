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



void run_cases() {

    vector<int> values;

    for(int64_t N = 1; N <= 100; N++) {
        vector<vector<int>> correct(2 * N + 1, vector<int>(2 * N + 1));
        vector<vector<int>> wrong(2 * N + 1, vector<int>(2 * N + 1));

        auto set_pixel_to_black_correct = [&](int64_t x, int64_t y) {
            correct[x + N][y + N] = 1;
        };

        function<void(int64_t)> draw_circle_filled = [&](int64_t R) {
            for(int64_t x = -R; x <= R; x++) {
                for(int64_t y = -R; y <= R; y++) {
                    if(round(sqrtl(x * x + y * y)) <= R ) {
                        set_pixel_to_black_correct(x, y);
                    }
                }
            }
        };

        auto set_pixel_to_black_wrong = [&](int x, int y) {
            wrong[x + N][y + N] = 1;
        };

        function<void(int)> draw_circle_perimeter = [&](int R) {
            for(int64_t x = -R; x <= R; x++) {
                int64_t y = round(sqrtl(R * R - x * x));
                set_pixel_to_black_wrong(x, y);
                set_pixel_to_black_wrong(x, -y); 
                set_pixel_to_black_wrong(y, x);
                set_pixel_to_black_wrong(-y, x);
            }
        };

        function<void(int)> draw_circle_filled_wrong = [&](int R) {
            for(int r = 0; r <= R; r++) {
                draw_circle_perimeter(r);
            }
        };

        draw_circle_filled(N);

        draw_circle_filled_wrong(N);

        int answer = 0;

        for(int i = 0; i < 2 * N + 1; i++) {
            for(int j = 0; j < 2 * N + 1; j++) {
                if(correct[i][j] != wrong[i][j]) {
                    answer++;
                }
            }
        }
        values.push_back(answer);

        cout << answer << '\n';
    }

    vector<int> differences;

    for(int i = 1; i < 100; i++) {
        differences.push_back(values[i] - values[i - 1]);
    }

    debug() << imie(differences);

    
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests; test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}