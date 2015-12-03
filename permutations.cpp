#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int> > helper(vector<int> nums, int i) {
        vector<vector<int> > res;
        if (i < 0) {
            return res;
        }
        if (i == 0) {
            vector<int> permutation(1, nums[0]);
            res.push_back(permutation);
            return res;
        }
        vector<vector<int> > prev_res = helper(nums, i - 1);
        for (auto prev_permutation : prev_res) {
            for (int j = 0; j <= prev_permutation.size(); ++j) {
                vector<int> temp = prev_permutation;
                temp.insert(temp.begin() + j, nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
public:
    vector<vector<int> > permute(vector<int>& nums) {
        return helper(nums, nums.size() - 1);
    }
};

int main() {
    Solution s;
    int array[] = {1, 2, 3};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    vector<vector<int> >res = s.permute(nums);
    for (auto permutation : res) {
        for (int x : permutation) {
            cout << x << " ";
        }
        cout << endl;
    }
}