#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        vector<string> tokens;
        while (!path.empty()) {
            size_t pos = path.find_first_of('/');
            string token = path.substr(0, pos);
            if (token == "..") {
                if (!tokens.empty()) {
                    tokens.pop_back();
                }
            } else if (token != "." && token != "") {
                tokens.push_back(token);
            }
            if (pos == string::npos) {
                path = "";
            } else {
                path = path.substr(pos + 1);
            }
        }
        if (tokens.empty()) {
            return "/";
        }
        for (string token : tokens) {
            res += "/" + token;
        }
        return res;
    }
};
int main() {
    Solution s;
    string str = "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///";
    cout << s.simplifyPath(str) << endl;
}