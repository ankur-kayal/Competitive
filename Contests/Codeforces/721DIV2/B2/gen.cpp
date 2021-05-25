#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int n = rnd.next(1, 1000);
    string s = "";
    println(n);
    for(int i=0;i<n;i++) {
        s += (rnd.next(0, 1) + '0');
    }
    println(s);    
}