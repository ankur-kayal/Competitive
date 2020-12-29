#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    string s;
    cin >> s;
    int l = s.length();
    int ans = 0;
    int c = 0;
    for(int i=0;i<l;i++) {
        c++;
        int rem = (l- 2 * c) / 2;
        if(rem == 0) {
        	break;
        }
        if(s.substr(0,c) == s.substr(0+c,c) and s.substr(2*c,rem) == s.substr(2*c+rem,rem)) {
            ans++;
        }
    }
    cout << ans << '\n';
    
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif
	int t;
	cin >> t;
	while(t--) solve();
}


