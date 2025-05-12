#include"../stdc++.h"

using namespace std;

class GraphNode {
    public:
        int val;
        vector<GraphNode*> neighbours;

        GraphNode() {
            val = 0;
            neighbours = vector<GraphNode*>();
        }

        GraphNode(int value) {
            val = value;
            neighbours = vector<GraphNode*>();
        }
        GraphNode(int value, vector<GraphNode*>& _neighbours ) {
            val = value;
            neighbours = _neighbours;
        }
};

GraphNode* clone_graph(GraphNode* node) {

    queue<GraphNode*> q;
    unordered_map<GraphNode*, GraphNode*> old_to_new_map;

    q.push(node);
    GraphNode* tmpNode;
    old_to_new_map[node] = new GraphNode(node->val);
    while(!q.empty()){
        tmpNode = q.front();
        q.pop();

        for (auto neigh_node : tmpNode->neighbours){
            if (old_to_new_map.find(neigh_node) == old_to_new_map.end()) {
                old_to_new_map[neigh_node] = new GraphNode(neigh_node->val);
                // old_to_new_map[neigh_node]->neighbours.push_back(old_to_new_map[node]);
                q.push(neigh_node);
            }
            old_to_new_map[tmpNode]->neighbours.push_back(old_to_new_map[neigh_node]);
        }

    }
    return old_to_new_map[node];



}

int main() {

    GraphNode* one = new GraphNode(1);
    GraphNode* two = new GraphNode(2);
    GraphNode* three = new GraphNode(3);

    one->neighbours.push_back(two);
    two->neighbours.push_back(one);
    two->neighbours.push_back(three);
    three->neighbours.push_back(two);

    GraphNode* new_graph = clone_graph(one);

    cout<<"completed";

}