#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    void helper(vector<int> nums, int start, vector<vector<int>>& res) {
        if (start == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[start]) {
                continue;
            }
            swap(nums[start], nums[i]);
            helper(nums, start + 1, res);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(nums, 0, res);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 1, 2, 2});
    vector<vector<int>> res = s.permuteUnique(nums);
    for (auto permutation : res) {
        for (int x : permutation) {
            cout << x << " ";
        }
        cout << endl;
    }
}