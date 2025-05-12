#include"../stdc++.h"

using namespace std;

int gcd(int a, int b){
    int r1, r2;

    if (a > b){
        r1 = a;
        r2 = b;
    } else {
        r2 = a;
        r1 = b;
    }
    int reminder;
    while (r2 != 0) {
        reminder = r1 % r2;
        r1 = r2;
        r2 = reminder;
    }

    return r1;
}

int main() {
    int a = 60; 
    int b = 25;

    int res = gcd(a,b);
}