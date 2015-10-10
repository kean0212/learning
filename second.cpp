//
//  cc150.cpp
//  
//
//  Created by qifan li on 2015-10-09.
//
//

#include <iostream>
#include <algorithm>

using namespace std;

// 1.1
bool isAllUnique(string str) {
    if (str.length() > 256) {
        return false;
    }
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

// 1.2
void reverse(char *str) {
    if (str == NULL) {
        return;
    }
    char *end = str;
    while (*end != '\0') {
        ++end;
    }
    --end;
    char *start = str;
    char tmp;
    while (start < end) {
        tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
    return;
}

// 1.3
bool isPermutation(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    int length = min((int)str1.length(), 256);
    int *array = new int[length]();
    int index1, index2;
    for (int i = 0; i < str1.length(); ++i) {
        index1 = (int)str1[i];
        array[index1]++;
        index2 = (int)str2[i];
        array[index2]--;
    }
    for (int i = 0; i < length; ++i) {
        if (array[i] != 0) {
            return false;
        }
    }
    delete array;
    return true;
}

// 1.4
void replaceAllSpaces(string &input, int length) {
    int number_spaces = 0;
    for (int i = 0; i < length; ++i) {
        if (input[i] == ' ') {
            number_spaces++;
        }
    }
    char tmp;
    int new_length = length + 2 * number_spaces;
    input[new_length] = '\0';
    while (number_spaces > 0) {
        tmp = input[length - 1];
        if (tmp != ' ') {
            input[new_length - 1] = tmp;
            length--;
            new_length--;
        } else {
            input[new_length - 1] = '0';
            input[new_length - 2] = '2';
            input[new_length - 3] = '%';
            length--;
            new_length -= 3;
            number_spaces--;
        }
    }
}

// main function
int main() {
    // test 1.1
//    string str = "helo world";
//    cout << isAllUnique(str) << endl;
    
    // test 1.2
//    char str[] = "world";
//    reverse(str);
//    cout << str << endl;
    
    // test 1.3
//    string str1 = "hello";
//    string str2 = "ollhe";
//    cout << isPermutation(str1, str2) << endl;
    
    // test 1.4
//    string str1 = "Mr John Smith         ";
//    replaceAllSpaces(str1, 13);
//    cout << str1 << endl;
}
