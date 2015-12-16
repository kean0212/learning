#include <vector>
#include <iostream>

using namespace std;

//class Solution {
//    vector<vector<int> > threeSum(vector<int>&nums, int target, int start) {
//        vector<vector<int> > res;
//        for (int i = start; i < nums.size(); ++i) {
//            if (i != start && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            vector<int> sub_res;
//            int low = i + 1;
//            int high = nums.size() - 1;
//            while (low < high) {
//                int sum = nums[i] + nums[low] + nums[high];
//                if (sum == target) {
//                    res.push_back(vector<int> {nums[i], nums[low], nums[high]});
//                }
//                if (sum <= target) {
//                    low++;
//                    while(nums[low] == nums[low - 1]) {
//                        low++;
//                    }
//                }
//                if (sum >= target) {
//                    high--;
//                    while(nums[high] == nums[high + 1]) {
//                        high--;
//                    }
//                }
//            }
//        }
//        return res;
//    }
//public:
//    vector<vector<int> > fourSum(vector<int>& nums, int target) {
//        vector<vector<int> > res;
//        sort(nums.begin(), nums.end());
//        for(int i = 0; i < nums.size(); ++i) {
//            if (i != 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            vector<vector<int> > sub_res = threeSum(nums, target - nums[i], i + 1);
//            for (auto x : sub_res) {
//                x.insert(x.begin(), nums[i]);
//                res.push_back(x);
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 3; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                int low = j + 1;
                int high = n - 1;
                while (low < high) {
                    int sum = nums[i] + nums[j] + nums[low] + nums[high];
                    if (sum == target) {
                        res.push_back(vector<int> {nums[i], nums[j], nums[low], nums[high]});
                    }
                    if (sum <= target) {
                        do {
                            low++;
                        } while(nums[low] == nums[low - 1]);
                    }
                    if (sum >= target) {
                        do {
                            high--;
                        } while(nums[high] == nums[high + 1]);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int array[] = {0,0,0,0};
    int target = 0;
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    vector<vector<int> > res = s.fourSum(nums, target);
    for (auto x : res) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << res.size() << endl;
}