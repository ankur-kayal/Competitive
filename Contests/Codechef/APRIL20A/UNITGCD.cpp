#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
	#endif

    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	if(n == 1) {
    		cout << 1 << '\n' << "1 1" << '\n';
    		continue;
    	}
    	int cnt = n / 2;
    	cout << cnt << '\n';
    	for(int i=1;i<=cnt;i++) {
    		int a = 2 * i;
    		int b = a + 1;
    		int c = (a <= n) + (b <= n);
    		if(i == 1) {
    			cout << min(n,3) << " " << 1 << " ";
    		}
    		else {
    			cout << c << " ";
    		}
    		if(a <= n) {
    			cout << a << " ";
    		}
    		if(b <= n) {
    			cout << b << '\n';
    		}
    	}

    }
}