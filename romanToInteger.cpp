#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

//class Solution {
//    unordered_map<char, int> mapping;
//
//public:
//    Solution() : mapping({
//        {'I', 1},
//        {'V', 5},
//        {'X', 10},
//        {'L', 50},
//        {'C', 100},
//        {'D', 500},
//        {'M', 1000}}){}
//    int romanToInt(string s) {
//        int res = 0;
//        for (int i = 0; i < s.length(); ++i) {
//            char c1 =s[i];
//            if (c1 == 'I') {
//                if (i < s.length() - 1) {
//                    char c2 = s[i + 1];
//                    if (c2 == 'V') {
//                        // check if it's IV
//                        res += 4;
//                        ++i;
//                    } else if (c2 == 'X') {
//                        // check if it's IX
//                        res += 9;
//                        ++i;
//                    } else {
//                        res += mapping[c1];    
//                    }
//                } else {
//                    res += mapping[c1];
//                }
//            } else if (c1 == 'X') {
//                if (i < s.length() - 1) {
//                    char c2 = s[i + 1];
//                    if (c2 == 'L') {
//                        // check if it's XL
//                        res += 40;
//                        ++i;
//                    } else if (c2 == 'C') {
//                        // check if it's XC
//                        res += 90;
//                        ++i;
//                    } else {
//                        res += mapping[c1];
//                    }
//                } else {
//                    res += mapping[c1];
//                }
//            } else if (c1 == 'C') {
//                if (i < s.length() - 1) {
//                    char c2 = s[i + 1];
//                    if (c2 == 'D') {
//                        // check if it's CD
//                        res += 400;
//                        ++i;
//                    } else if (c2 == 'M') {
//                        // check if it's CM
//                        res += 900;
//                        ++i;
//                    } else {
//                        res += mapping[c1];
//                    }
//                } else {
//                    res += mapping[c1];
//                }
//            } else {
//                res += mapping[c1];
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    int romanToInt(string s) {
        int mapping[256];
        mapping['I'] = 1;
        mapping['V'] = 5;
        mapping['X'] = 10;
        mapping['L'] = 50;
        mapping['C'] = 100;
        mapping['D'] = 500;
        mapping['M'] = 1000;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int temp;
            if ((temp = mapping[s[i]]) < mapping[s[i + 1]]) {
                res -= temp;
            } else {
                res += temp;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "XLVIII";
    cout << s.romanToInt(str) << endl;
}
