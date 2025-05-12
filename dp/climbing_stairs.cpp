#include "../stdc++.h" 

using namespace std;

int climbing_stairs_util_recur(int n) {

    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }

    return climbing_stairs_util_recur(n-1) + climbing_stairs_util_recur(n-2);

}

int climbing_stairs_util_dp(int n) {

    int one = 1;
    int two = 0;
    int res = 0;

    for (int i = n-1; i >=0; i--) {
        res = one + two;

        one = res;
        two = one;
    }

    return res;

}

int clmbing_stairs (int n) {
    int res = 0;

    res = climbing_stairs_util_dp(n);

    return res;
}

int main() {
    int n = 1;

    int res = clmbing_stairs(n);
}