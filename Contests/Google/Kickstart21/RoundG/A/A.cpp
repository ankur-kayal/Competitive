#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t N, D, C, M;
    cin >> N >> D >> C >> M;

    string S;
    cin >> S;

    int dogs = count(S.begin(), S.end(), 'D');

    for(auto u: S) {
        if(u == 'D') {
            if(D == 0) {
                break;
            } else {
                D--;
                dogs--;
                C += M;
            }
        } else {
            if(C == 0) {
                break;
            }
            C--;
        }
    }

    cout << (dogs == 0 ? "YES" : "NO") << '\n';
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