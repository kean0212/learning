#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        for (string token : tokens) {
            if (token == "+") {
                nums[nums.size() - 2] += nums.back();
                nums.pop_back();
            } else if (token == "-") {
                nums[nums.size() - 2] -= nums.back();
                nums.pop_back();
            } else if (token == "*") {
                nums[nums.size() - 2] *= nums.back();
                nums.pop_back();
            } else if (token == "/") {
                nums[nums.size() - 2] /= nums.back();
                nums.pop_back();
            } else {
                nums.push_back(stoi(token));
            }
        }
        return nums.front();
    }
};

int main() {
    Solution s;
    vector<string> tokens({"3", "4", "5", "*", "-"});
    cout << s.evalRPN(tokens) << endl;
}