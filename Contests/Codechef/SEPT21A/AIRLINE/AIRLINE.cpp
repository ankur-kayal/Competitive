#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    vector<int> bags = {A, B, C};
    vector<int> id = {0, 1, 2};

    do {
        if(bags[id[0]] + bags[id[1]] <= D && bags[id[2]] <= E) {
            cout << "YES\n";
            return;
        }
    } while(next_permutation(id.begin(), id.end()));

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}