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
#include <unordered_set>

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

// 1.7
void update(int **mat, int M, int N) {
    bool has_zero_at_top = false;
    bool has_zero_at_left = false;
    for (int i = 0; i < N; ++i) {
        if (mat[0][i] == 0) {
            has_zero_at_top = true;
            break;
        }
    }
    for (int i = 0; i < M; ++i) {
        if (mat[i][0] == 0) {
            has_zero_at_left = true;
            break;
        }
    }
    for (int i = 1; i < M; ++i) {
        for (int j = 1; j < N; ++j) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        if (mat[0][i] == 0) {
            for (int j = 1; j < M; ++j) {
                mat[j][i] = 0;
            }
        }
    }
    for (int i = 1; i < M; ++i) {
        if (mat[i][0] == 0) {
            for (int j = 1; j < N; ++j) {
                mat[i][j] = 0;
            }
        }
    }
    if (has_zero_at_top) {
        for (int i = 0; i < N; ++i) {
            mat[0][i] = 0;
        }
    }
    if (has_zero_at_left) {
        for (int i = 0; i < M; ++i) {
            mat[i][0] = 0;
        }
    }
}

// 1.8
bool isSubstring(string s1, string s2) {
    size_t found = s2.find(s1);
    if (found != string::npos) {
        return true;
    } else {
        return false;
    }
}

bool isRotation(string s1, string s2) {
    int length = s1.length();
    if (length == s2.length() && length > 0) {
        return isSubstring(s1, s2 + s2);
    }
    return false;
}

// 2.1
class Node {
    
public:
    int data;
    Node *next;

    int getData() {
        return data;
    }
    
    Node *getNext() {
        return next;
    }
};

Node *removeDuplicates(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *n = head;
    unordered_set<int> hash;
    int current_data;
    while (n->next != NULL) {
        current_data = n->next->data;
        if (hash.count(current_data) == 0) {
            hash.insert(current_data);
        } else {
            n->next = n->next->next;
        }
        n = n->next;
    }
    return head;
}

// follow up
Node *removeDuplicatesFU(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *first_ptr = head;
    Node *second_ptr;
    while (first_ptr != NULL) {
        second_ptr = first_ptr;
        while (second_ptr->next != NULL) {
            if (second_ptr->next->data == first_ptr->data) {
                second_ptr->next = second_ptr->next->next;
            } else {
                second_ptr = second_ptr->next;
            }
        }
        first_ptr = first_ptr->next;
    }
    return head;
}

// 2.2 iterative solution
Node *findKthToLast(Node *head, int k) {
    if (k <= 0) {
        return NULL;
    }
    Node *first = head;
    Node *second = head;
    for (int i = 0; i < k - 1; ++i) {
        if (second == NULL) {
            return NULL;
        }
        second = second->next;
    }
    if (second == NULL) {
        return NULL;
    }
    while (second->next != NULL) {
        first = first->next;
        second = second->next;
    }
    return first;
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
    
    // test 1.8
//    string s1 = "waterbottle";
//    string s2 = "erbottlewat";
//    cout << isRotation(s1, s2) << endl;
}
