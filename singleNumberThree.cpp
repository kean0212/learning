#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xor_all ^= nums[i];
        }
        int index_diff = 0;
        while ((xor_all & 1) == 0) {
            xor_all >>= 1;
            index_diff++;
        }
        int num1 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (((nums[i] >> index_diff) & 1) == 1) {
                num1 ^= nums[i];
            } else {
                num2 ^= nums[i];
            }
        }
        int array[] = {num1, num2};
        vector<int> res(array, array + 2);
        return res;
    }
};

int main() {
    Solution s;
    int array[] = {1, 2, 1, 3, 2, 5};
    vector<int> nums(array, array + 6);
    vector<int> res = s.singleNumber(nums);
    cout << res[0] << " " << res[1] << endl;
}