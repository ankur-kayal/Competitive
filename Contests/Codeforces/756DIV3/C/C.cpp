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

bool verify(deque<int> perm, deque<int> result) {
    deque<int> got;

    debug() << imie(perm);

    while(perm.size() > 1) {
        int left_value = perm.front();
        int right_value = perm.back();

        if(left_value < right_value) {
            got.push_front(left_value);
            perm.pop_front();
        } else {
            got.push_back(right_value);
            perm.pop_back();
        }
    }

    deque<int> got2 = got;

    got.push_back(perm.front());
    got2.push_front(perm.front());

    debug() << imie(got) imie(got2);


    return (got == result) || (got2 == result);
}

void run_cases() {
    int N;
    cin >> N;

    deque<int> original(N);

    for(auto &u: original) {
        cin >> u;
    }

    deque<int> copy;

    deque<int> tmp = original;

    while(tmp.size() > 1) {
        int left_value = tmp.front();
        int right_value = tmp.back();

        if(left_value < right_value) {
            copy.push_front(left_value);
            tmp.pop_front();
        } else {
            copy.push_back(right_value);
            tmp.pop_back();
        }
    }

    deque<int> copy2 = copy;

    copy.push_back(tmp.front());
    copy2.push_front(tmp.front());

    if(verify(copy, original)) {
        for(auto u: copy) {
            cout << u << " ";
        }
        cout << '\n';
    } else if(verify(copy2, original)) {
        for(auto u: copy2) {
            cout << u << " ";
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
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