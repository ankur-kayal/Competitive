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
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    for(int i = 0; i+1 < n; i+=2) {
        swap(a[i], a[i + 1]);
    }

    if(n & 1) {
        swap(a[n - 1], a[n - 2]);
    }

    output_vector(a);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}