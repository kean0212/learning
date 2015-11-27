#include <iostream>

using namespace std;


//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        root->next = NULL;
        TreeLinkNode *head_current = root;
        TreeLinkNode *tail_current = root;
        while (head_current) {
            TreeLinkNode *parent = head_current;
            if (parent) {
                if (parent->left == NULL && parent->right == NULL) {
                    break;
                } else {
                    head_current = parent->left;
                    parent->left->next = parent->right;
                    tail_current = parent->right;
                }
                parent = parent->next;
            }
            while (parent) {
                if (parent->left) {
                    tail_current->next = parent->left;
                    parent->left->next = parent->right;
                    tail_current = parent->right;
                }
                parent = parent->next;
            }
            tail_current->next = NULL;
        }
    }
};

void output(TreeLinkNode *head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "0" << endl;
}

int main() {
    Solution s;
    TreeLinkNode n1(1);
    TreeLinkNode n2(2);
    TreeLinkNode n3(3);
    TreeLinkNode n4(4);
    TreeLinkNode n5(5);
    TreeLinkNode n6(6);
    TreeLinkNode n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    s.connect(&n1);
    output(&n1);
    output(&n2);
    output(&n4);
}