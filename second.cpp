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
#include <limits>

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
    Node *more = addLists(n1->next, n2->next, carry);
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

vector<list<BTNode *> > generateListsPO(BTNode *root) {
    vector<list<BTNode *> > lists;
    generateLists(lists, root, 0);
    return lists;
}

// using BFS
vector<list<BTNode *> > generateLists(BTNode *root) {
    vector<list<BTNode *> > lists;
    if (root == NULL) {
        return lists;
    }
    list<BTNode *> current;
    current.push_back(root);
    list<BTNode *> parents;
    while (!current.empty()) {
        lists.push_back(current);
        parents = current;
        current.clear();
        for (BTNode *parent : parents) {
            if (parent->left != NULL) {
                current.push_back(parent->left);
            }
            if (parent->right != NULL) {
                current.push_back(parent->right);
            }
        }
    }
    return lists;
}

// 4.5
// using in-order traversal
bool isBSTIO(BTNode *root, int *last) {
    if (root == NULL) {
        return true;
    }
    if (!isBSTIO(root->left, last)) {
        return false;
    }
    if (last != NULL && *last > root->data) {
        return false;
    }
    last = &(root->data);
    if (!isBSTIO(root->right, last)) {
        return false;
    }
    return true;
}

bool isBSTOne(BTNode *root) {
    int *last = NULL;
    return isBSTIO(root, last);
}

// using left <= top < right
bool isBSTDF(BTNode *root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    if (root->data <= min || root->data > max) {
        return false;
    }
    if (!isBSTDF(root->left, min, root->data) ||
        !isBSTDF(root->right, root->data, max)) {
        return false;
    }
    return true;
}

bool isBSTTWo(BTNode *root) {
    return isBSTDF(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}

// 4.6
class TreeNode2 {
public:
    int data;
    TreeNode2 *left;
    TreeNode2 *right;
    TreeNode2 *parent;
};

TreeNode2 *inorderTraverse(TreeNode2 *n) {
    while (n->left != NULL) {
        n = n->left;
    }
    return n;
}

TreeNode2 *findInorderSuccessor(TreeNode2 *n) {
    if (n == NULL) {
        return NULL;
    }
    if (n->right != NULL) {
        return inorderTraverse(n->right);
    } else {
        TreeNode2 *x = n;
        TreeNode2 *p = n->parent;
        while (p != NULL && p->left != x) {
            x = p;
            p = p->parent;
        }
        return p;
    }
}

// 4.7
class Result {
public:
    BTNode *node;
    bool isAncestor;
    Result(BTNode *n, bool b) {
        node = n;
        isAncestor = b;
    }
    Result(const Result &res) { // shallow copy
        node = res.node;
        isAncestor = res.isAncestor;
    }
};

Result findCommonAncestorHelper(BTNode *root, BTNode *a, BTNode *b) {
    if (root == NULL) {
        return Result(NULL, false);
    }
    if (root == a && root == b) {
        return Result(root, true);
    }
    
    Result left_res = findCommonAncestorHelper(root->left, a, b);
    if (left_res.isAncestor) {
        return left_res;
    }
    Result right_res = findCommonAncestorHelper(root->right, a, b);
    if (right_res.isAncestor) {
        return right_res;
    }
    
    if (left_res.node != NULL && right_res.node != NULL) {
        return Result(root, true);
    } else if (root == a || root == b) {
        bool flag = left_res.node != NULL || right_res.node != NULL ? true : false;
        return Result(root, true);
    } else {
        return Result(left_res.node != NULL ? left_res.node : right_res.node, false);
    }
}

BTNode *findCommonAncestor(BTNode *root, BTNode *a, BTNode *b) {
    Result res = findCommonAncestorHelper(root, a, b);
    if (res.isAncestor) {
        return res.node;
    }
    return NULL;
}

// 4.8
bool matchTree(BTNode *a, BTNode *b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a == NULL || b == NULL) {
        return false;
    }
    if (a->data != b->data) {
        return false;
    }
    if (!matchTree(a->left, b->left) ||
        !matchTree(a->right, b->right)) {
        return false;
    }
    return true;
}

bool isSubtree(BTNode *a, BTNode *b) {
    if (b == NULL) {
        return true;
    }
    if (a == NULL) {
        return false;
    }
    if (a->data == b->data) {
        if (matchTree(a, b)) {
            return true;
        }
    }
    return isSubtree(a->left, b) || isSubtree(a->right, b);
}

// 4.9
int depth(BTNode *root) {
    if (root == NULL) {
        return 0;
    }
    return max(depth(root->left), depth(root->right)) + 1;
}

void printArray(int *array, int start, int end) {
    for (int i = start; i <= end; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void printAllPaths(BTNode *root, int sum, int *array, int level) {
    if (root == NULL) {
        return;
    }
    
    array[level] = root->data;
    
    int s = 0;
    for (int i = level; i >= 0; --i) {
        s += array[i];
        if (s == sum) {
            printArray(array, i, level);
        }
    }
    
    printAllPaths(root->left, sum, array, level + 1);
    printAllPaths(root->right, sum, array, level + 1);
    
    return;
}

void printAllPaths(BTNode *root, int sum) {
    int depth_tree = depth(root);
    int *array = new int[depth_tree];
    printAllPaths(root, sum, array, 0);
}

// 5.1
int insert(int N, int M, int i, int j) {
    int mask1 = (1 << (j + 1)) - 1;
    int mask2 = (1 << i) - 1;
    int mask = mask1 ^ mask2;
    int n_cleared = N & mask;
    return n_cleared | (M << i);
}

// 5.2
void printBinaryRep(double x) {
    if (x <= 0 || x >= 1) {
        cout << "Error" << endl;
        return;
    }
    double frac = 0.5;
    string res = ".";
    res.reserve(32);
    int count = 0;
    while (x != 0) {
        if (count > 30) {
            cout << "Error" << endl;
            return;
        }
        if (x >= frac) {
            res += "1";
            x -= frac;
        } else {
            res += "0";
        }
        frac *= 0.5;
        count++;
    }
    cout << res << endl;
}

// 5.3
int getNextSmallest(int n) {
    int num_zeros = 0;
    int num_ones = 0;
    while ((n & 1) == 1) {
        num_ones++;
        n >>= 1;
    }
    if (n == 0) { // 0000.....11111 || 11111...11111
        return -1;
    }
    while ((n & 1) == 0) {
        num_zeros++;
        n >>= 1;
    }
    n--; // flip the last one
    num_zeros--;
    num_ones++;
    int mask = ((1 << num_ones) - 1) << num_zeros;
    return (n << (num_zeros + num_ones)) | mask;
}

int getNextLargest(int n) {
    int num_zeros = 0;
    int num_ones = 0;
    while ((n & 1) == 0 && (n != 0)) {
        num_zeros++;
        n >>= 1;
    }
    if (n == 0) { // 0000000....00000
        return -1;
    }
    while ((n & 1) == 1) {
        num_ones++;
        n >>= 1;
    }
    if (n == 0) { // 111111....0000000
        return -1;
    }
    n++; // flip the last digit
    num_ones--;
    num_zeros++;
    int mask = (1 << num_ones) - 1;
    return (n << (num_ones + num_zeros)) | mask;
}

// 5.5
int countFlips(int A, int B) {
    int count = 0;
    for (int C = A ^ B; C != 0; C = C & (C - 1)) {
        count++;
    }
    return count;
}

// 5.6
int swapOddEven(int a) {
    return ((a & 0xaaaaaaaa) >> 1) | ((a & 0x55555555) << 1);
}

// 5.7
// My solution - more space-efficient
void findMissingIntHelper(list<int> &array, int bit, int *res) {
    if (array.empty()) {
        return;
    }
    
    list<int>::iterator it;
    // count the numbers of 0's and 1's at bit
    int num_zeros = 0;
    int num_ones = 0;
    for (it = array.begin(); it != array.end(); ++it) {
        (*it & (1 << bit)) > 0 ? num_ones++ : num_zeros++;
    }
    
    // find out which is missing
    bool missingOne = num_zeros > num_ones ? true : false;
    if (missingOne) {
        *res |= (1 << bit);
    }
    
    bool isOne;
    for (it = array.begin(); it != array.end(); ++it) {
        isOne = (*it & (1 << bit)) > 0 ? true : false;
        if (missingOne && !isOne) { // 1 is missing, then erase all ints with 0 at bit
            array.erase(it);
        }
        if (!missingOne && isOne) { // 0 is missing, then erase all ints with 1 at bit
            array.erase(it);
        }
    }
    
    findMissingIntHelper(array, bit + 1, res);
}

int findMissingInt(list<int> array) {
    int res = 0;
    findMissingIntHelper(array, 0, &res);
    return res;
}

// The solution on book - more readable
int fetch(int i, int j) {
    int res;
    (i & (1 << j)) > 0 ? res = 1 : res = 0;
    return res;
}

int findMissingIntHelperTwo(list<int> l, int bit) {
    if (l.empty()) {
        return 0;
    }
    list<int> oneBits;
    list<int> zeroBits;
    for (int i : l) {
        fetch(i, bit) == 1 ? oneBits.push_back(i) : zeroBits.push_back(i);
    }
    
    if (zeroBits.size() > oneBits.size()) {
        return (findMissingIntHelperTwo(oneBits, bit + 1) << 1) | 1;
    } else {
        return (findMissingIntHelperTwo(zeroBits, bit + 1) << 1) | 0;
    }
}

int findMissingIntTwo(list<int> l) {
    return findMissingIntHelperTwo(l, 0);
}

// 5.8
using byte = unsigned char;
void drawHorizontalLine(byte array[], int w, int x1, int x2, int y) {
    // x1 is not necessarily to the left of x2
    int left = x1, right = x2;
    if (x1 > x2) {
        left = x2;
        right = x1;
    }
    
    // calculate the positions of the bytes
    int above_bytes = y * w / 8;
    int left_bytes = left / 8;
    int left_offset = left % 8;
    int right_bytes = right / 8;
    int right_offset = right % 8;
    
    // create masks
    int left_mask = ~0 >> left_offset;
    int right_mask = ~0 << (7 - right_offset);
    
    if (left_bytes == right_bytes) {
        // if they are in the same byte
        array[above_bytes + left_bytes] |= (left_mask & right_mask);
    } else {
        // if they are in different bytes
        array[above_bytes + left_bytes] |= left_mask;
        for (int i = above_bytes + left_bytes + 1; i < above_bytes + right_bytes; ++i) {
            array[i] = ~0;
        }
        array[above_bytes + right_bytes] |= right_mask;
    }
}

// Generate a list of primes from 2 through max
void crossoff(vector<bool> &flags, int prime) {
    for (int i = prime * prime; i < flags.size(); i += prime) {
        flags[i] = false;
    }
}

int getNextPrime(vector<bool> flags, int prime) {
    int next = prime + 1;
    while (next < flags.size() && !flags[next]) {
        next++;
    }
    return next;
}

vector<bool> sieveOfEratosthenes(int max) {
    vector<bool> flags(max + 1, true);
    flags[0] = false;
    flags[1] = false;
    int prime = 2;
    while (prime <= sqrt(max)) {
        crossoff(flags, prime);
        prime = getNextPrime(flags, prime);
        if (prime >= flags.size()) {
            break;
        }
    }
    return flags;
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
    
    // test 5.2
//    double x = 0.75;
//    printBinaryRep(x);
    
    // test 5.3
//    int a = 15;
//    cout << getNextSmallest(a) << endl;
//    int b = 0;
//    cout << getNextLargest(b) << endl;
    
    // test 5.5
//    int a = 29, b = 15;
//    cout << countFlips(a, b) << endl;
    
    // test 5.7
//    int array[] = {0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12};
//    list<int> l(array, array + sizeof(array) / sizeof(int));
//    list<int>::iterator it;
//    for (it = l.begin(); it != l.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << endl;
//    cout << findMissingInt(l) << endl;
//    cout << findMissingIntTwo(l) << endl;
    
    // test i++ and ++i
//    int i = 2;
//    cout << i++ << endl; // 2
//    cout << ++i << endl; // 4
    
    // test for sieve of eratosthenes
//    int max = 30;
//    vector<bool> res = sieveOfEratosthenes(max);
//    for (int i = 0; i < res.size(); ++i) {
//        if (res[i]) {
//            cout << i << " ";
//        }
//    }
//    cout << endl;
}