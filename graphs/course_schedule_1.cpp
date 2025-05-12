#include "../stdc++.h" 

using namespace std;

class GraphNode {
    
}

bool course_schedule(int num_of_courses, vector<vector<int>> preq_list){
    
}

int main() {
    int num_of_courses = 4;
    vector<vector<int>> preq_list = {{1, 0},
    {2, 0},
    {3, 1},
    {3, 2}
    };

    bool res = course_schedule(num_of_courses, preq_list);
    cout<<"completed";
}