#include <bits/stdc++.h>
using namespace std;
#define int long long
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0, cnt0 = 0;
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[n - i - 1]) {
            cnt++;
        }
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            cnt0++;
        }
    }
    //cout << "cnt = " << cnt << ", cnt0 = " << cnt0 << ", s[n / 2] = " << s[n / 2] << "\n";
    if(cnt >= 2) {
        cout << "ALICE\n";
        return;
    }
    if(cnt == 1 && n % 2 == 1 && s[n / 2] == '0' && cnt0 == 2) {
        cout << "DRAW\n";
        return;
    }
    if(cnt == 1) {
        cout << "ALICE\n";
        return;
    }
    if(n % 2 == 1 && s[n / 2] == '0') {
        s[n / 2] = '1';
        cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                cnt++;
            }
        }
        if(cnt == 0) {
            cout << "BOB\n";
        }
        else {
            cout << "ALICE\n";
        }
        return;
    }
    cout << "BOB\n";
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        Solve();
    }
    return 0;
}