#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;

    deque<int> ans;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(ans.empty()) {
            ans.push_front(a);
        } else {
            if(a < ans.front()) {
                ans.push_front(a);
            } else {
                ans.push_back(a);
            }
        }
    }

    for(auto u: ans) {
        cout << u << " ";
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}