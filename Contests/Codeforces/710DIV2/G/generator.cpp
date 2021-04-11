#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    println(1);

    int n = rnd.next(1, 200000);
    string s;
    for(int i=0;i<n;i++) {
        s += char('a' + rnd.next(0, 25));
    }
    println(s);
}