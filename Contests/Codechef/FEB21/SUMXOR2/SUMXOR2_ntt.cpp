#pragma GCC optimization ("O3")
#pragma GCC optimize("O3","unroll-loops")
// #pragma GCC optimize "trapv"
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC target("avx2")
#include<bits/stdc++.h>
#define fast_az_fuk ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
#define ull unsigned ll
#define ld long double 
#define pb push_back 
#define int ll
#define pf push_front
#define dll deque<ll> 
#define vll vector<ll>
#define vvll vector<vll> 
#define pll pair<ll,ll> 
#define vpll vector<pll>
#define dpll deque<pll>
#define mapll map<ll,ll>
#define endl "\n" 
#define all(v) v.begin(),v.end() 
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const ll N = 2e5;
const int  p = 998244353;
const int mod = 998244353;
const int root = 31;
const int root_1 = 128805723;
const int root_pw = (1LL<<23);
const int worstN=524288;
vll fact(N+1,1);
vll inFact(N+1,1);
vll inVal(worstN+1,1);
vvll WLEN(worstN+1,vll(2));


// this NTT template is derived from CP - Algorithms
// Link : https://cp-algorithms.com/algebra/fft.html

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = WLEN[len][invert];

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (a[i+j+len/2] * w)%mod;
                a[i+j] = (u+v)%mod;
                a[i+j+len/2] = (u-v+mod)%mod;
                w = (w * wlen)%mod;
            }
        }
    }

    if (invert) {
        int n_1 = inVal[n];
        for (auto & x : a)
            x = (x * n_1)%mod;
    }
}
void multiply(vector<int> & fa, vector<int> & fb,vll &result) {
    int n = 1;
    while (n < fa.size() + fb.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = (fb[i]*fa[i])%p;
    fft(fa, true);

    result.resize(n);
    for (int i = 0; i < n; i++)
        result[i] = fa[i];
}
int32_t main()
{
    clock_t clk = clock();
    fast_az_fuk
    ll n,q; cin>>n;
    for(ll len=2;len<=worstN;len<<=1){
        int invert=0;
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (wlen * wlen)%mod;
        WLEN[len][invert]=wlen;
        invert=1;
        wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (wlen * wlen)%mod;
        WLEN[len][invert]=wlen;
    }

    auto power = [&] (ll x,ull y)
    {
        ull res=1;
        while(y)
        {
            if(y&1) res=(res*x)%p;
            x=(x*x)%p; y>>=1;
        }
        return res;
    };
    for(ll i=1;i<=N;i++) fact[i] = ( fact[i-1] * i ) % mod;
    for(ll i=1;i<=N;i++) inFact[i] = power(fact[i],p-2)%p;
    for(ll i=1;i<=worstN;i++) inVal[i] = power(i,p-2);
    // exit(0);
    auto nCr = [&] (ll n,ll r){
        if(r>n) return 0LL;
        else if(r<0) return 0LL;
        ll answer=fact[n];
        answer=(answer*inFact[n-r])%p; answer=(answer*inFact[r])%p;
        return answer;
    };
    vll hash(30,0);
    for(ll i=1;i<=n;i++){
        ll x; cin>>x;
        assert(x < (1 << 30));
        for(ll j=0;j<30;j++){
            if(x&(1LL<<j)) hash[j]++;
        }
    }
    vvll ans(n+1,vll(30,0));
    for(ll b=0;b<30;b++){
        if(hash[b]==0) continue;
        ll h = hash[b];
        vll v1(h+1); v1[0]=0; for(ll i=1;i<=h;i++) { if(i%2==0) v1[i]=0; else v1[i]=nCr(h,i);}
        ll temp = nCr(n-h,0);
        vll v2(n+1);
        v2[0]=temp;
        for(ll i=1;i<=n;i++){
            temp = (temp + nCr(n-h,i))%p;
            v2[i]=temp;
        }
        vll result;
        multiply(v1,v2,result);
        // for(ll x:result) cerr<<x<<" "; cerr<<endl;
        for(ll x:v1) cerr<<x<<" "; cerr<<endl;
        for(ll x:v2) cerr<<x<<" "; cerr<<endl;
        // cerr<<endl;
        for(ll i=1;i<=n;i++) ans[i][b] = (result[i]*(1LL<<b))%p;
    }
    cin>>q;
    // q=n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<30;j++) ans[i][j]=(ans[i][j-1]+ans[i][j])%p;
    }
    while(q--){
        ll m; cin>>m;
        cout<<ans[m][29]<<endl;
    }
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}