#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 0) {
            return "";
        }
        string *rows = new string[numRows]();
        int modular = 2 * numRows - 2;
        for (int i = 0; i < s.length(); ++i) {
            int index = i % modular;
            if (index < numRows) {
                rows[index] += s[i];
                cout << "append " << s[i] << " to " << index << "-th row" << endl;
            } else {
                rows[modular - index] += s[i];
                cout << "append " << s[i] << " to " << modular - index << "-th row" << endl;
            }
        }
        string res = "";
        for (int i = 0; i < numRows; ++i) {
            res += rows[i];
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "PAYPALISHIRING";
    int numRows = 3;
    cout << s.convert(str, 3) << endl;
}