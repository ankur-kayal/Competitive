#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;

//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define nl '\n'
#define Stringize( L )     #L 
#define MakeString( M, L ) M(L)
#define $Line MakeString( Stringize, __LINE__ )
#define Reminder __FILE__ "(" $Line ") : Warning: "

//----------------------------------- END DEFINES -------------------------------- 

//-------------------------- CUSTOM UNORDERED MAP HASH ---------------------------

struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(a + FIXED_RANDOM);
    }
    template<class T> size_t operator()(T a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        return splitmix64(x(a) + FIXED_RANDOM);
    }
    template<class T, class H> size_t operator()(pair<T, H> a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        hash<H> y;
        return splitmix64(x(a.first) * 37 + y(a.second) + FIXED_RANDOM);
    }
};
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;

//----------------------- CUSTOM UNORDERED MAP HASH END--------------------------

string magic(string a) {
    string ans = "";
    for(auto u: a) {
        if(u == '5') {
            ans += '2';
        }
        else if(u == '2') {
            ans += '5';
        }
        else {
            ans += u;
        }
    }
    return ans;
}
vector<int> bad = {3,4,6,7,9};
void run_cases() {
    int h,m;
    cin >> h >> m;
    string s;
    cin >> s;

    vector<pair<int,int>> valid;
    for(int i=0;i<h;i++) {
        for(int j=0;j<m;j++) {
            set<int> d;
            string hours = to_string(i);
            string minutes = to_string(j);

            if(hours.length() == 1) {
                hours = '0' + hours;
            }
            if(minutes.length() == 1) {
                minutes = '0' + minutes;
            }
            for(auto u: hours) {
                d.insert(u-'0');
            }
            for(auto u: minutes) {
                d.insert(u - '0');
            }
            bool ok = true;
            for(auto u: bad) {
                if(d.count(u)) {
                    ok = false;
                }
            }
            reverse(all(hours));
            reverse(all(minutes));
            hours = magic(hours);
            minutes = magic(minutes);
            if(stoi(hours) >= m or stoi(minutes) >= h) {
                ok = false;
            }
            if(ok) {
                valid.emplace_back(i, j);
            }
        }
    }
    // debug() << imie(valid);
    string ans = "00:00";
    pair<int,int> time = {stoi(s.substr(0,2)), stoi(s.substr(3))};
    // debug() << imie(time);

    if(lower_bound(all(valid), time) != valid.end()) {
        pair<int,int> temp = *lower_bound(all(valid), time);
        string hours = to_string(temp.first);
        string minutes = to_string(temp.second);
        if(hours.length() == 1) {
            hours = '0' + hours;
        }
        if(minutes.length() == 1) {
            minutes = '0' + minutes;
        }
        ans = hours + ":" + minutes;

    }
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}