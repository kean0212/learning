#include <utility>
#include <iostream>
#include <vector>

using namespace std;



class NumArray {
    class TreeNode {
    public:
        pair<int, int> range;
        int sum;
        TreeNode* left;
        TreeNode* right;
        TreeNode(pair<int, int> p, int s) : left(NULL), right(NULL) {
            range = p;
            sum = s;
        }
    };
    TreeNode* root;
    TreeNode* construct(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        if (l == r) return new TreeNode(make_pair(l, r), nums[l]);
        int mid = l + (r - l) / 2;
        TreeNode* left = construct(nums, l, mid);
        TreeNode* right = construct(nums, mid + 1, r);
        TreeNode* rt = new TreeNode(make_pair(l, r), left->sum + right->sum);
        rt->left = left;
        rt->right = right;
        return rt;
    }
    int sumRangeHelper(TreeNode* rt, int i, int j) {
        if (!rt) return 0;
        if (rt->range.first == i && rt->range.second == j) {
            return rt->sum;
        }
        if (i > rt->range.second || j < rt->range.first) return 0;
        int mid = rt->range.first + (rt->range.second - rt->range.first) / 2;
        if (mid >= j) return sumRangeHelper(rt->left, i, j);
        if (mid < i) return sumRangeHelper(rt->right, i, j);
        else return sumRangeHelper(rt->left, i, mid) + sumRangeHelper(rt->right, mid + 1, j);
    }
public:
    NumArray(vector<int> &nums) {
        root = construct(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) {
        if (!root) return;
        if (i < root->range.first || i > root->range.second) return;
        TreeNode* temp = root;
        while (temp->range.first != i || temp->range.second != i) {
            int mid = temp->range.first + (temp->range.second - temp->range.first) / 2;
            if (i > mid) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        int diff = val - temp->sum;
        temp->sum = val;
        temp = root;
        while (temp->range.first != i || temp->range.second != i) {
            temp->sum += diff;
            int mid = temp->range.first + (temp->range.second - temp->range.first) / 2;
            if (i > mid) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
    }

    int sumRange(int i, int j) {
        return sumRangeHelper(root, i, j);
    }
};

int main() {
    vector<int> nums({1,3,5});
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 0) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(2, 2) << endl;
}