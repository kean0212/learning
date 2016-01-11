#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    void helper(vector<string>& res, string &str, int index, int length, int left, int right) {
        if (index > length - 1) {
            res.push_back(str);
            return;
        }
        if (left) {
            str[index] = '(';
            helper(res, str, index + 1, length, left - 1, right);
        }
        if (left < right) {
            str[index] = ')';
            helper(res, str, index + 1, length, left, right -1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int length = 2 * n;
        string str(length, ' ');
        vector<string> res;
        helper(res, str, 0, length, n, n);
        return res;
    }
};

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}