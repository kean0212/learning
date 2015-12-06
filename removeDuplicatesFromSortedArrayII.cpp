#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) {
            return size;
        }
        int first = 0;
        int second = 1;
        int count = 1;
        while (second < size) {
            if (nums[second] == nums[first]) {
                if (count < 2) {
                    nums[++first] = nums[second++];
                } else {
                    second++;
                }
                count++;
            } else {
                nums[++first] = nums[second++];
                count = 1;
            }
        }
        return first + 1;
    }
};
