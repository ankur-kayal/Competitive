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

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);

    for(auto &u: A)
        cin >> u;

    A.push_back(0);

    vector<int> ans = {0, 0, 0};

    vector<pair<int,int>> elements;
    int minus = 0, two = 0;


    for(int i = 0; i <= N; i++) {
        if(A[i] != 0) {
            elements.emplace_back(A[i], i);
            if(abs(A[i]) == 2) {
                two++;
            }
            if(A[i] < 0) {
                minus++;
            }
        } else if(!elements.empty()) {

            debug() << imie(elements);
            int ttwo = two;
            int front = elements.front().second;
            int back = N - elements.back().second - 1;
            if(minus % 2 != 0) {
                for(auto [value, index] : elements) {
                    if(abs(value) == 2) {
                        ttwo--;
                    }
                    if(value < 0) {
                        front = index + 1;
                        back = N - elements.back().second - 1;
                        if(front + back <= N) {
                            ans = max(ans, {ttwo, front, back});
                        }
                        debug() << imie(ttwo) imie(front) imie(back);
                        break;
                    }
                }

                reverse(elements.begin(), elements.end());

                ttwo = two;

                for(auto [value, index] : elements) {
                    if(abs(value) == 2) {
                        ttwo--;
                    }
                    if(value < 0) {
                        front = elements.back().second;
                        back = N - index;
                        if(front + back <= N) {
                            ans = max(ans, {ttwo, front, back});
                        }
                        debug() << imie(ttwo) imie(front) imie(back);
                        break;
                    }
                }

            } else {
                ans = max(ans, {two, front, back});
            }

            two = 0;
            minus = 0;
            elements.clear();
            
        }
    }

    cout << ans[1] << " " << ans[2] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}