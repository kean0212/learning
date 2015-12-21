#include <vector>
#include <iostream>

using namespace std;

class Solution {
    void helper(vector<vector<int> >& res, vector<int>& candidates, int start, int target, vector<int>& combination) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            combination.push_back(candidates[i]);
            helper(res, candidates, i + 1, target - candidates[i], combination);
            combination.pop_back();
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        for (int i = 0; i < candidates.size(); ++i) {
            if (i > 0 && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            combination.push_back(candidates[i]);
            helper(res, candidates, i + 1, target - candidates[i], combination);
            combination.pop_back();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums({1});
    int target = 1;
    vector<vector<int> > res = s.combinationSum2(nums, target);
    for (auto combination : res) {
        for (int x : combination) {
            cout << x << " ";
        }
        cout << endl;
    }
}