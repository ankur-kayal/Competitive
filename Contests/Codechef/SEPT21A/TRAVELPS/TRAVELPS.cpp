#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t N, A, B;
    cin >> N >> A >> B;

    string S;
    cin >> S;

    cout << (count(S.begin(), S.end(), '0') * A + count(S.begin(), S.end(), '1') * B) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}