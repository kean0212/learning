#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    vector<vector<int> > levelOrderBottom(TreeNode* root) {
//        vector<vector<int> > res;
//        if (root == NULL) {
//            return res;
//        }
//        vector<vector<TreeNode*> > all_levels;
//        vector<TreeNode*> current_nodes;
//        current_nodes.push_back(root);
//        while (!current_nodes.empty()) {
//            vector<TreeNode*> parents = current_nodes;
//            current_nodes.clear();
//            all_levels.push_back(parents);
//            for (TreeNode *parent : parents) {
//                if (parent->left != NULL) {
//                    current_nodes.push_back(parent->left);
//                }
//                if (parent->right != NULL) {
//                    current_nodes.push_back(parent->right);
//                }
//            }
//        }
//        for (int i = all_levels.size() - 1; i >= 0; --i) {
//            vector<int> level;
//            for (int j = 0; j < all_levels[i].size(); ++j) {
//                level.push_back(all_levels[i][j]->val);
//            }
//            res.push_back(level);
//        }
//        return res;
//    }
//};

class Solution {
    int depth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(depth(root->left), depth(root->right)) + 1;
    }
    
    void addLevels(vector<vector<int> > &all_levels, TreeNode* root, int i) {
        if (root == NULL || i < 0) {
            return;
        }
        all_levels[i].push_back(root->val);
        addLevels(all_levels, root->left, i - 1);
        addLevels(all_levels, root->right, i - 1);
        return;
    }
    
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<int> level;
        vector<vector<int> > all_levels(d, level);
        if (root == NULL) {
            return all_levels;
        }

        addLevels(all_levels, root, d - 1);
        return all_levels;
    }
};

int main() {
    TreeNode root(1);
    Solution s;
    vector<vector<int> > res = s.levelOrderBottom(&root);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
