#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int findMin(vector<int>& nums, int low, int high) {
        if (low + 1 == high) {
            return nums[low] < nums[high] ? nums[low] : nums[high];
        }
        int mid = (low + high) / 2;
        if (nums[mid] > nums[high]) {
            return findMin(nums, mid, high);
        } else {
            return findMin(nums, low, mid);
        }
    }
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return findMin(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution s;
    int array[] = {-4, -4, -3};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    cout << s.findMin(nums) << endl;
}