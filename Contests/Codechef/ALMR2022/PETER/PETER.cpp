#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int S;
    cin >> S;

    int length = (S / 26) + ((S % 26) != 0);
    if(S & 1) {
        if(length % 2 == 0) {
            length++;
        }
    }

    cout << length << '\n';
}       

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}