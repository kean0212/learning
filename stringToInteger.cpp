#include <string>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
    int sign = 1;
    size_t isValid(string str) {
        size_t pos = str.find_first_not_of(' ');
        if (pos != string::npos) {
            char c = str[pos];
            if (c == '+' || c == '-') {
                if (pos < str.length() - 1 && isdigit(str[pos + 1])) {
                    c == '+' ? sign = 1 : sign = -1;
                    return pos + 1;
                }
            } else if (c >= '0' && c <= '9') {
                sign = 1;
                return pos;
            }
        }
        return -1;
    }
    
    int stringToInt(string str) {
        double res = 0;
        double max_int = numeric_limits<int>::max();
        double min_int = numeric_limits<int>::min();
        for (int i = 0; i < str.length(); ++i) {
            char c = str[i];
            if (!isdigit(c)) {
                break;
            } else {
                res = res * 10 + c - '0';
            }
            if ((sign == 1) && (res > max_int)) {
                return max_int;
            }
            if ((sign == -1) && (res > -min_int)) {
                return min_int;
            }
        }
        return sign * res;
    }
    
public:
    int myAtoi(string str) {
        size_t pos;
        if ((pos = isValid(str)) != -1) {
            return stringToInt(str.substr(pos));
        } else {
            return 0;
        }
    }
};

int main() {
    Solution s;
    string str = "-2147483647";
    cout << s.myAtoi(str) << endl;
}