#include <string>
#include <vector>

using namespace std;

int main() {
    string s = "aab";
    const char* chars = s.c_str();
    char* temp = chars;
    vector<string> res;
    for (int i = 0; i < s.length(); ++i) {
        res.push_back(string(temp + i));
    }
}