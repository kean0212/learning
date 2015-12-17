#include <vector>
#include <iostream>
#include <climits>

using namespace std;

//class Solution {
//public:
//    void nextPermutation(vector<int>& nums) {
//        int n = nums.size();
//        int min_num = INT_MAX;
//        int min_index = n;
//        int i = 0;
//        for (i = n - 1; i > 0; --i) {
//            if (nums[i] < min_num) {
//                min_index = i;
//                min_num = nums[i];
//            }
//            if (nums[i - 1] < nums[i]) {
//                break;
//            }
//        }
//        if (i) {
//            nums[i - 1] = nums[i - 1] + min_num;
//            nums[min_index] = nums[i - 1] - min_num;
//            nums[i - 1] = nums[i - 1] - nums[min_index];
//            sort(nums.begin() + i, nums.end());
//        } else {
//            sort(nums.begin(), nums.end());
//        }
//    }
//};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        int j = i;
        while (i > 0 && nums[i-1] >= nums[i])
            i--;
        for (int k = i; k < j; k++, j--)
            swap(nums[k], nums[j]);
        if (i > 0) {
            j = i--;
            while (nums[j] <= nums[i])
                j++;
            swap(nums[i], nums[j]);
        }
    }
};

int main() {
    Solution s;
    int array[] = {3,1,4,4,2,3,4,0,0};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    s.nextPermutation(nums);
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}