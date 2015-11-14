#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1;
        m--;
        n--;
        while (m >= 0 && n >= 0) {
            if (nums1[m] > nums2[n]) {
                nums1[i] = nums1[m];
                m--;
            } else {
                nums1[i] = nums2[n];
                n--;
            }
            i--;
        }
        for (int j = 0; j <= n; ++j) {
            nums1[j] = nums2[j];
        }
    }
};

int main() {
    int array1[] = {0, 0, 3, 0, 0, 0, 0, 0, 0};
    vector<int> nums1(array1, array1 + 9);
    int array2[] = {-1, 1, 1, 1, 2, 3};
    vector<int> nums2(array2, array2 + 6);
    Solution s;
    s.merge(nums1, 3, nums2, 6);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;
}