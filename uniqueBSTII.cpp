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
    vector<TreeNode*> generateSubtrees(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left_subtrees = generateSubtrees(start, i - 1);
            vector<TreeNode*> right_subtrees = generateSubtrees(i + 1, end);
            for (TreeNode* left_subtree : left_subtrees) {
                for (TreeNode* right_subtree : right_subtrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_subtree;
                    root->right = right_subtree;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        for (int i = 1; i <= n; ++i) {
            vector<TreeNode*> left_subtrees = generateSubtrees(1, i - 1);
            vector<TreeNode*> right_subtrees = generateSubtrees(i + 1, n);
            for (TreeNode* left_subtree : left_subtrees) {
                for (TreeNode* right_subtree : right_subtrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_subtree;
                    root->right = right_subtree;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<TreeNode*> res = s.generateTrees(2);
    cout << res[0]->val << endl;
    cout << res[1]->val << endl;
}