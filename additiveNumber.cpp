#include <deque>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    string addStrings(string s1, string s2) {
        int length1 = s1.length();
        int length2 = s2.length();
        int max_length = max(length1, length2);
        if (max_length == length2) {
            s1.insert(0, length2 - length1, '0');
        } else {
            s2.insert(0, length1 - length2, '0');
        }
        string res(max_length, 0);
        int carry = 0;
        for (int i = max_length - 1; i >= 0; --i) {
            int sum = s1[i] - '0' + s2[i] - '0' + carry;
            res[i] = '0' + (sum % 10);
            carry = sum / 10;
        }
        if (carry) {
            res = "1" + res;
        }
        return res;
    }
    bool helper(string num, int start, deque<string>& nums) {
        for (int length = 1; start + length <= num.length(); ++length) {
            if (num[start] == '0' && length > 1) break;
            string temp1 = num.substr(start, length);
            string temp2 = nums.front();
            if (addStrings(temp2, nums.back()) == temp1) {
                cout << temp2 << " + " << nums.back() << " = " << temp1 << endl;
                if (start + length == num.length()) return true;
                nums.pop_front();
                nums.push_back(temp1);
                if (helper(num, start + length, nums)) return true;
                nums.pop_back();
                nums.push_front(temp2);
            }
        }
        return false;
    }
public:
    bool isAdditiveNumber(string num) {
        if (num.length() < 3) return false;
        deque<string> nums;
        for (int l1 = 1; l1 <= num.length(); ++l1) {
            if (num[0] == '0' && l1 > 1) break;
            string num1 = num.substr(0, l1);
            nums.push_back(num1);
            for (int l2 = 1; l1 + l2 <= num.length(); ++l2) {
                if (num[l1] == '0' && l2 > 1) break;
                string num2 = num.substr(l1, l2);
                nums.push_back(num2);
                cout << nums.front() << " " << nums.back() << endl;
                if (helper(num, l1 + l2, nums)) return true;
                nums.pop_back();
            }
            nums.pop_back();
        }
        return false;
    }
};

int main() {
    Solution s;
    string num = "12012122436";
    cout << s.isAdditiveNumber(num) << endl;
//    cout << s.addStrings("123", "389") << endl;
}