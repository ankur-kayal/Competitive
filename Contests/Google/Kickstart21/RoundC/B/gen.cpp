#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);

    int t = 1;
    println(t);

    int n = rnd.next(1, 10000);
    println(n);    
}