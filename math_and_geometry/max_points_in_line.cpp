#include"../stdc++.h"

using namespace std;

int max_points(vector<pair<int,int>> points) {

    unordered_map<float, int> count;
    int res = 1;

    for (int i = 0; i < points.size(); i ++) {
        count = unordered_map<float, int>();

        for (int j = 0; j < points.size(); j++) {

            if (i == j) {
                continue;
            }

            int numerator = points[i].first - points[j].first;
            int denominator = points[i].second - points[j].second;
            float slope;

            if (denominator == 0) {
                if (count.find(INT_MAX) == count.end()) {
                    count[INT_MAX] = 2;
                } else {
                    count[INT_MAX]++;
                }
            } else {
                slope = numerator / denominator;
                if (count.find(slope) == count.end()) {
                    count[slope] = 2;
                } else {
                    count[slope]++;
                }
            }

            res = max(count[slope] , res);


        }

        
    }

    return res;

}

int main() {

    vector<pair<int,int>> points = {{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}}};

    int res = max_points(points);
}