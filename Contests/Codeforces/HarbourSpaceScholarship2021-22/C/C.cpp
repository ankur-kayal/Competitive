#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s;
    cin >> s;
    int minimum = 10;

    for(int mask = 0; mask < (1 << 10); mask++) {
        string curr = s;
        for(int bit = 0; bit < 10; bit++) {
            if(curr[bit] != '?') continue;
            if(mask & (1 << bit)) {
                curr[bit] = '1';
            } else {
                curr[bit] = '0';
            }
        }

        int score1 = 0, score2 = 0;
        int remaining1 = 5, remaining2 = 5;
        bool first = true;
        for(int i = 0; i < 10; i++) {
            if(first) {
                score1 += (curr[i] == '1');
                remaining1--;
            } else {
                score2 += (curr[i] == '1');
                remaining2--;
            }
            first = !first;

            if(score1 > score2 + remaining2 || score2 > score1 + remaining1) {
                minimum = min(minimum, i + 1);
            }
        }
    } 
    cout << minimum << '\n';
}   

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}