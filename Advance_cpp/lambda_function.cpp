#include "../stdc++.h"

using namespace std;

int main() {

    int c = 4;

    auto lambda = [&c] (int a , int b) {
        if (c == 5){
            return a+b+c;
        }
        c++;
        lambda(a, b);
        return 2;

    };

    cout<<lambda(1,2)<< endl;
    cout<<c;
}