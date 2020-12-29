#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

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
    	int n,k;
    	cin >> n >> k;
        // assert(k > 1);
    	int f[n+1];
    	map<int,int> cnt;
    	for(int i=0;i<n;i++) {
    		cin >> f[i];
    	}
    	vector <map<int,int>> tables;
        cnt[f[0]]++;
        tables.pb(cnt);
        for(int i=1;i<n;i++) {
            int currentAnswer = k;
            for(auto u: cnt) {
                if(u.ss > 1) {
                    currentAnswer += u.ss;
                } 
            }
            int val;
            if(cnt[f[i]] == 0) {
                val = 0;
            }
            else if(cnt[f[i]] == 1) {
                val = 2;
            }
            else {
                val = 1;
            }
            if(currentAnswer + val <= currentAnswer + k) {
                cnt[f[i]]++;
                tables.pop_back();
                tables.pb(cnt);
            }
            else {
                cnt.clear();
                cnt[f[i]]++;
                tables.pb(cnt);
            }
        }
        // for(int i=0;i<tables.size();i++) {
        //     cout << "table " << i + 1 << '\n';
        //     for(auto v : tables[i]) {
        //         cout << v.ff << " " << v.ss << '\n';
        //     }
        // }   
        ll ans1 = 0;
        for(auto u: tables) {
            ans1+=k;
            for(auto v : u) {
                if(v.ss > 1) {
                    ans1 += v.ss;
                }
            }
        }
    	cout << ans1 << '\n';
    }
}