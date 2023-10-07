#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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



void solve(vector<int> A) {
    int N = A.size();

    auto ask = [&](int a, int b, int c) {

        if(a == 0 || b == 0 || c == 0 || a == b || b == c || c == a) {
            debug() << imie(A);
            exit(0);
        }
        int s = A[a - 1] + A[b - 1] + A[c - 1];
        if(s < 0) {
            return 0;
        } else {
            return 1;
        }
    };

    vector<int> original;
    for(int i = 1; i <= N; i++) {
        if(A[i - 1] == -1) {
            original.push_back(i);
        }
    }

    vector<int> parity(N + 1, 0);
    int crewmate_position = 0;
    int imposter_position = 0;

    vector<int> zero = {};
    vector<int> one = {};

    vector<int> questions(N - 1);

    for(int i = 1; i <= N - 2; i++) {
        questions[i] = ask(i, i + 1, i + 2);
    }

    bool found = false;

    for(int i = 1; i <= N; i++) {
        if(questions[i] == 0 && questions[i + 1] == 1 && questions[i + 2] == 1) { // 011
            parity[i + 3] = 1;
            crewmate_position = i + 3;
            imposter_position = i;
            parity[i] = -1;
            found = true;
            break;
        }
        if(questions[i] == 1 && questions[i + 1] == 0 && questions[i + 2] == 1) { // 101
            crewmate_position = i;
            imposter_position = i + 1;
            parity[i] = 1;
            parity[i + 1] = -1;
            found = true;
            break;
        }
        if(questions[i] == 1 && questions[i + 1] == 1 && questions[i + 2] == 0) { // 110
            crewmate_position = i + 1;
            parity[i + 1] = 1;
            imposter_position = i + 4;
            parity[i + 4] = -1;
            break;
        }
        if(questions[i] == 0 && questions[i + 1] == 0 && questions[i + 2] == 1) { // 001
            crewmate_position = i + 4;
            imposter_position = i + 1;
            parity[crewmate_position] = 1;
            parity[imposter_position] = -1;
            break;
        }

        if(questions[i] == 1 && questions[i + 1] == 0 && questions[i + 2] == 0) { // 100
            crewmate_position = i;
            imposter_position = i + 3;
            parity[crewmate_position] = 1;
            parity[imposter_position] = -1;
            break;
        }
    }

    debug() << imie(crewmate_position) imie(imposter_position);


    for(int i = 1; i <= N; i++) {
        if(parity[i] == 0) {
            int res = ask(i, crewmate_position, imposter_position); 
            if(res == 0) {
                parity[i] = -1;
            } else {
                parity[i] = 1;
            }
        }
    }

    vector<int> imposter_positions;
    for(int i = 1; i <= N; i++) {
        if(parity[i] == -1) {
            imposter_positions.push_back(i);
        }
    }

    sort(imposter_positions.begin(), imposter_positions.end());

    if(imposter_positions != original) {
        debug() << imie(A);
        exit(0);
    }
}

void simulate() {
    vector<int> A = {-1,-1,-1,-1,-1,1,1,1,1};

    do {
        solve(A);
    } while(next_permutation(A.begin(), A.end()));
}

int ask(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    int response;
    cin >> response;
    if(response == -1) {
        exit(0);
    }
    return response;
}

void print(vector<int> imposter_positions) {
    cout << "! ";
    cout << imposter_positions.size() << " ";
    for(auto u: imposter_positions) {
        cout << u << " ";
    }
    cout << endl;
}

void run_cases() {
    int N;
    cin >> N;

    vector<int> parity(N + 1, 0);
    int crewmate_position = 0;
    int imposter_position = 0;

    vector<int> zero = {};
    vector<int> one = {};

    vector<int> questions(N - 1);

    for(int i = 1; i <= N - 2; i++) {
        questions[i] = ask(i, i + 1, i + 2);
    }

    bool found = false;

    for(int i = 1; i <= N; i++) {
        if(questions[i] == 0 && questions[i + 1] == 1 && questions[i + 2] == 1) { // 011
            parity[i + 3] = 1;
            crewmate_position = i + 3;
            imposter_position = i;
            parity[i] = -1;
            found = true;
            break;
        }
        if(questions[i] == 1 && questions[i + 1] == 0 && questions[i + 2] == 1) { // 101
            crewmate_position = i;
            imposter_position = i + 1;
            parity[i] = 1;
            parity[i + 1] = -1;
            found = true;
            break;
        }
        if(questions[i] == 1 && questions[i + 1] == 1 && questions[i + 2] == 0) { // 110
            crewmate_position = i + 1;
            parity[i + 1] = 1;
            imposter_position = i + 4;
            parity[i + 4] = -1;
            break;
        }
        if(questions[i] == 0 && questions[i + 1] == 0 && questions[i + 2] == 1) { // 001
            crewmate_position = i + 4;
            imposter_position = i + 1;
            parity[crewmate_position] = 1;
            parity[imposter_position] = -1;
            break;
        }

        if(questions[i] == 1 && questions[i + 1] == 0 && questions[i + 2] == 0) { // 100
            crewmate_position = i;
            imposter_position = i + 3;
            parity[crewmate_position] = 1;
            parity[imposter_position] = -1;
            break;
        }
    }

    debug() << imie(crewmate_position) imie(imposter_position);


    for(int i = 1; i <= N; i++) {
        if(parity[i] == 0) {
            int res = ask(i, crewmate_position, imposter_position); 
            if(res == 0) {
                parity[i] = -1;
            } else {
                parity[i] = 1;
            }
        }
    }

    vector<int> imposter_positions;
    for(int i = 1; i <= N; i++) {
        if(parity[i] == -1) {
            imposter_positions.push_back(i);
        }
    }

    print(imposter_positions);
}   

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(nullptr);
    // simulate();
    // return 0;
    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}