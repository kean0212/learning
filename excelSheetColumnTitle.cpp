#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        if (n < 1) {
            return res;
        }
        while (n) {
            res = (char) ('A' + (--n) % 26) + res;
            n /= 26;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(26) << endl;
    cout << s.convertToTitle(27) << endl;
    cout << s.convertToTitle(32) << endl;
}
