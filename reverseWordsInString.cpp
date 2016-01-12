#include <string>
#include <iostream>

using namespace std;

class Solution {
    void swapChars(string& str, size_t& start, size_t& end) {
        while (start < end) {
            swap(str[start++], str[end--]);
        }
    }
public:
    void reverseWords(string &s) {
        // find the last non-trailing character
        int pos_first_char = s.find_first_not_of(' ');
        int pos_last_char = s.find_last_not_of(' ');
        if (pos_last_char == string::npos) {
            s = "";
        } else {
            s.erase(pos_last_char + 1);
            s.erase(0, pos_first_char);
            // swap front and back
            size_t start = 0;
            size_t end = s.length() - 1;
            swapChars(s, start, end);
            // swap the chars in each word and reduce the white space
            start = 0;
            size_t pos_first_space;
            while ((pos_first_space = s.find_first_of(' ', start)) != string::npos) {
                end = pos_first_space - 1;
                swapChars(s, start, end);
                start = pos_first_space + 1;
                while (s[start] == ' ') {
                    s.erase(start, 1);
                }
            }
            // swap the last word
            end = s.size() - 1;
            swapChars(s, start, end);
        }
    }
};

int main() {
    Solution s;
    string str = "";
    s.reverseWords(str);
    cout << str << endl;
}