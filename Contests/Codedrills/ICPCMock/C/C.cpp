#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N,X,Y,K;
    cin >> N >> X >> Y >> K;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    int extra = 0;
    map<int,int> cnt;
    int bw = Y - X + 1;
    for(auto u: A) {
        if(cnt[u] != 0) {
            extra++;
        } 
        if(cnt[u] == 0 && X <= u && u <= Y) {
            bw--;
        }

        cnt[u] = 1;
    }

    int ans = N - extra + min({K, extra, bw});

    cout << ans << '\n';


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}