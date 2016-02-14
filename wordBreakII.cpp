#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
    bool wordBreakI(string s, unordered_set<string>& wordDict) {
        int length = s.length();
        bool* flags = new bool[length + 1]();
        flags[0] = true;
        for (int i = 1; i <= length; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                string token = s.substr(j, i - j);
                if (wordDict.count(token) && flags[j]) {
                    flags[i] = true;
                    break;
                }
            }
        }
        return flags[length];
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (!wordBreakI(s, wordDict)) return vector<string>();
        int length = s.length();
        vector<vector<string>> breaks(length + 1, vector<string>());
        for (int i = 1; i <= length; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                cout << j << endl;
                string token = s.substr(j, i - j);
                if (wordDict.count(token)) {
                    if (j > 0 && !breaks[j].empty()) {
                        for (auto one_break : breaks[j]) {
                            one_break += " " + token;
                            breaks[i].push_back(one_break);
                        }
                    } else if (!j) {
                        breaks[i].push_back(token);
                    }
                }
            }
        }
        return breaks.back();
    }
};

int main() {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    unordered_set<string> wordDict({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
                                     Solution solution;
                                     vector<string> res = solution.wordBreak(s, wordDict);
                                     for (auto str : res) {
                                     cout << str << endl;
                                     }
                                     
}