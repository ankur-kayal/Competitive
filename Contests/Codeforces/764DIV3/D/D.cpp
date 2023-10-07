#include <algorithm>
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
    int N, K;
    cin >> N >> K;


    string S;
    cin >> S;

    if(2 * K > N) {
        cout << 1 << '\n';
        return;
    }
    vector<int> cnt(26);
    for(auto &u: S)
        cnt[u - 'a']++;

    multiset<int> buckets;
    for(int i = 0; i < K; i++) {
        buckets.insert(0);
    }
    int index = 0;
    for(int i = 0; i < 26; i++) {
        while(cnt[i] >= 2) {
            int mine = *buckets.begin();
            buckets.erase(buckets.begin());
            mine += 2;
            cnt[i] -= 2;
            buckets.insert(mine);
        }
    }


    for(int i = 0; i < 26; i++) {
        if(cnt[i] == 1) {
            int mine = *buckets.begin();
            if(mine & 1) {
                break;
            }
            mine++;
            buckets.erase(buckets.begin());
            buckets.insert(mine);
        }
    }
    

    vector<int> lengths;
    for(auto &u: buckets) {
        lengths.push_back(u);
    }

    int l = 0, r = K - 1;

    while(r > l) {
        while(l < N && lengths[l] % 2 == 1) {
            l++;
        }
        while(r >= 0 && lengths[r] % 2 == 1) {
            r--;
        }
        if(l < r) {
            if(lengths[l] < lengths[r]) {
                lengths[r]--;
                lengths[l]++;
            }
            r--;
            l++;
        }

        // debug() << imie(r) imie(l);
    }

    cout << *min_element(lengths.begin(), lengths.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}