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
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    vector<vector<int>> ans;

    for(int i=0;i<N;i+=2) {
        ans.push_back(vector<int>{1, i + 1, i + 2});
        ans.push_back(vector<int>{2, i + 1, i + 2});
        ans.push_back(vector<int>{1, i + 1, i + 2});
        ans.push_back(vector<int>{2, i + 1, i + 2});
        ans.push_back(vector<int>{1, i + 1, i + 2});
        ans.push_back(vector<int>{2, i + 1, i + 2});

    }

    cout << ans.size() << '\n';

    for(auto u: ans) {
        output_vector(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}