#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

/*
3 2 2 0



4 1 3 2 4
*/


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

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    vector<int> B;

    set<int> total_mex;
    for(int i = 0; i <= N + 1; i++) {
        total_mex.insert(i);
    }
    vector<int> cnt(N + 1);
    for(auto u: A) {
        cnt[u]++;
        if(total_mex.count(u)) {
            total_mex.erase(u);
        }
    }
    int index = 0;
    while(index < N) {
        int end = index;
        int max_mex = *total_mex.begin();
        debug() << imie(max_mex);
        int left = max_mex;
        set<int> contains;
        for(int i = index; i < N; i++) {
            if(A[i] < max_mex) {
                if(!contains.count(A[i])) {
                    left--;
                    contains.insert(A[i]);
                }
            }
            if(left == 0) {
                end = i;
                break;
            }
        }
        B.push_back(max_mex);
        for(int i = index; i <= end; i++) {
            cnt[A[i]]--;
            if(cnt[A[i]] == 0)
                total_mex.insert(A[i]);
        }
        index = end + 1;

        debug() << imie(index) imie(total_mex);

    }

    cout << B.size() << '\n';

    output_vector(B);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}