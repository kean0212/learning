#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;


// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    UndirectedGraphNode* helper(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& hash) {
        if (!node) return NULL;
        if (!hash.count(node)) {
            hash[node] = new UndirectedGraphNode(node->label);
            for (auto x : node->neighbors) {
                hash[node]->neighbors.push_back(helper(x, hash));
            }
        }
        return hash[node];
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
        return helper(node, hash);
    }
    
};

int main() {
    Solution s;
    UndirectedGraphNode n1(-1);
    UndirectedGraphNode n2(1);
//    UndirectedGraphNode n3(3);
    n1.neighbors.push_back(&n2);
//    n1.neighbors.push_back(&n3);
//    n2.neighbors.push_back(&n3);
//    n3.neighbors.push_back(&n3);
    UndirectedGraphNode* res= s.cloneGraph(&n1);
    for (auto neighbor : n1.neighbors) {
        cout << neighbor->label << " ";
    }
    cout << endl;
    for (auto neighbor : n2.neighbors) {
        cout << neighbor->label << " ";
    }
    cout << endl;
//    for (auto neighbor : n3.neighbors) {
//        cout << neighbor->label << " ";
//    }
//    cout << endl;
}