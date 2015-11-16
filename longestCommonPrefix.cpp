#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        string prefix = "";
//        char cur_char = '\0';
//        int index = 0;
//        while (true) {
//            for (int i = 0; i < strs.size(); ++i) {
//                if (strs[i] == "") {
//                    return "";
//                } else {
//                    if (index < strs[i].length()) {
//                        if (cur_char == '\0') {
//                            cur_char = strs[i][index];
//                        } else {
//                            if (strs[i][index] != cur_char) {
//                                return prefix;
//                            }
//                        }    
//                    } else {
//                        return prefix;
//                    }
//                }
//            }
//            prefix += cur_char;
//            index++;
//            cur_char = '\0';
//        }
//    }
//};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.size() == 0) {
            return prefix;
        }
        int min = numeric_limits<int>::max();
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i] == "") {
                return "";
            }
            if (strs[i].length() < min) {
                prefix = strs[i];
                min = strs[i].length();
            }
        }
        for (int i = 0; i < prefix.length(); ++i) {
            char cur_char = prefix[i];
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[j][i] != cur_char) {
                    return prefix.substr(0, i);
                }
            }
        }
        return prefix;
    }
};

int main() {
    Solution s;
    string array[] = {"", "ab", "abc", "abcd"};
    vector<string> strs(array, array + 4);
    cout << s.longestCommonPrefix(strs) << endl;
}