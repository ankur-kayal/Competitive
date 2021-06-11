#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    int t = 1e4;
    int magic = 998244353;
    println(t);
    for(int i = 1; i <= t; i++) {
        println(magic, magic, magic);
    }
}