#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    void helper(string& s, int start, int tokens, string& addr, vector<string>& res) {
        if (start > s.length()) return;
        if (start == s.length()) {
            if (tokens == 4) res.push_back(addr.substr(0, addr.length() - 1));
            return;
        }
        for (int count = 1; count <= 3; ++count) {
//            cout << start << endl;
            string token = s.substr(start, count);
            if (token[0] == '0' && token.length() > 1) break;
            if (stoi(token) >= 0 && stoi(token) < 256) {
                addr += token + ".";
                helper(s, start + count, tokens + 1, addr, res);
                addr.erase(addr.length() - token.length() - 1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() > 12) return res;
        string addr = "";
        helper(s, 0, 0, addr, res);
        return res;
    }
};
// class Solution {
//     void helper(string s, int start, vector<string>& res, string ip, int count) {
//         if (start > s.length()) {
//             return;
//         }
//         if (start == s.length()) {
//             if (count == 4) {
//                 res.push_back(ip.substr(0, ip.length() - 1));
//             }
//             return;
//         }
//         for (int i = 1; i <= 3; ++i) {
//             string token = s.substr(start, i);
//             if (token[0] == '0' && token.length() > 1) {
//                 break;
//             }
//             int temp = stoi(token);
//             if (temp >= 0 && temp <= 255) {
//                 ip += token + ".";
//                 helper(s, start + i, res, ip, count + 1);
//                 ip.erase(ip.length() - token.length() - 1);
//             }
//         }
//     }
// public:
//     vector<string> restoreIpAddresses(string s) {
//         vector<string> res;
//         if (s.length() > 12) {
//             return res;
//         }
//         string ip = "";
//         int count = 0;
//         ip.reserve(s.length() + 4);
//         helper(s, 0, res, ip, count);
//         return res;
//     }
// };
int main() {
    Solution s;
    vector<string> res = s.restoreIpAddresses("25525511135");
    for (string x : res) {
        cout << x << " ";
    }
    cout << endl;
}