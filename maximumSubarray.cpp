#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        bool isAllNegative = true;
//        int max_elem = numeric_limits<int>::min();
//        int max_sum = 0;
//        int sum = 0;
//        for (int i = 0; i < nums.size(); ++i) {
//            int num = nums[i];
//            // If all elements were negative, then return the maximum
//            max_elem = num > max_elem ? nums[i] : max_elem;
//            if (isAllNegative && num > 0) {
//                isAllNegative = false;
//            }
//            // Otherwise, use the same methodology
//            int temp = 0;
//            if ((temp = sum + num) >= 0) {
//                if (temp > max_sum) {
//                    max_sum = temp;
//                }
//                sum = temp;
//            } else {
//                sum = 0;
//            }
//        }
//        return isAllNegative ? max_elem : max_sum;
//    }
//};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;
        for (int x : nums) {
            sum = sum > 0 ? sum + x : x;
            if (sum > res) {
                res = sum;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int array[] = {-2, -3, -1};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    cout << s.maxSubArray(nums) << endl;
}
