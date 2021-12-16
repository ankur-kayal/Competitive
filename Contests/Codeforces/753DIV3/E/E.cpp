#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, M;
    cin >> N >> M;

    string S;
    cin >> S;

    int horizontal = 0, vertical = 0;

    int index = 0;

    while(abs(horizontal) >= 0 && abs(horizontal) <= M && abs(vertical) >= 0 && abs(vertical) <= N) {
        if(S[index] == 'L') {
            horizontal--;
        }
        else if(S[index] == 'R') {
            horizontal++;
        }
        else if(S[index] == 'U') {
            vertical--;
        } else {
            vertical++;
        }
        index++;
    }

    int x = 1, y = 1;

    if(horizontal)


    cout << x << " " << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}