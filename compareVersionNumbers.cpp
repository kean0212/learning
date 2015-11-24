#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        while (version1 != "" || version2 != "") {
            if (version1 == "") {
                // version1 is empty but version2 isn't
                size_t pos = version2.find_first_of('.');
                int current = stoi(version2.substr(0, pos));
                if (current) {
                    return -1;
                } else {
                    if (pos == string::npos) {
                        version2 = "";
                    } else {
                        version2 = version2.substr(pos + 1);
                    }
                }
            } else if (version2 == "") {
                // version2 is empty but version1 isn't
                size_t pos = version1.find_first_of('.');
                int current = stoi(version1.substr(0, pos));
                if (current) {
                    return 1;
                } else {
                    if (pos == string::npos) {
                        version1 = "";
                    } else {
                        version1 = version1.substr(pos + 1);
                    }
                }
            } else {
                // both version1 and version2 aren't empty
                size_t pos1 = version1.find_first_of('.');
                size_t pos2 = version2.find_first_of('.');
                int current1 = stoi(version1.substr(0, pos1));
                int current2 = stoi(version2.substr(0, pos2));
                if (current1 > current2) {
                    return 1;
                } else if (current1 < current2) {
                    return -1;
                }
                if (pos1 != string::npos) {
                    version1 = version1.substr(pos1 + 1);
                } else {
                    version1 = "";
                }
                if (pos2 != string::npos) {
                    version2 = version2.substr(pos2 + 1);
                } else {
                    version2 = "";
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    string version1 = "1";
    string version2 = "1.0.0";
    cout << s.compareVersion(version1, version2) << endl;
}