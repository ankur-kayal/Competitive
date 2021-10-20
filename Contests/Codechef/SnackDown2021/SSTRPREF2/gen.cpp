#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
        
    println(1);
    string s1 = rnd.next("[a-a]{1000000, 1000000}");
    string s2 = rnd.next("[a-a]{1000000, 1000000}");
    string x = rnd.next("[a-a]{1000000, 1000000}");

    println(s1);
    println(s2);
    println(x);
}