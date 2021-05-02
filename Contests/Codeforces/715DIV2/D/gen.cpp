#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]) {
    registerGen(argc, argv, 1);
    
    println(1);
    int n = rnd.next(1, 5);
    println(n);
    for(int i=0;i<2*n;i++) {
        cout << rnd.next(0,1);
    }    
    cout << endl;
    for(int i=0;i<2*n;i++) {
        cout << rnd.next(0,1);
    }    
    cout << endl;
    for(int i=0;i<2*n;i++) {
        cout << rnd.next(0,1);
    }    
    cout << endl;
}   