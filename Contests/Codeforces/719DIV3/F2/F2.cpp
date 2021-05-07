#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int val;
    cin >> val;
    return val;
}


void run_cases() {
    map<pair<int,int>, int> ranges;
    int n, t;
    cin >> n >> t;

    while(t--) {
        int k;
        cin >> k;
        vector<pair<int,int>> range_stack;
        int r = n;
        int l = 0;
        while(r > l + 1) {
            int m = (r + l) / 2;
            if(!ranges.count(make_pair(l + 1, m))) {
                ranges[{l + 1, m}] = query(l + 1, m);
            }
            int val = ranges[{l + 1, m}];
            int zeros = m - l - val;
            if(k <= zeros) {
                range_stack.push_back({l + 1, m});
                r = m;
            } else {
                k -= zeros;
                l = m;
            }
        }
        cout << "! " << r << endl;
        while(!range_stack.empty()) {
            ranges[range_stack.back()]++;
            range_stack.pop_back();
        }
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