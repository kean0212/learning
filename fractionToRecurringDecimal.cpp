#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int num, int denom) {
        string res = "";
        bool positive = (num > 0 && denom > 0) || (num < 0 && denom < 0);
        long numerator = num;
        numerator = abs(numerator);
        long denominator = denom;
        denominator = abs(denominator);
        if (denominator == 0) {
            return res;
        }
        if (numerator == 0) {
            return "0";
        }
        res += to_string(numerator / denominator);
        long remainder = numerator % denominator;
        if (remainder) {
            res += ".";
        }
        unordered_map<int, int> hash; // last remainder and its corresponding index in the string
        int pos = res.length();
        while ((remainder *= 10)) {
            while (remainder < denominator) {
                remainder *= 10;
                res += "0";
                pos++;
            }
            if (hash.count(remainder)) break;
            hash[remainder] = pos;
            res += to_string(remainder / denominator);
            remainder %= denominator;
            pos++;
        }
        if (remainder) {
            res.insert(hash[remainder], 1, '(');
            res += ')';
        }
        return positive ? res : "-" + res;
    }
};

int main() {
    Solution s;
    int num = INT_MIN;
    cout << s.fractionToDecimal(num, -1) << endl;
}