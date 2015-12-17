#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        long long dividend_long = dividend;
        long long divisor_long = divisor;
        bool isNegative = false;
        if (dividend < 0) {
            isNegative = !isNegative;
            dividend_long = -dividend_long;
        }
        if (divisor < 0) {
            isNegative = !isNegative;
            divisor_long = -divisor_long;
        }
        long long res = 0;
        while (dividend_long >= divisor_long) {
            long long sum = divisor_long;
            long long sub_res = 1;
            while ((sum << 1) <= dividend_long) {
                sub_res <<= 1;
                sum <<= 1;
            }
            dividend_long -= sum;
            res += sub_res;
        }
        if (!isNegative && res > INT_MAX) {
            return INT_MAX;
        }
        return isNegative ? -res : res;
    }
};

int main() {
    Solution s;
    cout << s.divide(-1010369383, INT_MIN) << endl;
    int b = INT_MIN;
    long long a = b;
    a = 0 - b;
    cout << a << endl;
}
