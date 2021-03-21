#include <testlib.h>
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for(int i=1;i<=100;i++) {
        println(rnd.next(1,2));
    }
}