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
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        vector <int> index[26];
        vector <int> ori[26];
        bool ok = 1;
        for(int i=0;i<n;i++) {
            int c1 = a[i] - 'a';
            int c2 = b[i] - 'a';
            if(c1 >= c2) {
                if(c1 > c2) {
                    index[c2].pb(i);
                }
                if(c1 == c2) {
                    ori[c2].pb(i);
                }
                else {
                    ori[c1].pb(i);
                }
            }
            else {
                ok = 0;
                break;
            }
        }
        int c = 0;
        if(ok) {
            for(int i=25;i>=0;i--) {
                if(index[i].size() > 0) {
                    if(ori[i].size() > 0) {
                        index[i].pb(ori[i][0]);
                    }
                    else {
                        ok = 0;
                        break;
                    }
                    c++;
                }
            }
        }
        if(ok) {
            cout << c << '\n';
            for(int i=25;i>=0;i--) {
                if(index[i].size() > 0) {
                    cout << index[i].size() << " ";
                    for(auto u: index[i]) {
                        cout << u << " ";
                    }
                    cout << '\n';
                }
            }
        }
        else {
            cout << -1 << '\n';
        }
    }
}