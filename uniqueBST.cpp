#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int temp = 2 * n;
        double numerator = 1;
        double denominator = 1;
        for (int i = 1; i <= n; ++i) {
            denominator *= i;
            numerator *= temp - i + 1;
        }
        return round(numerator / denominator / (n + 1));
    }

//    int numTrees(int n) {
//        int *cache = new int[n + 1]();
//        cache[0] = 1;
//        cache[1] = 1;
//        int sum = 0;
//        int left = 0;
//        int right = 0;
//        for (int i = 2; i <= n; ++i) { // for n
//            for (int j = 1; j <= i; ++j) { // for the previous, j as the root
//                left = cache[j - 1];
//                right = cache[i - j];
//                sum += left * right;
//            }
//            cache[i] = sum;
//            sum = 0;
//        }
//        return cache[n];
//    }
    
};

int main() {
    Solution s;
    cout << s.numTrees(17) << endl;
}
