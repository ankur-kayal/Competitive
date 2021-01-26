#include <bits/stdc++.h>
using namespace std;

// USACO 2021 January Contest, Bronze
// Problem 2. Even More Odd Photos

void run_cases() {
    int n;
    cin >> n;
    vector<int> even;
    vector<int> odd;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(x & 1) {
            odd.push_back(x);
        }
        else {
            even.push_back(x);
        }
    }

    int parity = 0;
    int count = 0;
    while(true) {
        if(parity == 0) {
            if(!even.empty()) {
                even.pop_back();
            }
            else if(int(odd.size()) >= 2) {
                odd.pop_back();
                odd.pop_back();
            }
            else goto print;
        }
        else {
            if(!odd.empty()) {
                odd.pop_back();
            }
            else goto print;
        }
        parity ^= 1;
        count++;
    }



    print:
    if(!odd.empty()) {
        assert(int(odd.size()) == 1);
        count--;
    }
    cout << count;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}