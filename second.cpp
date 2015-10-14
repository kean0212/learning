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
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <list>

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
    
    Node(int d, Node *n) {
        data = d;
        next = n;
    }
    
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

// 2.3
bool deleteNode(Node *n) {
    if (n == NULL) {
        return false;
    }
    if (n->next == NULL) {
        n = NULL;
        return true;
    }
    n->data = n->next->data;
    n->next = n->next->next;
    return true;
}

// 2.4
Node *partition(Node *head, int x) {
    Node *head_first = NULL;
    Node *tail_first = NULL;
    Node *head_second = NULL;
    Node *tail_second = NULL;
    while (head != NULL) {
        if (head->data < x) {
            if (head_first == NULL) {
                head_first = head;
                tail_first = head;
            } else {
                tail_first->next = head;
                tail_first = head;
            }
        } else {
            if (head_second == NULL) {
                head_second = head;
                tail_second = head;
            } else {
                tail_second->next = head;
                tail_second = head;
            }
        }
        head = head->next;
    }
    if (head_first == NULL && head_second != NULL) {
        tail_second->next = NULL;
        return head_second;
    }
    if (head_first != NULL && head_second == NULL) {
        tail_first->next = NULL;
        return head_first;
    }
    tail_first->next = head_second;
    tail_second->next= NULL;
    return head_first;
}

// 2.5
Node *add(Node *n1, Node *n2, int carry) {
    if (n1 == NULL && n2 == NULL && carry == 0) {
        return NULL;
    }
    int val = carry;
    if (n1 != NULL) {
        val += n1->data;
    }
    if (n2 != NULL) {
        val += n2->data;
    }
    Node *res = new Node(val % 10, NULL);
    if (n1 != NULL || n2 != NULL) {
        Node *more = add(n1 == NULL ? NULL : n1->next,
                         n2 == NULL ? NULL : n2->next,
                         val > 10 ? 1 : 0);
        res->next = more;
    }
    return res;
}

// Follow up
int countListLength(Node *n) {
    int count = 0;
    while (n != NULL) {
        count++;
        n = n->next;
    }
    return count;
}

Node *padList(Node *n, int length) {
    for (int i = 0; i < length; ++i) {
        Node *new_node = new Node(0, n);
        n = new_node;
    }
    return n;
}

Node *addLists(Node *n1, Node *n2, int &carry) {
    if (n1 == NULL && n2 == NULL) {
        carry = 0;
        return NULL;
    }
    Node *more = addLists(n1, n2, carry);
    int val = carry + n1->data + n2->data;
    Node *res= new Node(val % 10, more);
    carry = val / 10;
    return res;
}

Node *addFU(Node *n1, Node *n2) {
    if (n1 == NULL) {
        return n2;
    }
    if (n2 == NULL) {
        return n1;
    }
    int length1 = countListLength(n1);
    int length2 = countListLength(n2);
    if (length1 < length2) {
        n1 = padList(n1, length2 - length1);
    } else if (length1 > length2) {
        n2 = padList(n2, length1 - length2);
    }
    int carry = 0;
    Node *res = addLists(n1, n2, carry);
    if (carry == 0) {
        return res;
    } else {
        Node *new_res = new Node(carry, res);
        return new_res;
    }
}

// 2.6
Node *getStartOfLoop(Node *head) {
    Node *slow_ptr = head;
    Node *fast_ptr = head;
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr) {
            break;
        }
    }
    if (fast_ptr == NULL || slow_ptr == NULL) {
        return NULL;
    }
    fast_ptr = head;
    while (slow_ptr != fast_ptr) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }
    return slow_ptr;
}

// 2.7
// using stack
bool isPalindrome(Node *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    Node *slow_ptr = head;
    Node *fast_ptr = head;
    stack<Node *> s;
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        s.push(slow_ptr);
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    if (fast_ptr->next == NULL) {
        slow_ptr = slow_ptr->next;
    }
    while (slow_ptr != NULL) {
        if (slow_ptr->data != s.top()->data) {
            return false;
        }
        s.pop();
        slow_ptr = slow_ptr->next;
    }
    return true;
}

// using recursion

// 4.1
class TreeNode {
public:
    
    TreeNode *left;
    TreeNode *right;
};

int checkHeight(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = checkHeight(root->left);
    if (left_height == -1) {
        return -1;
    }
    int right_height = checkHeight(root->right);
    if (right_height == -1) {
        return -1;
    }
    if (abs(left_height - right_height) <= 1) {
        return max(left_height, right_height) + 1;
    } else {
        return -1;
    }
}

bool isBSTBalanced(TreeNode *root) {
    if (checkHeight(root) == -1) {
        return false;
    } else {
        return true;
    }
}

// 4.2
class GraphNode {
public:
    bool isVisited = false;
    vector<GraphNode *> children;
};

bool isConnected(GraphNode *A, GraphNode *B) {
    if (A == NULL || B == NULL) {
        return false;
    }
    queue<GraphNode *> q;
    q.push(A);
    GraphNode *tmp;
    while (!q.empty()) {
        tmp = q.front();
        if (tmp != NULL && !tmp->isVisited) {
            if (tmp == B) {
                return true;
            }
            tmp->isVisited = true;
            for (GraphNode *n : tmp->children) {
                q.push(n);
            }
        }
        q.pop();
    }
    return false;
}

// 4.3
class BSTNode {
public:
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int d, BSTNode *l, BSTNode *r) {
        data = d;
        left = l;
        right = r;
    }
};

BSTNode *constructBST(int array[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    BSTNode *res = new BSTNode(array[mid], NULL, NULL);
    res->left = constructBST(array, start, mid - 1);
    res->right = constructBST(array, mid + 1, end);
    return res;
}

BSTNode *constructBST(int array[], int length) {
    if (array == NULL) {
        return NULL;
    }
    return constructBST(array, 0, length - 1);
}

// 4.4
class BTNode {
public:
    int data;
    BTNode *left;
    BTNode *right;
    BTNode(int d, BTNode *l, BTNode *r) {
        data = d;
        left = l;
        right = r;
    }
};
// using pre-order traversal
void generateLists(vector<list<BTNode *> > &lists, BTNode *root, int height) {
    if (root == NULL) {
        return;
    }
    if (height < lists.size()) {
        lists[height].push_back(root);
    } else {
        list<BTNode *> l;
        l.push_back(root);
        lists.push_back(l);
    }
    generateLists(lists, root->left, height + 1);
    generateLists(lists, root->right, height + 1);
}
vector<list<BTNode *> > generateLists(BTNode *root) {
    vector<list<BTNode *> > lists;
    generateLists(lists, root, 0);
    return lists;
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
