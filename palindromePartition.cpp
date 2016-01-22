#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    bool isPalindrome(string s) {
        int left, right, n = s.length();
        if (n == 1) return true;
        left = n / 2 - 1;
        if (n % 2)  right = left + 2;
        else        right = left + 1;
        while (left >= 0 && right < n)
            if (s[left--]!= s[right++]) return false;
        return true;
    }
    void backTrack(string s, vector<string>& partition, vector<vector<string>>& res) {
        if (s.empty()) {
            res.push_back(partition);
            return;
        }
        for (int i = 1; i <= s.length(); ++i) {
            string token = s.substr(0, i);
            if (isPalindrome(token)) {
                partition.push_back(token);
                backTrack(s.substr(i), partition, res);
                partition.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) return res;
        vector<string> partition;
        backTrack(s, partition, res);
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<string>> res = s.partition("abbab");
    for (auto partition : res) {
        for (string palindrome : partition)
            cout << palindrome << " ";
        cout << endl;
    }
}