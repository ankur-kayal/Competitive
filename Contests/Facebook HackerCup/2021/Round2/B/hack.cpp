#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define ll long long int
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define nl '\n'
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
const int N=1e6+10;
vl adj[N];
ll vis[N],a[N],val[N],sub[N],ans=0;
set<ll> se;
map<ll,ll> first;
map<ll,vl> mapp;
void dfs(int node){    
    ll temp=0;
    vis[node]=1;
    if(first[a[node]]==0){
        first[a[node]]++;
        val[node]=mapp[a[node]].size()-1;
    }
    else{
        val[node]=-1;
    }
    
    for(int child : adj[node]){
        if(vis[child]==0){
            dfs(child);
            temp+=sub[child];
            
        }
        
    }
    sub[node]=temp+val[node];
    // deb(node);
    // deb2(val[node],sub[node]);
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll node,ans=0;
    fo2(i,1,n){
        vis[i]=0,val[i]=0,sub[i]=0;
        adj[i].clear();
        mapp[i].clear();
    }
    se.clear(),first.clear();
    fo(i,n-1){
        int u,v;
        cin>>u>>v;
        // deb2(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fo2(i,1,n){
        if(adj[i].size()==1){
            node=i;
        }
        cin>>a[i];
        se.insert(a[i]);
        mapp[a[i]].pb(i);
    }
    ans=0;
    // deb(node);
    dfs(node);
   
    fo2(i,1,n){
        if(i==node){
            continue;
        }
        if(sub[i]==0){
            ans++;
        }
    }
    
    // deb(ans);
    cout<<ans<<nl;
}
 
int main(){
    freopen("b_final_input.txt", "r", stdin);
    freopen("b_final_output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1,i;
    cin>>t;
    fo2(i,1,t){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    
}
 