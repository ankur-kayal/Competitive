#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int query(int t, int i, int j, int x) {
    cout << "? " << t << " " << i << " " << j << " " << x << '\n' << flush;
    int val;
    cin >> val;
    if(val == -1) {
        exit(0);
    }
    return val;
}

void output(vector<int> a) {
    cout << "! ";
    for(auto u: a) {
        cout << u << " ";
    }
    cout << '\n' << flush;
    
}

// t = 1, x = n - 1, return the maximum of the two elements
// t = 2, x = 1, returns the minimum of the two elements
void run_cases() {
    int n;
    cin >> n;
    vector<int> a(n, -1);
    int pos = -1;
    for(int i=0;i+1<n;i+=2) {
        int max_val = query(1, i + 1, i + 2, n - 1);
        if(max_val == n) {
            a[i + 1] = n;
            pos = i + 1;
            break;
        } else if(max_val == n - 1) {
            int max_val2 = query(1, i + 2, i + 1, n - 1);
            if(max_val2 == n) {
                a[i] = n;
                pos = i;
                break;
            }
        }
    }
    if(pos == -1) {
        pos = n - 1;
        a[pos] = n;
    }

    for(int i=0;i<n;i++) {
        if(a[i] == -1) {
            a[i] = query(2, i + 1, pos + 1, 1);
        }
    }
    output(a);

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}