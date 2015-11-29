#include <cmath>
#include <iostream>

using namespace std;

//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        if (m <= 0 || n <= 0) {
//            return -1;
//        }
//        double res = 1.0;
//        int total_moves = m + n - 2;
//        for (int i = 0; i < n - 1; ++i) {
//            res *= (double) (total_moves - i) / (i + 1);
//        }
//        return round(res);
//    }
//};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return -1;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        m--;
        n--;
        if (m < n) {
            m = m + n;
            n = m - n;
            m = m - n;
        }
        double res = 1;
        for (int i = m + n, j = 1; j <= n; --i, ++j) {
            res *= i;
            res /= j;
        }
        return (int)res;
    }
};

int main() {
    int m = 9;
    int n = 8;
    Solution s;
    cout << s.uniquePaths(m, n) << endl;
}
