#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &u: a) {
        cin >> u;
    }

    int ans = 0;

    for(int i=0;i<n;i++) {
        int c = 0;
        map<int,int> cnt;
        int sum = 0;
        for(int j=i;j<n;j++) {
            c++;
            cnt[a[j]]++;
            sum += a[j];
            if(sum % c == 0) {
                if(cnt[sum/c] != 0) {
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
}