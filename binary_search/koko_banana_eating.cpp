#include"../stdc++.h"

using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int high = 0;
    int low = 1;
    int mid = 0;
    for (int i = 0; i < piles.size(); i ++) {
        if (high < piles[i]) {
            high = piles[i];
        }
    }

    int eating_time = 0;
    while(low <= high) {
        mid =( high + low ) /2;

        eating_time = 0;

        for (int i = 0; i < piles.size(); i++) {
            eating_time += ceil(static_cast<double> (piles[i]/mid));
        }

        if (eating_time > h) {
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }

    return mid;

}

int main() {
    vector<int> piles = {1,4,3,2};

    int hours = 9;

    int k = minEatingSpeed(piles, hours);

}