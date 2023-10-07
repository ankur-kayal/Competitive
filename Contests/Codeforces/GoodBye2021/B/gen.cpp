#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    println(1);
    int n = rnd.next(1, 10);
    string s = rnd.next("[a-z]{" + to_string(n) + "}");

    println(n);
    println(s);

}