#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return res;
    }
};

int main() {
    Solution s;
    int array[] = {1,1,1,2,4,4,4,5,5,5,5,6,7,8,8,9,9,9,9,9,9,10};
    int target = 12;
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    vector<int> res = s.searchRange(nums, target);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}