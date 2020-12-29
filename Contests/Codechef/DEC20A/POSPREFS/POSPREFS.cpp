#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int a[n + 1];
        for(int i=1;i<=n;i++) {
            a[i] = -i;
        }
        int odd = 1;
        int even = (n & 1 ? n - 1 : n);
        for(int i=0;i<k;i++) {

            if(odd <= n) {
                a[odd] *= -1;
                odd += 2;
            }
            else {
                a[even] *= -1;
                even -= 2;
            }
        }
        for(int i=1;i<=n;i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
}