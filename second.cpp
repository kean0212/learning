//
//  cc150.cpp
//  
//
//  Created by qifan li on 2015-10-09.
//
//

#include <iostream>
#include <algorithm>
#include <string>

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

// 1.5
//string compress(string str) {
//    if (str.length() <= 2) {
//        return str;
//    }
//    string new_str = "";
//    char current_char = str[0];
//    int count = 1;
//    for (int i = 0; i < str.length(); ++i) {
//        if (str[i] != current_char) {
//            new_str = new_str + current_char + to_string(count);
//            current_char = str[i];
//            count = 1;
//        } else {
//            count++;
//        }
//    }
//    new_str = new_str + current_char + to_string(count);
//    return new_str.length() < str.length() ? new_str : str;
//}

int lengthOfCompression(string str) {
    int length = 0;
    char last_char = str[0];
    int count = 1;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == last_char) {
            count++;
        } else {
            length += 1 + to_string(count).length();
            last_char = str[i];
            count = 1;
        }
    }
    length += 1 + to_string(count).length();
    return length;
}

string compress(string str) {
    if (str.length() <= 2) {
        return str;
    }
    int length_of_compression = lengthOfCompression(str);
    if (length_of_compression >= str.length()) {
        return str;
    }
    string res;
    res.reserve(length_of_compression);
    char last_char = str[0];
    int count = 1;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == last_char) {
            count++;
        } else {
            res += last_char + to_string(count);
            last_char = str[i];
            count = 1;
        }
    }
    res += last_char + to_string(count);
    return res;
}

// 1.6
// since it's in-place, it has to be NxN matrix
void rotate90(int **image, int n) {
    for (int layer = 0; layer < n / 2; ++layer) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            // save the top
            int tmp = image[first][i];
            // left -> top
            image[first][i] = image[last - offset][first];
            // bottom -> left
            image[last - offset][first] = image[last][last - offset];
            // right -> bottom
            image[last][last - offset] = image[i][last];
            // top -> right
            image[i][last] = tmp;
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

    // test 1.5
//    string str = "aabcccccaaa";
//    cout << compress(str) << endl;
}
