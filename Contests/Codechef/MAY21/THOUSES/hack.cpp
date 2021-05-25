#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

void input(int *arr, int n){
    for(int i=0; i<n; ++i) cin >> arr[i];
}

void input(vector<int>&arr, int n){
    for(int i=0; i<n; ++i) cin >> arr[i];
}

void print(int *arr, int n){
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << "\n";
}

void print(vector<int>&arr, int n){
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << "\n";
}

vector<vector<ll> >vec;
vector<ll>factor;
vector<ll>ans;

int dfs(ll node, ll par, ll root){
    ll branch;
    if(node == root){
        branch = vec[node].size();
    }
    else{
        branch = vec[node].size() - 1;
    }
    if(branch==0 && node!=root){
        factor[node] = 1;
        return factor[node];
    }
    factor[node] += branch;
    for(auto to : vec[node]){
        if(to == par){
            continue;
        }
        ll f = dfs(to, node, root);
        factor[node] += f;
    }
    return factor[node];
}

void solve(ll node, ll par, ll x){
    ans[node] = x;
    ll fact = 1;
    priority_queue<pair<ll, ll> >pq;
    for(auto to : vec[node]){
        if(to == par){
            continue;
        }
        pq.push({factor[to], to});
    }
    while(!pq.empty()){
        ll to = pq.top().ss;
        pq.pop();
        solve(to, node, x*fact);
        fact += 1;
    }
}

const ll mod = 1e9+7;

int main(){
    FAST;
    int test = 1;
    cin >> test;
    for(int tt=1; tt<=test; ++tt){
        ll n, x;
        cin >> n >> x;
        vec = vector<vector<ll> >(n+1, vector<ll>());
        for(ll i=1; i<n; ++i){
            int u, v;
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        factor = vector<ll>(n+1, 0);
        factor[1] = dfs(1, -1, 1);
        ans = vector<ll>(n+1, 0);
        
        solve(1, -1, 1);
        ll s = 0;
        for(ll i=1; i<=n; ++i){
            s = (s + ans[i]%mod)%mod;
        }
        s = (s * (x % mod)) % mod;
        
        cout << s << "\n";
    }
    return 0;
}