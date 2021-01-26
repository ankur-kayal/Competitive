#include <bits/stdc++.h>
using namespace std;

void run_cases() {
    string total;
    cin >> total;
    string said;
    cin >> said;
    int count = 0;
    int index = 0;
    while(index < int(said.size())) {
        count++;
        for(int i=0;i<26;i++) {
            if(total[i] == said[index]) {
                index++;
            }
            if(index == int(said.size())) {
                break;
            }
        }
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