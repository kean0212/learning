#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    bool isIntermediate(string str1, string str2) {
        int count = 0;
        for (int i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[i]) {
                count++;
            }
        }
        return count == 1;
    }
    void helper(string beginWord, string endWord, unordered_set<string> wordList, int& minLength, vector<string>& ladder, vector<vector<string>>& res) {
        if (beginWord == endWord || isIntermediate(beginWord, endWord)) {
            if (isIntermediate(beginWord, endWord)) {
                ladder.push_back(endWord);
            }
            if (ladder.size() == minLength) {
                res.push_back(ladder);
            } else if (ladder.size() < minLength) {
                res.clear();
                res.push_back(ladder);
                minLength = ladder.size();
            }
            return;
        }
        for (auto it = wordList.begin(); it != wordList.end(); ++it) {
            if (isIntermediate(beginWord, *it)) {
                ladder.push_back(*it);
                unordered_set<string> newWordList = wordList;
                newWordList.erase(newWordList.find(*it));
                helper(*it, endWord, newWordList, minLength, ladder, res);
            }
        }
        return;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> res;
        vector<string> ladder({beginWord});
        wordList.erase(beginWord);
        int minLength = wordList.size() + 2;
        for (auto it = wordList.begin(); it != wordList.end(); ++it) {
            if (isIntermediate(beginWord, *it)) {
                ladder.push_back(*it);
                unordered_set<string> newWordList = wordList;
                newWordList.erase(newWordList.find(*it));
                helper(*it, endWord, newWordList, minLength, ladder, res);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList({"hot","dot","dog","lot","log"});
    vector<vector<string>> res = s.findLadders(beginWord, endWord, wordList);
    cout << res.size() << endl;
    for (auto ladder : res) {
        for (string x : ladder) {
            cout << x << " ";
        }
        cout << endl;
    }
}