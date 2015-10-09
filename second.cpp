//
//  cc150.cpp
//  
//
//  Created by qifan li on 2015-10-09.
//
//

#include <iostream>

using namespace std;

// 1.1
bool isAllUnique(string str) {
    bool hash_table[256] = {false};
    int index = 0;
    for (int i = 0; i < str.length(); ++i) {
        index = (int)str[i];
        if (hash_table[index]) {
            return false;
        } else {
            hash_table[index] = true;
        }
    }
    return true;
}


// main function
int main() {
    string str = "helo world";
    cout << isAllUnique(str) << endl;
}
