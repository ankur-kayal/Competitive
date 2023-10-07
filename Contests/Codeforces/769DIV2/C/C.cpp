#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int a, b;
    cin >> a >> b;

    int moves = 0;

    int cb = b;

    int answer = b - a;

    while(true) {
        if(cb == (a | cb)) {
            answer = min(answer, moves + 1);
            break;
        }
        moves++;
        cb++;
    }

    int ca = a;
    moves = 0;
    while(true) {
        if(a == b) {
            answer = min(answer, moves);
            break;
        }
        if(b == (ca | b)) {
            answer = min(answer, moves + 1);
            break;
        }
        moves++;
        ca++;
    }

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