#include <vector>
#include <string>
#include <iostream>

using namespace std;

//class Solution {
//    bool isPalindrome(string s) {
//        int left, right, n = s.length();
//        if (n == 1) return true;
//        left = n / 2 - 1;
//        if (n % 2)  right = left + 2;
//        else        right = left + 1;
//        while (left >= 0 && right < n)
//            if (s[left--]!= s[right++]) return false;
//        return true;
//    }
//    void backTrack(string s, vector<string>& partition, vector<vector<string>>& res) {
//        if (s.empty()) {
//            res.push_back(partition);
//            return;
//        }
//        for (int i = 1; i <= s.length(); ++i) {
//            string token = s.substr(0, i);
//            if (isPalindrome(token)) {
//                partition.push_back(token);
//                backTrack(s.substr(i), partition, res);
//                partition.pop_back();
//            }
//        }
//    }
//public:
//    vector<vector<string>> partition(string s) {
//        vector<vector<string>> res;
//        if (s.empty()) return res;
//        vector<string> partition;
//        backTrack(s, partition, res);
//        return res;
//    }
//};

class Solution {
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    void helper(string& s, int start, vector<string>& partition, vector<vector<string>>& res) {
        if (start == s.length()) {
            res.push_back(partition);
            return;
        }
        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                partition.push_back(s.substr(start, end - start + 1));
                helper(s, end + 1, partition, res);
                partition.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> partition;
        helper(s, 0, partition, res);
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