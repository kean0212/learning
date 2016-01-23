#include <string>
#include <iostream>

using namespace std;

class Solution {
    char bases[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    string convertDigit(int num, int start) {
        if (!num) return "";
        if (num > 0 && num < 4) {
            return string(num, bases[start]);
        } else if (num == 4) {
            return string(1, bases[start]) + string(1, bases[start + 1]);
        } else if (num == 5) {
            return string(1, bases[start + 1]);
        } else if (num > 5 && num < 9) {
            return string(1, bases[start + 1]) + string(num - 5, bases[start]);
        } else {
            return string(1,bases[start]) + string(1, bases[start + 2]);
        }
    }
public:
    string intToRoman(int num) {
        string res = "";
        for (int i = 0; i < 7 && num; i += 2, num /= 10) {
            res = convertDigit(num % 10, i) + res;
        }
        if (num) res = string(num, 'M') + res;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(1235) << endl;
}