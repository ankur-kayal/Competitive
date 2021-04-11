#include <algorithm>
#include <testlib.h>
#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n;
    cin >> n;
    vector<int> a(n);
    iota(all(a), 1);
    int count = 1;
    for(int i=1;i<=n;i++) {
        count *= i;
    }
    println(count);
    do {
        println(n);
        println(a);
    } while(next_permutation(all(a)));
}