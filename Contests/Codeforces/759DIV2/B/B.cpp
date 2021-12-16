#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    vector<int> st;
    for(auto u: A) {
        while(!st.empty() && st.back() <= u) {
            st.pop_back();
        }
        st.push_back(u);
    }

    cout << st.size() - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}