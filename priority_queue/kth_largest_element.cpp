#include "../stdc++.h"
using namespace std;

class KthLargest {
    public:
        priority_queue<int , vector<int>, greater<int> > pq;
        KthLargest(int k, vector<int>& nums) {
            
            for (auto i : nums) {
                if (pq.size() < 3) {
                    pq.push(i);
                }else {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        
        int add(int val) {
            if (pq.size() < 3) {
                pq.push(val);
            }else {
                pq.pop();
                pq.push(val);
            }
            return pq.top();

        }
    };

int main() {
    vector<int> v = {1, 2, 3, 3};
    KthLargest *kthLargest = new KthLargest(3, v);
    cout<<kthLargest->add(3);   // return 3
    cout<<kthLargest->add(5);   // return 3
    cout<<kthLargest->add(6);   // return 3
    cout<<kthLargest->add(7);   // return 5
    cout<<kthLargest->add(8);   // return 6
}