#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 228;
const pair<int, int> bad = make_pair(-1, N);

pair<int, int> A[N];
vector<int> used_c[N];
int next[N];

const int MOD = 1e9 + 7;

int fact[2 * N];
int _fact[2 * N];

int powm(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return (long long) powm(a, b - 1) * a % MOD;
    int z = powm(a, b / 2);
    return (long long) z * z % MOD;
}

int C(int n, int k) {
    long long res1 = (long long) fact[n] * _fact[k] % MOD;
    return (long long) res1 * _fact[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(A, A + N, bad);

    fact[0] = 1;
    for (int i = 1; i < 2 * N; ++i) {
        fact[i] = (long long) fact[i - 1] * i % MOD;
        _fact[i] = powm(fact[i], MOD - 2);
    }

    int n, type;
    cin >> n >> type;
    multiset<int> now_y;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        A[x].first = max(A[x].first, y);
        A[x].second = min(A[x].second, y);
        used_c[x].push_back(y);
        now_y.insert(y);
    }
    vector<int> next(N);
    int last = N;
    for (int i = N - 1; i >= 0; --i) {
        next[i] = last;
        if (A[i] != bad)
            last = i;
    }
    pair<int, int> now = A[next[0]];
    for (int i : used_c[next[0]])
        now_y.erase(now_y.find(i));
    long long s = now.first - now.second + 1;
    int ans = 1;
    for (int i = next[0]; i < N; i = next[i]) {
        if (next[i] == N)
            break;

        int mx = *now_y.rbegin();
        int mn = *now_y.begin();
        if (mx < now.second) {
            s += (next[i] - i - 1);
            ans = (long long) ans * C(next[i] - i + now.second - mx, next[i] - i) % MOD;
            now = make_pair(now.second, A[next[i]].second);
            s += now.first - now.second + 1;
        } else if (mn > now.first) {
            s += (next[i] - i - 1);
            ans = (long long) ans * C(next[i] - i + mn - now.first, next[i] - i) % MOD;
            now = make_pair(A[next[i]].first, now.first);
            s += now.first - now.second + 1;
        } else {
            now = make_pair(min(now.first, mx), max(now.second, mn));
            s += (long long) (now.first - now.second + 1) * (next[i] - i - 1);
            now.first = max(now.first, A[next[i]].first);
            now.second = min(now.second, A[next[i]].second);
            s += now.first - now.second + 1;
        }
        for (int j : used_c[next[i]])
            now_y.erase(now_y.find(j));
    }
    
    if (type == 0)
        cout << s << '\n';
    else
        cout << s << ' ' << ans << '\n';
}