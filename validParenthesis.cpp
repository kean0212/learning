#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;
        for (int i = 0; i < s.length(); ++i) {
            if (!chars.empty()) {
                char top = chars.top();
                if ((top == '(' && s[i] == ')') ||
                    (top == '{' && s[i] == '}') ||
                    (top == '[' && s[i] == ']')) {
                    chars.pop();
                } else {
                    chars.push(s[i]);
                }
            } else {
                chars.push(s[i]);
            }
        }
        return chars.empty();
    }
};

int main() {
    string s1 = "()[]{}";
    string s2 = "([)]";
    string s3 = "(())";
    string s4 = "({[]})";
    Solution solution;
    cout << solution.isValid(s1) << endl;
    cout << solution.isValid(s2) << endl;
    cout << solution.isValid(s3) << endl;
    cout << solution.isValid(s4) << endl;
}