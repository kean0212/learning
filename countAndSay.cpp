#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string prev_res = countAndSay(n - 1);
        string res = "";
        char cur = prev_res[0];
        int count = 1;
        for (int i = 1; i < prev_res.length(); ++i) {
            if (prev_res[i] == cur) {
                count++;
            } else {
                res += "" + to_string(count) + cur;
                cur = prev_res[i];
                count = 1;
            }
        }
        return res + to_string(count) + cur;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(1) << endl;
    cout << s.countAndSay(2) << endl;
    cout << s.countAndSay(3) << endl;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(5) << endl;
}