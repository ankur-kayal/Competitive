#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    for(int rot = 1; rot <= 100; rot++) {
        string ns = s;
        for(int i = 0; i < N; i++) {
            if(s[i] == 'B') {
                if(i - 1 >= 0 && ns[i - 1] == '?') {
                    ns[i - 1] = 'R';
                }
                if(i + 1 < N && ns[i + 1] == '?') {
                    ns[i + 1] = 'R';
                }
            } else if(s[i] == 'R') {
                if(i - 1 >= 0 && ns[i - 1] == '?') {
                    ns[i - 1] = 'B';
                }
                if(i + 1 < N && ns[i + 1] == '?') {
                    ns[i + 1] = 'B';
                }
            }
        }
        s = ns;
    }

    if(count(s.begin(), s.end(), '?') > 0) {
        for(int i = 0; i < N; i++) {
            s[i] = (i & 1 ? 'R' : 'B');
        }
    }

    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}