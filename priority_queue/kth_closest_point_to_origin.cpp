#include"../stdc++.h"

using namespace std;

class Comparator{
    public:
        bool operator() (const vector<int> a, const vector<int> b) {
            if (a[0]*a[0] > b[2]){
                return true;
            } else {
                return false;
            }
        }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
    int distance = 0;
    vector<vector<int>> result;
    priority_queue<vector<int>, vector<vector<int>>, Comparator > pq ; 

    for (auto i : points) {
        pq.push(i);
    }

    for (int j = 0; j<k; j++) {
        result.push_back(pq.top());
        pq.pop();
    }

    return result;

}

int main() {
    vector<vector<int>> points = {{0,2}, {2,2}} ;
    vector<vector<int>> result ;
    result = kClosest(points, 1);

}