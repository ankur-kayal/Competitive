#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second
 
 
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif
   
    int n,m;
    cin >> n >> m;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    queue<ll> q1;
    queue<ll> q2;
    for (int i = n-1; i >= 0; i--) q1.push(a[i]);
    ll ans[63000005];
   
    for (int i = 1; i <= 63000000; i++){
        if (q2.empty()){
            if (q1.empty()) break;
            ll x = q1.front();
            q1.pop();
            ans[i] = x;
            q2.push(x/2);
        }
        else if (q1.empty()){
            ll x = q2.front();
            q2.pop();
            ans[i] = x;
            q2.push(x/2);
        }
        else {
            ll x = q1.front();
            ll y = q2.front();
            if (x > y){
                ans[i] = x;
                q2.push(x/2);
                q1.pop();
            }
            else{
                ans[i] = y;
                q2.push(y/2);
                q2.pop();
            }
        }
        cout << i << " " << ans[i] << '\n';
    }
    while (m --){
        int q;
        cin >> q;
        cout << ans[q] << "\n";
    }
}