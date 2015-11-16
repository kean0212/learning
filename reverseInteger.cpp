#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        double res = 0;
        int temp = abs(x);
        while (temp) {
            int mod = temp % 10;
            res = res * 10 + mod;
            temp /= 10;
        }
        if (res > numeric_limits<int>::max() || res < numeric_limits<int>::min()) {
            return 0;
        } else {
            return x > 0 ? res : -res;
        }
    }
};

int main() {
    cout << sizeof(double) << endl;
    cout << sizeof(int) << endl;
    Solution s;
    cout << s.reverse(1534236469) << endl;
}