#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return n > m ? (rangeBitwiseAnd(m >> 1, n >> 1) << 1) : m;
    }
};

int main() {
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7) << endl;
}