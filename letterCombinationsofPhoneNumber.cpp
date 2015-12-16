#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void helper(vector<string>& res, string digits, int i, string& mapping, unordered_map<char, string>& hash_table) {
        if (i == digits.length() && i != 0) {
            res.push_back(mapping);
            return;
        }
        if (digits[i] != '0' && digits[i] != '1') {
            string potentials = hash_table[digits[i]];
            for (int j = 0; j < potentials.length(); ++j) {
                mapping[i] = potentials[j];
                helper(res, digits, i + 1, mapping, hash_table);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string mapping(digits.length(), ' ');
        unordered_map<char, string> hash_table({
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
            {'0', " "}
        });
        helper(res, digits, 0, mapping, hash_table);
        return res;
    }
};

int main() {
    Solution s;
    string str = "2";
    vector<string> res = s.letterCombinations(str);
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;
}