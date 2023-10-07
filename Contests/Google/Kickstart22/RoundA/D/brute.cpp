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

void precompute(int N) {
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(pro(i) % sum(i) == 0) {
            cnt++;
            numbers.push_back(i);
        }
    }

    debug() << imie(cnt);
}

void run_cases() {
    int64_t A, B;
    cin >> A >> B;

    int ans = 0;
    for(auto u: numbers) {
        if(A <= u && u <= B) {
            ans++;
        }
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    precompute(1e5 + 10);


    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}