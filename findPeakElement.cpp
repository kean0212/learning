#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high - 1) { // at least three elements
            int mid = (low + high) / 2;
            if (nums[mid - 1] > nums[mid]) {
                high = mid - 1;
            } else if (nums[mid + 1] > nums[mid]) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return low == high - 1 && nums[high] > nums[low] ? high : low; // at most 2 elements
    }
};

int main() {
    int array[] = {-1};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    Solution s;
    cout << s.findPeakElement(nums) << endl;
}