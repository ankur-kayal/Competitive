#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    if(1 <= N && N <= 125) {
        cout << 4;
    }
    else if(126 <= N && N <= 211) {
        cout << 6;
    } else {
        cout << 8;
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}