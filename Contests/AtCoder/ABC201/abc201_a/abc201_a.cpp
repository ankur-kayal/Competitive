#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    vector<int> a(3);
    for(auto &u: a) 
        cin >> u;
    sort(a.begin(), a.end());
    if(a[1] - a[0] == a[2] - a[1]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}