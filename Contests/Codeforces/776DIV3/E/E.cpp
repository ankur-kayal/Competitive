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
    int N, D;
    cin >> N >> D;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    vector<int> rest(N);
    multiset<int> pq;
    rest[0] = A[0] - 1;
    for(int i = 1; i < N; i++) {
        rest[i] = A[i] - A[i - 1] - 1;
    }

    for(auto u: rest) {
        pq.insert(u);
    }

    int answer = *min_element(rest.begin(), rest.end());

    // take an exam and put it in the last one if possible

    if(A.back() != D) {
        for(int i = 0; i < N - 1; i++) {
            pq.erase(pq.find(rest[i]));
            pq.erase(pq.find(rest[i + 1]));

            int combined = rest[i] + rest[i + 1] + 1;

            pq.insert(combined);

            pq.insert(D - A.back() - 1);

            answer = max(answer, *pq.begin());

            // now revert the changes
            pq.erase(pq.find(combined));
            pq.erase(pq.find(D - A.back() - 1));
            pq.insert(rest[i + 1]);
            pq.insert(rest[i]);
            

        }

        pq.erase(pq.find(rest.back()));
        pq.insert(D - A[N - 2] - 1);
        answer = max(answer, *pq.begin());
        pq.insert(rest.back());
        pq.erase(pq.find(D - A[N - 2] - 1));
    }

    debug() << imie(answer);
    debug() << imie(pq);

    // take an exam out, merge the two and put in the middle of the largest gap available

    for(int i = 0; i < N - 1; i++) {
        pq.erase(pq.find(rest[i]));
        pq.erase(pq.find(rest[i + 1]));

        int combined = rest[i] + rest[i + 1] + 1;

        pq.insert(combined);

        int largestTillNow = *prev(pq.end());
        pq.erase(pq.find(largestTillNow));

        // perform modification
        if(largestTillNow & 1) {
            pq.insert(largestTillNow / 2);
            pq.insert(largestTillNow / 2);
        } else {
            pq.insert(largestTillNow / 2);
            pq.insert(largestTillNow / 2 - 1);
        }

        debug() << imie(pq);

        answer = max(answer, *pq.begin());

        // revert the changes performed
        if(largestTillNow & 1) {
            pq.erase(pq.find(largestTillNow / 2));
            pq.erase(pq.find(largestTillNow / 2));
        } else {
            pq.erase(pq.find(largestTillNow / 2));
            pq.erase(pq.find(largestTillNow / 2 - 1));
        }
        pq.insert(largestTillNow);
        pq.erase(pq.find(combined));
        pq.insert(rest[i + 1]);
        pq.insert(rest[i]);
    }

    // special for the last element

    {
        pq.erase(pq.find(rest.back()));
        // pq.erase(pq.find(rest[i + 1]));

        // int combined = rest[i] + rest[i + 1] + 1;

        // pq.insert(combined);

        int largestTillNow = *prev(pq.end());
        pq.erase(pq.find(largestTillNow));

        // perform modification
        if(largestTillNow & 1) {
            pq.insert(largestTillNow / 2);
            pq.insert(largestTillNow / 2);
        } else {
            pq.insert(largestTillNow / 2);
            pq.insert(largestTillNow / 2 - 1);
        }

        answer = max(answer, *pq.begin());

        // revert the changes performed
        if(largestTillNow & 1) {
            pq.erase(pq.find(largestTillNow / 2));
            pq.erase(pq.find(largestTillNow / 2));
        } else {
            pq.erase(pq.find(largestTillNow / 2));
            pq.erase(pq.find(largestTillNow / 2 - 1));
        }
        pq.insert(largestTillNow);
        // pq.erase(pq.find(combined));
        // pq.insert(rest[i + 1]);
        pq.insert(rest.back());
    }


    debug() << imie(rest);

    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}