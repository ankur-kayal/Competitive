#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

const int64_t INF64 = 1e18;


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

bool valid_range(pair<int64_t, int64_t> pos) {
    return pos.first <= pos.second;
}

void run_cases() {
    int64_t N, M;
    cin >> N >> M;
    set<int64_t> diff;
    set<pair<int64_t, int64_t>> ranges;
    for(int64_t i = 0; i < N; i++) {
        int64_t A, B;
        cin >> A >> B;
        ranges.insert({A, B});
    }
    vector<int64_t> ans;

    for(int i = 0; i < M; i++) {
        int64_t S;
        cin >> S;

        auto it = ranges.lower_bound({S, S});
        auto pos = *it;
        debug() << imie(pos);
        if(pos.first == S) {
            ans.push_back(S);
            pos.first++;
            ranges.erase(it);
            if(valid_range(pos)) {
                ranges.insert(pos);
            }

        } else if(it != ranges.begin()) {
            pair<int64_t, int64_t> left = *prev(it);
            if(left.first <= S && S <= left.second) {
                ans.push_back(S);
                pair<int64_t, int64_t> l = {left.first, S - 1};
                pair<int64_t, int64_t> r = {S + 1, left.second};
                ranges.erase(prev(it));
                if(valid_range(l)) {
                    ranges.insert(l);
                }
                if(valid_range(r)) {
                    ranges.insert(r);
                }
            } else {
                int64_t l = left.second;
                int64_t r = pos.first;
                if(abs(l-S) <= abs(S-r)) {
                    left.second--;
                    ranges.erase(prev(it));
                    if(valid_range(left)) {
                        ranges.insert(left);
                    }
                    ans.push_back(l);
                } else {
                    pos.first++;
                    ranges.erase(it);
                    if(valid_range(pos)) {
                        ranges.insert(pos);
                    }
                    ans.push_back(r);
                }
            }

        } else {
            ans.push_back(pos.first);
            pos.first++;
            ranges.erase(it);
            if(valid_range(pos)) {
                ranges.insert(pos);
            }
        }
    }

    output_vector(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}