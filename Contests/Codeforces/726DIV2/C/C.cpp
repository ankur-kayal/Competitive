#include <algorithm>
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
    vector<int64_t> H(N);
    for(auto &u: H)
        cin >> u;

    map<int64_t, int64_t> cnt;
    for(auto u: H) 
        cnt[u]++;


    sort(H.begin(), H.end());
    // check if there exists any element with frequency 2
    vector<int64_t> answer(N);
    for(auto u: H) {
        if(cnt[u] >= 2) {
            cnt[u] -= 2;
            answer[0] = u;
            answer[N - 1] = u;
            int index = 1;
            vector<int64_t> stock;
            debug() << imie(u);
            for(auto ele: H) {
                if(ele >= u && cnt[ele] > 0) {
                    stock.push_back(ele);
                    cnt[ele]--;
                }
            }
            for(auto ele: H) {
                if(ele < u) {
                    stock.push_back(ele);
                }
            }
            for(int ele: stock) {
                answer[index++] = ele;
            }
            output_vector(answer);
            return;
        }
    }

    int64_t first = -1, last = -1, val = 1e18;
    for(int i = 0; i < N - 1; i++) {
        int64_t tmp = H[i+1] - H[i];
        if(tmp < val) {
            val = tmp;
            first = H[i];
            last = H[i + 1];
        }
    }

    answer[0] = first;
    answer[N - 1] = last;
    vector<int64_t> stock;
    int index = 1;
    cnt[first]--;
    cnt[last]--;
    for(auto ele: H) {
        if(ele >= answer[0] && cnt[ele] > 0) {
            stock.push_back(ele);
            cnt[ele]--;
        }
    }
    for(auto ele: H) {
        if(ele < answer[0]) {
            stock.push_back(ele);
        }
    }
    debug() << imie(stock);
    for(int ele: stock) {
        answer[index++] = ele;
    }


    output_vector(answer);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}