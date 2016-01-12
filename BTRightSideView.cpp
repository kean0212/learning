#include <queue>
#include <vector>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        res.push_back(root->val);
        queue<TreeNode*> current({root});
        while(!current.empty()) {
            queue<TreeNode*> parents;
            parents.swap(current);
            while (!parents.empty()) {
                TreeNode* parent = parents.front();
                parents.pop();
                if (parent->left) {
                    current.push(parent->left);
                }
                if (parent->right) {
                    current.push(parent->right);
                }
            }
            if (!current.empty())
                res.push_back(current.back()->val);
        }
        return res;
    }
};

int main() {
    Solution s;
    TreeNode root(1);
    vector<int> res = s.rightSideView(&root);
    
}