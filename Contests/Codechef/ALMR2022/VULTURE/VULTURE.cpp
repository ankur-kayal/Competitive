#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

vector<int64_t> spidey;

void generate(string s, int n) {
    if(s.length() == n) {
        spidey.push_back(stoll(s));
        return;
    }

    for(auto u: {'3', '6'}) {
        s += u;
        generate(s, n);
        s.pop_back();
    }
}

void run_cases() {

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    string s = "";

    generate(s, 18);

    cout << spidey.size() << '\n';

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}