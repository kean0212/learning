#include <vector>
#include <iostream>

using namespace std;

int findMissingNumber(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[left] + mid - left) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return nums[left] == nums[left - 1] + 1 ? -1 : nums[left - 1] + 1;
}

int main() {
    vector<int> nums({1,2,3,4,5,7});
    cout << findMissingNumber(nums) << endl;
}