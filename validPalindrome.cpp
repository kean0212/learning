#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "") {
            return true;
        }
        int low = 0;
        int high = s.length() - 1;
        while (low < high) {
            while (!isalnum(s[low]) && low < s.length() - 1) {
                low++;
            }
            while (!isalnum(s[high]) && high >= 0) {
                high--;
            }
            if (low < high) {
                char low_char = tolower(s[low]);
                char high_char = tolower(s[high]);
                if (low_char != high_char) {
                    cout << low_char << " " << high_char << endl;
                    return false;
                } else {
                    low++;
                    high--;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    cout << solution.isPalindrome(s) << endl;
}