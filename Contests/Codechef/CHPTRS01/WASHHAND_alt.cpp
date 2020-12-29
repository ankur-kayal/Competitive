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
    	string p;
    	cin >> p;	
    	int d;
    	cin >> d;
    	vector <int> iso(d);
    	for(int i=0;i<d;i++) {
    		cin >> iso[i];
    	}
    	// 0 means not infected, 1 means infected
        // -5 means can pass, 5 means cannot pass
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(p[i] == '1') {
                ans++;
            }
        }
        vector <int> travel(2*n+1);
        for(int i=2;i<=2*n;i+=2) {
            travel[i] = p[(i-2)/2] - '0';
        }
        for(int i=1;i<2*n;i+=2) {
            travel[i] = -5;
        }
        // for(int i=1;i<=2*n;i++) {
        //     cout << travel[i] << " ";
        // }
        // cout << '\n';
        int ans1 = ans;
        for(int i=0;i<d;i++) {
            int ele = iso[i];
            travel[ele * 2 - 1] = 5;
            for(int j=2; j<=2*n; j++) {
                //spread left if possible
                if(travel[j-1] == -5 and j != 2 and travel[j-2] == 0 and travel[j] == 1) {
                    travel[j-2] = 1;
                    ans++;
                }
                //spread right if possible
                if(j != 2*n and travel[j+1] == -5 and travel[j+2] == 0 and travel[j] == 1) {
                    travel[j+2] = 1;
                    ans++;
                    j+=2;
                }
            }
            // for(int i=1;i<=2*n;i++) {
            //     cout << travel[i] << " ";
            // }
            // cout << '\n';
            if(ans1 == ans) {
                break;
            }
            else {
                ans1 = ans;
            }
        }
    	cout <<  ans << '\n';
    }

}