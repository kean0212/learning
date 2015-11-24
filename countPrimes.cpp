#include <iostream>
#include <cmath>

using namespace std;

//class Solution {
//    bool isPrime(int n) {
//        for (int i = 2; i <= sqrt(n); ++i) {
//            if (n % i == 0) {
//                return false;
//            }
//        }
//        return true;
//    }
//    
//public:
//    int countPrimes(int n) {
//        if (n <= 2) {
//            return 0;
//        }
//        return isPrime(n - 1) ? countPrimes(n - 1) + 1 : countPrimes(n - 1);
//    }
//};

class Solution {
    bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.countPrimes(49979) << endl;
}
