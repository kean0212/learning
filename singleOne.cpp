#include <vector>
#include <iostream>

using namespace  std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= nums[i];   
        }
        return res;
    }
};

int main() {
    int array[] = {1, 8, 3, 2, 10, 7, 3, 5, 5, 7, 8, 2, 10};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    Solution s;
    cout << s.singleNumber(nums) << endl;
}
