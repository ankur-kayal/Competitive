#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void solve() {
    int n;
    cin >> n;
    int arr[n];
    set <int> unique;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        unique.insert(arr[i]);
    }
    vector <int> count[1001];
    set<int> a;
    for(int i=0;i<n;i++) {
        count[arr[i]].pb(i);
    }
    bool exists = true;
    for(int i=1;i<=1000;i++) {
        exists = true;
        if(count[i].size() > 0) {
            int prev = -1;
            int c = 0;
            for(auto u: count[i]) {
                // cout << u << " " << prev << '\n';
                c++;
                if(prev == -1) {
                    prev = u;
                }
                else {
                    if(u - prev != 1) {
                        exists = false;
                        break;
                    }
                    prev = u;
                }
            }
            a.insert(c);
            // cout << i << " jtjb" << '\n';
        }
        if(exists == false) {
            break;
        }
        
    }
    // for(auto u: unique) {
    //     cout << u << ' ';
    // }
    // cout << '\n';
    // for(auto u: a) {
    //     cout << u << ' ';
    // }
    // cout << '\n';
    if(exists and a.size() == unique.size()) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
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
