#include "testlib.h"
#include "bits/stdc++.h"
using namespace std;


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    println(1);
    string s = "";
    int n = rnd.next(1, 20);
    for(int i=0;i<n;i++) {
        s += rnd.next(0,1) + '0';
    }
    if(s.front() == '0') {
        s = '1' + s;
    }
    println(s);
}
