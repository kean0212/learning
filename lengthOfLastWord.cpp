#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_char = s.length() - 1;
        while (last_char >= 0) {
            if (s[last_char] == ' ') {
                last_char--;
            } else {
                break;
            }
        }
        if (last_char < 0) {
            return 0;
        }
        for (int i = last_char - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                return last_char - i;
            }
        }
        return last_char + 1;
    }
};

int main() {
    string str = " a b c dwe    ";
    Solution s;
    cout << s.lengthOfLastWord(str) << endl;
}