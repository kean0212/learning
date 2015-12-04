#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void helper(int n, int k, int start, vector<int>& combination, vector<vector<int>>& res) {
        if (k == 0) {
            cout << "hello" << endl;
            res.push_back(combination);
            return;
        }
        for (int i = start; i <= n - (k - 1); ++i) {
            combination.push_back(i);
            helper(n, k - 1, i + 1, combination, res);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n == 0 || k == 0) {
            return res;
        }
        vector<int> combination;
        helper(n, k, 1, combination, res);
        return res;
    }
};

