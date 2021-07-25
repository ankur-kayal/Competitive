#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s;
    cin >> s;

    int red = 0, green = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        int cnt = min(2, (int)count(s.begin(), s.end(), c));
        int left = cnt / 2;
        int right = cnt - left;
        red += right;
        green += left;
        if(red > green) {
            swap(red, green);
        }
    }
    cout << min(red, green) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}