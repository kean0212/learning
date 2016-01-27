#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
//    string s = "aab";
//    const char* chars = s.c_str();
//    char* temp = chars;
//    vector<string> res;
//    for (int i = 0; i < s.length(); ++i) {
//        res.push_back(string(temp + i));
//    }
    string s = "0234";
    cout << stoi(s) << endl;
    
    vector<int> empty;
    cout << (empty.begin() == empty.end()) << endl;
    
    empty.push_back(1);
    auto it = empty.begin();
    cout << (++it == empty.end()) << endl;
    
    empty.insert(empty.end(), 2);
    cout << empty.size() << endl;
}