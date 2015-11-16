#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    int *cache;
public:
    NumArray(vector<int> &nums) {
        cache = new int[nums.size()]();
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cache[i] = res + nums[i];
            res += nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return cache[j];
        }
        return cache[j] - cache[i - 1];
    }
};

int main() {
    int array[] = {-2, 0, 3, -5, 2, -1};
    vector<int> nums(array, array + 6);
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
}
