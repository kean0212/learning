#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last_ture = n - 1;
        vector<bool> cache(n - 1, false);
        cache.push_back(true);
        for (int i = n - 2; i >= 0; --i) {
            if (i + nums[i] >= last_ture) {
                cache[i] = true;
                last_ture = i;
            }
        }
        return cache[0];
    }
};

int main() {
    Solution s;
    int array[] = {2,3,1,1,4};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    cout << s.canJump(nums) << endl;
}