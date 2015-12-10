#include <iostream>
#include <vector>
#include <map>

using namespace std;

//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        int max_length = 0;
//        int size = nums.size();
//        vector<int> cache(size, 1);
//        for (int i = size - 2; i >= 0; --i) {
//            int temp = nums[i];
//            for (int j = size - 1; j > i; --j) {
//                if (nums[j] > nums[i]) {
//                    cache[i] = max(cache[j] + 1, cache[i]);
//                } else if (nums[j] == nums[i]) {
//                    cache[i] = max(cache[i], cache[j]);
//                }
//            }
//        }
//        for (int x : cache) {
//            max_length = max(max_length, x);
//        }
//        return max_length;
//    }
//};



int main() {
    Solution s;
    int array[] = {10, 9, 2, 5, 3, 4};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    cout << s.lengthOfLIS(nums) << endl;
}