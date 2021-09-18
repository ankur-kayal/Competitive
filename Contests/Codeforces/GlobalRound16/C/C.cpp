#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;
    vector<string> bi(2);
    cin >> bi[0] >> bi[1];

    vector<bool> used_cols(n);

    int mex = 0;

    for(int i = 0; i < n; i++) {
        set<int> uni;
        for(int j = 0; j < 2; j++) {
            uni.insert(bi[j][i]);
        }

        if(uni.size() == 2) {
            mex += 2;
            used_cols[i] = true;
        }
    }

    for(int col = 0; col < n; col++) {
        if(!used_cols[col]) {
            if(bi[0][col] == '1') {
                if(col + 1 < n && !used_cols[col + 1] && bi[0][col + 1] == '0') {
                    mex += 2;
                    used_cols[col] = true;
                    used_cols[col + 1] = true;
                }
            } else {
                if(col + 1 < n && !used_cols[col + 1] && bi[0][col + 1] == '1') {
                    mex += 2;
                    used_cols[col] = true;
                    used_cols[col + 1] = true;
                } else {
                    mex++;
                }
            }
        } 
    }   

    cout << mex << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}