#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool inorderTraverse(TreeNode* root, int* &max) {
        if (root == NULL) {
            return true;
        }
        if (!inorderTraverse(root->left, max)) {
            return false;
        }
        if (max && root->val < *max) {
            return false;
        }
        if (!max) {
            max = new int[1];
        }
        *max = root->val;
        return inorderTraverse(root->right, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        int* max = NULL;
        return inorderTraverse(root, max);
    }
};

void test(int* x) {
    if (x == NULL) {
        x = new int[1];
    }
    if (*x == 100) {
        cout << "Succeed" << endl;
        return;
    }
    *x = *x + 1;
    test(x);
}
int main() {
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;
    Solution s;
//    cout << s.isValidBST(&root) << endl;
    int* x = NULL;
    test(x);
    cout << x << endl;
}