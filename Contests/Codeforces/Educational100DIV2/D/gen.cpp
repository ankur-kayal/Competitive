#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int64_t rand(int64_t a, int64_t b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    // int t = rand(1,1000);
    int t = 1;
    cout << t << '\n';
    while(t--) {
        int n = rand(1, 200000);
        set<int> a;
        while(a.size() != n) {
            a.insert(rand(1, 2*n));
        }
        cout << n << '\n';
        for(auto u: a) {
            cout << u << " ";
        }
        cout << '\n';
    }
}