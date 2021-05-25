#pragma GCC optimize "trapv"
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ld long double
// #define mp make_pair
#define pii pair<int,int>
// #define mod 998244353
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,a,n) for(int i=a;i<n;i++)
#define all(v) v.begin(),v.end()
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.push_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}
#define EVARS(args...) {_evars_begin(LINE_); __evars(split(#args, ',').begin(), args);}
inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cerr << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cerr << val; }
inline void __evars(vector<string>::iterator it) { cerr << endl; }
template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    __evars_out_var(a);
    cerr << "; ";
    __evars(++it, args...);
}
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<typename T> istream& operator >>(istream &in,vector<T> &v){
    for(auto &x:v) in>>x; return in;
}
template<typename T> ostream& operator <<(ostream &out,vector<T> &v){
    for(auto &x:v) out<<x<<' '; return out;
}
template<typename T1,typename T2> istream& operator >>(istream &in,pair<T1,T2> &p){
    in>>p.first>>p.second; return in;
}
template<typename T1,typename T2> ostream& operator <<(ostream &out,pair<T1,T2> &p){
    out<<p.first<<' '<<p.second; return out;
}
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;
template<class T>using uset=unordered_set<T,custom_hash>;
int32_t main()
{
    fio;
    clock_t clk = clock();
    int t = 1;
    cin >> t;
    auto isPrime = [&] (ll n)
    {
        for(ll i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            return false;
        }
        return true;
    };
    rep(tc, t)
    {
        // cout << "Case #" << tc + 1 << ": ";
        ll n;
        cin >> n;
        vll a(n);
        cin >> a;
        vector<vector<ll>> ops;
        for(ll i = 1; i < n; i++)
        {
            if(__gcd(a[i - 1], a[i]) == 1)
            continue;
            ll mn = min(a[i - 1], a[i]), ind = 0;
            if(mn == a[i - 1])
            {
                ind = i - 1;
            }
            else
            ind = i;
            for(ll j = mn + 1;; j++)
            {
                if(isPrime(j))
                {
                    vll op = {i, i + 1};
                    if(ind == i - 1)
                    {
                        op.push_back(a[i - 1]);
                        op.push_back(j);
                        a[i] = j;
                    }
                    else
                    {
                        op.push_back(j);
                        op.push_back(a[i]);
                        a[i - 1] = j;
                    }
                    ops.push_back(op);
                    break;
                }
            }
        }
        for(int i = 0; i < n - 1; i++)
        {
            assert(__gcd(a[i], a[i + 1]) == 1);
        }
        assert((ll)ops.size() <= n);
        cout << (ll)ops.size() << endl;
        for(auto x: ops)
        {
            output_vector(x);
        }
    }  
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';    
}