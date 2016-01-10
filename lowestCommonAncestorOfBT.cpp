#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//    struct Result {
//        bool isAncestor;
//        TreeNode *node;
//        Result(bool i, TreeNode* n) {
//            isAncestor = i;
//            node = n;
//        }
//    };
//    Result helper(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == NULL) {
//            return Result(false, NULL);
//        }
//        Result left_res = helper(root->left, p, q);
//        Result right_res = helper(root->right, p, q);
////        if (left_res.node) {
////            cout << "root " << root->val << endl;
////            cout << "left_res is " << left_res.node->val << endl;
////        }
////        if (right_res.node) {
////            cout << "root " << root->val << endl;
////            cout << "right_res is " << right_res.node->val << endl;
////        }
//        // Cases where ancestor has been found
//        if (left_res.isAncestor) {
//            return left_res;
//        }
//        if (right_res.isAncestor) {
//            return right_res;
//        }
//        // Cases where root is ancestor
//        if ((left_res.node == p && right_res.node == q) ||
//            (left_res.node == q && right_res.node == p) ||
//            (root == p && (left_res.node == q || right_res.node == q)) ||
//            (root == q && (left_res.node == p || right_res.node == p)) ||
//            (root == p && root == q)) {
//            return Result(true, root);
//        }
//        // Cases where p or q is found
//        if (root == p || root == q) {
//            return Result(false, root);
//        }
//        if (left_res.node && !right_res.node) {
//            return left_res;
//        }
//        if (!left_res.node && right_res.node) {
//            return right_res;
//        }
//        return Result(false, NULL);
//    }
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        Result res = helper(root, p, q);
//        if (res.isAncestor) {
//            return res.node;
//        }
//        cout << "hello world" << endl;
//        return NULL;
//    }
//};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left_res = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_res = lowestCommonAncestor(root->right, p, q);
        return !left_res ? right_res : (!right_res ? left_res : root);
    }
};

int main() {
    Solution s;
    TreeNode root(3);
    TreeNode level1_1(5);
    TreeNode level1_2(1);
    TreeNode level2_1(6);
    TreeNode level2_2(2);
    TreeNode level2_3(0);
    TreeNode level2_4(8);
    TreeNode level3_1(7);
    TreeNode level3_2(4);
    root.left = &level1_1;
    root.right = &level1_2;
    level1_1.left = &level2_1;
    level1_1.right = &level2_2;
    level1_2.left = &level2_3;
    level1_2.right = &level2_4;
    level2_2.left = &level3_1;
    level2_2.right = &level3_2;
    TreeNode* res = s.lowestCommonAncestor(NULL, &level3_1, &level2_3);
    cout << (res ? res->val : 3) << endl;
}