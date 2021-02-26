/***************************************************

@author: vichitr
Compiled On: 13 Feb 2021

*****************************************************/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5 + 7;
const ll MOD = 1e9 + 7;
const pair<ll, ll> bad = {N, -1};

ll fact[N*2], ifact[N*2];
pair<ll, ll> segment[N];

vector<ll> rows[N];

ll pwr(ll x, ll y)
{
    ll r = 1LL;
    while(y)
    {
        if(y & 1)
            r = (r * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return r;
}

ll inv(ll x)
{
    return pwr(x, MOD - 2ll);
}

ll C(ll n, ll r){
    ll ret = fact[n] * ifact[r] % MOD;
    return ret * ifact[n - r] % MOD;
}


signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(segment, segment + N, bad);

    fact[0] = ifact[0] = 1;
    for (int i = 1; i < 2 * N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        ifact[i] = inv(fact[i]);
    }

    int n, t; cin >> n >> t;
    multiset<ll> curRows;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        segment[x].first = min(segment[x].first, y);
        segment[x].second = max(segment[x].second, y);
        rows[x].push_back(y);
        curRows.insert(y);
    }


    // Find next[i] for all columns i
    int last = N;
    vector<ll> next(N);
    for (int i = N - 1; i >= 0; --i) {
        next[i] = last;
        if (segment[i] != bad)
            last = i;
    }

    // set current segment for first column
    int curColumn = next[0];
    pair<ll, ll> curSegment = segment[curColumn];
    ll minSetSize = 0;
    ll countWays = 1;

    // iterate over columns
    for(int i = curColumn; i < N; i = next[i]){
        // remove current column checkered rows
        for(int j: rows[i]){
            curRows.erase(curRows.find(j));
        }

        // increase count of checkered rows for cur column
        minSetSize += curSegment.second - curSegment.first + 1;

        if(next[i] == N)
            break;

        // find minRow, maxRow
        ll minRow = *curRows.begin();
        ll maxRow = *curRows.rbegin();

        // find L, R for current sugment
        ll L = curSegment.first;
        ll R = curSegment.second;

        // case -1
        if(maxRow < L){
            // update set size
            minSetSize += next[i] - i - 1;
            // update number of ways
            countWays *= C(next[i] - i + L - maxRow, next[i] - i);
            countWays %= MOD;
            // update current segment
            curSegment = {segment[next[i]].first, L};
        }
        // case -2
        else if(minRow > R){
            // update set size
            minSetSize += next[i] - i - 1;
            // update number of ways
            countWays *= C(next[i] - i + minRow - R, next[i] - i);
            countWays %= MOD;
            // update current segment
            curSegment = {R, segment[next[i]].second};
        }
        // case -3
        else {
            // update set size
            minSetSize += (min(R, maxRow) - max(L, minRow) + 1) * (next[i] - i - 1);
            // update current segment
            curSegment = {min(max(L, minRow), segment[next[i]].first), max(min(R, maxRow), segment[next[i]].second)};
        }
    }

    if(t == 0) 
        cout << minSetSize;
    else
        cout << minSetSize << " " << countWays;

    return 0;
}