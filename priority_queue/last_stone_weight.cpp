#include"../stdc++.h"

using namespace std;

int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        int heavy1, heavy2;
        while(pq.size() >= 2) {
            heavy1 = pq.top();
            pq.pop();
            heavy2 = pq.top();
            pq.pop();
            pq.push(abs(heavy1-heavy2));
        }
        return pq.top();
}

int main(){
    vector<int> v = {1,2};

    cout<< lastStoneWeight(v);

}
