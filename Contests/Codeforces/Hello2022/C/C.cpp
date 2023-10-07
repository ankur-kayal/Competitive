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

void process(vector<int> perm) {
    int N = perm.size();
    vector<int> q(N);
    iota(q.begin(), q.end(), 1);

    auto modify = [&]() {
        vector<int> qq(N);
        for(int i = 0; i < N; i++) {
            qq[i] = q[perm[i] - 1];
        }
        q = qq;
    };

    auto  query = [&](int i) {

        int val = q[i - 1];

        modify();

        return val;
        
    };

    auto print = [&](vector<int> p) {
        if(p != perm) {
            debug() << imie(p) imie(perm);
            exit(1);
        }
    };


    vector<int> processed(N + 1);
    vector<int> p(N + 1);

    int rotated = 0;

    // query(1);

    for(int i = 1; i <= N; i++) {
        if(processed[i] == 0) {
            deque<int> loop;
            int index = i;
            while(processed[i] < 2) {
                index = query(i);
                loop.push_back(index);
                processed[index]++;
                // debug() << imie(index) imie(processed);
            }

            for(int j = 0; j < loop.size() - 1; j++) {
                p[loop[j]] = loop[j + 1];
            }

            // debug() << imie(loop) imie(p);
        }
    }

    p.erase(p.begin());
    print(p);

    debug() << imie(perm) << "passed";
}

void simulate() {
    int N;
    cin >> N;

    vector<int> perm(N);
    iota(perm.begin(), perm.end(), 1);

    do {
        process(perm);
    } while(next_permutation(perm.begin(), perm.end()));
}


void run_cases() {
    int N;
    cin >> N;

    // vector<int> perm = {4, 2, 1, 3};
    // vector<int> q = {1, 2, 3, 4};

    // auto modify = [&]() {
    //     vector<int> qq(4);
    //     for(int i = 0; i < 4; i++) {
    //         qq[i] = q[perm[i] - 1];
    //     }
    //     q = qq;
    //     debug() << imie(q);
    // };

    auto  query = [&](int i) {
        cout << "? " << i << endl;
        int qi;
        cin >> qi;
        return qi;
        // debug() << imie(i);

        // int val = q[i - 1];

        // modify();

        // return val;

        
    };

    auto print = [&](vector<int> p) {
        cout << "! ";
        for(auto u: p) {
            cout << u << " ";
        }
        cout << endl;
    };


    vector<int> processed(N + 1);
    vector<int> p(N + 1);

    int rotated = 0;

    // query(1);

    for(int i = 1; i <= N; i++) {
        if(processed[i] == 0) {
            deque<int> loop;
            int index = i;
            while(processed[i] < 2) {
                index = query(i);
                loop.push_back(index);
                processed[index]++;
                debug() << imie(index) imie(processed);
            }

            for(int j = 0; j < loop.size() - 1; j++) {
                p[loop[j]] = loop[j + 1];
            }

            debug() << imie(loop) imie(p);
        }
    }

    p.erase(p.begin());
    print(p);

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
        // simulate();
    }
}

// g++ C.cpp -o C.exe -DLOCAL