#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void run_cases() {
    int k, m, n;
    cin >> k >> n >> m;
    vector<int> actions;

    vector<int> a(n), b(m);
    for(auto &u: a)
        cin >> u;
    for(auto &u: b) {
        cin >> u;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(int i = 0; i < n + m; i++) {
        if(!a.empty() && a.back() == 0) {
            actions.push_back(a.back());
            a.pop_back();
            k++;
        }
        else if(!b.empty() && b.back() == 0) {
            actions.push_back(b.back());
            b.pop_back();
            k++;
        }
        else if(!a.empty() && a.back() <= k) {
            actions.push_back(a.back());
            a.pop_back();
        } 
        else if(!b.empty() && b.back() <= k) {
            actions.push_back(b.back());
            b.pop_back();
        } 
        else {
            break;
        }
    }

    if(actions.size() != n + m) {
        actions = {-1};
    }
    output_vector(actions);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}