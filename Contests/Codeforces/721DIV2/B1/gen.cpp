#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int n = rnd.next(1, 500);
    string s = "", rev = "";
    println(n * 2);
    for(int i=0;i<n-1;i++) {
        s += (rnd.next(0, 1) + '0');
    }
    s += '0';
    rev = s;
    reverse(rev.begin(), rev.end());
    s = s + rev;
    println(s);    
}