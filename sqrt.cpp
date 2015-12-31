#include <iostream>
#include <cmath>

using namespace std;

//class Solution {
//public:
//    int mySqrt(int x) {
//        long long left = 0;
//        long long right = x;
//        while (left <= right) {
////            cout << left << " " << right << endl;
//            long long mid = (left + right) / 2;
//            if (mid * mid == x) {
//                return mid;
//            } else if (mid * mid < x) {
//                if ((mid + 1) * (mid + 1) > x) {
//                    return mid;
//                } else {
//                    left = mid + 1;
//                }
//            } else {
//                if ((mid - 1) * (mid - 1) < x) {
//                    return mid - 1;
//                } else {
//                    right = mid - 1;
//                }
//            }
//        }
//    }
//};

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        }
        int left = 1;
        int right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};

int main() {
    Solution s;
    cout << (s.mySqrt(2147395599) == (int)sqrt(2147395599)) << endl;
}
