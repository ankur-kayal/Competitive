#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxVal = 1e5;

ll rand(ll a, ll b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = rand(1,20);
    int q = rand(1,10);
    cout << n << '\n';
    cout << q << '\n';
    for(int i=0;i<q;i++) {
        cout << rand(1, n) << '\n';
    }
}