#include <iostream>
#include <string>

using namespace std;

class Solution {
    string addBinary(string a, string b, char carry) {
        int char_carry = carry - '0';
        if (a == "" && b == "") {
            if (char_carry) {
                return "1";
            } else {
                return "";
            }
        }
        if (a == "") {
            if (char_carry) {
                return addBinary(b, "1", '0');
            } else {
                return b;
            }
        }
        if (b == "") {
            if (char_carry) {
                return addBinary(a, "1", '0');
            } else {
                return a;
            }
        }
        string res = "";
        int char_a = a.back() - '0';
        string prev_a = a.substr(0, a.length() - 1);
        int char_b = b.back() - '0';
        string prev_b = b.substr(0, b.length() - 1);
        if (char_a && char_b) {
            res = addBinary(prev_a, prev_b, '1');
            if (!char_carry) {
                res += "0";
            } else {
                res += "1";
            }
        } else if ((char_a && !char_b) ||
                   (!char_a && char_b)) {
            if (!char_carry) {
                res = addBinary(prev_a, prev_b, '0') + "1";
            } else {
                res = addBinary(prev_a, prev_b, '1') + "0";
            }
        } else {
            res = addBinary(prev_a, prev_b, '0');
            if (!char_carry) {
                res += "0";
            } else {
                res += "1";
            }
        }
        return res;
    }
public:
    string addBinary(string a, string b) {
        return addBinary(a, b, '0');
    }
};

//class Solution {
//    int str2Int(string binary_str) {
//        int res = 0;
//        int shift = 0;
//        for (int i = binary_str.length() - 1; i >= 0; --i) {
//            if (binary_str[i] == '1') {
//                res |= 1 << shift;
//            }
//            shift++;
//        }
//        return res;
//    }
//    string int2Str(int n) {
//        if (n == 0) {
//            return "0";
//        }
//        string res = "";
//        while (n) {
//            if (n & 1) {
//                res = "1" + res;
//            } else {
//                res = "0" + res;
//            }
//            n >>= 1;
//        }
//        return res;
//    }
//    
//public:
//    string addBinary(string a, string b) {
//        int int_a = str2Int(a);
//        int int_b = str2Int(b);
//        return int2Str(int_a + int_b);
//    }
//};

int main() {
    Solution s;
    string a = "11";
    string b = "0";
    cout << s.addBinary(a, b) << endl;
}