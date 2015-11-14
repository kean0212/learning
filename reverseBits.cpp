#include <iostream>

using namespace std;

class Solution {
    
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 1) {
                res |= 1 << (31 - i);
            }
            n >>= 1;
        }
        return res;
    }
    
    
};

int main () {
    int n = 43261596;
    Solution s;
    cout << s.reverseBits(n) << endl;
}