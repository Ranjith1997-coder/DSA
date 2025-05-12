#include"../stdc++.h"

using namespace std;

bool checkPowersOfThree(int n){
    if (n < 0) {
        return false;
    }

    if (n == 0) {
        return true;
    }

    int power = 1;
    while (n / pow(3, power) > 0) {
        
        if (checkPowersOfThree(n - pow(3, power))) {
            return true;
        }
        power++;

    }

    return false;


}

int main() {

    int n = 12;

    bool res = checkPowersOfThree(n);

}