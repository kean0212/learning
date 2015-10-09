#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <limits>
#include <fstream>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define NAME_SIZE 50

class Person {
    int id;
    char name[NAME_SIZE];
    
public:
    Person() : id(5) {
        id = 12;
    }
    void aboutMe() {
        cout << "I'm a Person" << endl;
    }
};

class Student : private Person {
public:
    void aboutMe() {
        cout << "I'm a student" << endl;
    }
};

int func(int a, int b = 3) {
    return b;
}

bool areAllCharsUnique(string str) {
    unordered_set<char> hashTable;
    for (int i = 0; i < str.length(); i++) {
        if (hashTable.find(str[i]) == hashTable.end()) {
            hashTable.insert(str[i]);
        } else {
            return false;
        }
    }
    return true;
}

//void reverse(char *str) {
//    char *end = str;
//    for (; *end != '\0'; end++);
//    end--;
//    char temp;
//    while (str < end) {
//        temp = *str;
//        *str = *end;
//        *end = temp;
//        str++;
//        end--;
//    }
//}

//void reverse(char *str) {
//    char *end = str;
//    char tmp;
//    if (str) {
//        while (*end) {
//            ++end;
//        }
//        --end;
//        while (str < end) {
//            tmp = *str;
//            *str++ = *end;
//            *end-- = tmp;
//        }
//    }
//}

void reverse(char *str) {
    int i = 0;
    for (; str[i] != '\0'; i++);
    i--;
    cout << i << endl;
    char temp;
    int left = 0, right = i;
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

bool isPermutation(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    int A[128];
    for (int i = 0; i < str1.length(); i++) {
        int c1 = str1[i];
        int c2 = str2[i];
        A[c1]++;
        A[c2]--;
    }
    for (int i = 0; i < str1.length(); i++) {
        if (A[i] != 0) {
            return false;
        }
    }
    return true;
}

void replaceWhitespace(string str, int trueLength) {
    // calculate the number of replacement
    int count = (str.length() - trueLength) / 2;
    int index = trueLength - 1;
    // scan the string from back to front
    for (int i = str.length()-1; i >= 0; ) {
        if (count == 0) {
            // if all replacements have been finished
            break;
        }
        if (str[index] == ' ') {
            // if there is a white space, replace three characters
            str[i] = '0';
            str[i-1] = '2';
            str[i-2] = '%';
            i = i - 3;
            count--;
        } else {
            // if not, replace one character
            str[i] = str[index];
            i--;
        }
        index--;
    }
}

int lengthOfInt(int integer) {
    stringstream ss;
    ss << integer;
    return ss.str().length();
}

string compress(string str) {
    // if the length is <= 1, just return the original string
    if (str.length() == 0) {
        return str;
    }
    // if the length is > 0
    stringstream ss;
    int size = 1;
    char currentChar = str[0];
    int count = 1;
    ss << currentChar;
    // iterate the chars in the string
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == currentChar) {
            count++;
        } else {
            ss << count;
            ss << str[i];
            currentChar = str[i];
            count = 1;
            size += lengthOfInt(count) + 1;
        }
    }
    ss << count;
    size += lengthOfInt(count);
    // after compression, if it's not smaller than the original one
    if (size >= str.length()) {
        return str;
    }
    return ss.str();
}

class Node {
public:
    Node *next = NULL;
    int data;
    Node(int d) {
        next = NULL;
        data = d;
    }
   void appendToTail(int d) {
        Node *end = new Node(d);
        Node *currentNode = this;
        while (currentNode->next) {
            currentNode = currentNode->next;
        }
        currentNode->next = end;
    }
};

Node *addTwoLists(Node *A, Node *B, int &carry) {
    if (A == NULL && B != NULL) {
        carry = 0;
        return B;
    }
    if (A != NULL && B == NULL) {
        carry = 0;
        return A;
    }
    Node *newNode = new Node(0);
    if (A->next == NULL && B->next == NULL) {
        int sum = A->data + B->data;
        carry = sum >= 10 ? 1 : 0;
        newNode->data = sum % 10;
        return newNode;
    }
    newNode->next = addTwoLists(A->next == NULL ? A : A->next,
                                B->next == NULL ? B : B->next,
                                carry);
    int sum = A->data + B->data + carry;
    newNode->data = sum % 10;
    carry = sum >= 10 ? 1 : 0;
    return newNode;
}

void printList(Node *A) {
    while (A != NULL) {
        cout << A->data << " ";
        A = A->next;
    }
    cout << endl;
}

bool isIsomorphic(string s, string t) {
    vector<int> array(256, 257);
    cout << array['a'] << endl;
    for(int i = 0; i < s.length(); i++) {
        int difference = array[(int)s[i]];
        cout << difference << endl;
        if(difference != 257) {
            if(difference != t[i] - s[i]) {
                return false;
            }
        } else {
            array[(int)s[i]] = t[i] - s[i];
        }
    }
    return true;
}

bool recursion(int rowOfStart, int colOfStart, vector<vector<char> >& board, int index, string word) {
    bool res = false;

    // if the current char doesn't match
    char curChar;
    if((curChar = board[rowOfStart][colOfStart]) != word[index]) {
        return false;
    }

    // base case
    if(index == word.length() - 1) {
        return true;
    }
   
    board[rowOfStart][colOfStart] = '*';
    
    // if start is matching with the char in word, then continue
    // test the left char
    if(colOfStart > 0) {
        res = recursion(rowOfStart, colOfStart - 1, board, index + 1, word);
    }
    // test the right char
    if(!res && colOfStart < board[0].size() - 1) {
        res = recursion(rowOfStart, colOfStart + 1, board, index + 1, word);
    }
    // test the top char
    if(!res && rowOfStart > 0) {
        res = recursion(rowOfStart - 1, colOfStart, board, index + 1, word);
    }
    // test the bottom char
    if(!res && rowOfStart < board.size() - 1) { // assume that all colums have the same length
        res = recursion(rowOfStart + 1, colOfStart, board, index + 1, word);
    }
    
    // reset the corresponding spot in arrayOfVisited
    board[rowOfStart][colOfStart] = curChar;
    
    return res;
}

bool exist(vector<vector<char> >& board, string word) {
    // test if the word is null
    if(word == "") {
        return true;
    }
    //find the the chars same as the first in word
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            if(recursion(i, j, board, 0, word)) {
                return true;
            }
        }
    }
    return false;
}

vector<string> summaryRanges(vector<int>& nums) {
    stringstream ss;
    vector<string> res;
    if (nums.empty()) {
        return res;
    }
    int start = nums[0];
    int end = nums[0];
    for (int index = 1; index < nums.size(); index++) {
        if (nums[index] != end + 1) {
            ss << "\"" << start << "->" << end << "\"";
            res.push_back(ss.str());
            ss.str("");
            start = nums[index];
            end = nums[index];
        } else {
            end ++;
        }
    }
    if (start == end) {
        ss << "\"" << start << "\"";
        res.push_back(ss.str());
    } else {
        ss << "\"" << start << "->" << end << "\"";
        res.push_back(ss.str());
    }
    return res;
}

struct Result {
    int *i;
    bool isInt;
    Result(int *i, bool isInt) {
        this->i = i;
        this->isInt = isInt;
    }
};

void test() {
    return;
}

//void helper(int n, int &count) {
//    if (n <= 0) {
//        return;
//    } else if (n == 1) {//|| n == 2 || n == 3) {
//        count++;
//    } else if (n == 2) {
//        count++;
//        helper(n - 1, count);
//    } else if (n == 3) {
//        count++;
//        helper(n - 1, count);
//        helper(n - 2, count);
//    }else {
//        helper(n - 1, count);
//        helper(n - 2, count);
//        helper(n - 3, count);
//    }
//}
//
//int countWays(int n) {
//    int res = 0;
//    if (n > 0) {
//        helper(n, res);
//    }
//    return res;
//}

void helper(int n, vector<int> &array) {
    if (n <= 0) {
        return;
    }
    if (n == 1) {
        array[1] = 1;
        return;
    }
    if (n == 2) {
        array[2] = 2;
        return;
    }
    if (n == 3) {
//        cout << "hello" << endl;
        array[3] = 4;
//        cout << "world" << endl;
        return;
    }
    if (array[n - 3] == 0) {
        helper(n - 3, array);
        if (array[n - 2] == 0) {
            helper(n - 2, array);
            if (array[n - 1] == 0) {
                helper(n - 1, array);
            }
        }
    }
    array[n] = array[n -3] + array[n - 2] + array[n -1];
    return;
}

int countWays(int n) {
    vector<int> array(n + 1, 0);
    if (n > 0) {
        helper(n, array);
    }
//    cout << n << endl;
    return array[n];
}

int countWaysTwo(int n, vector<int> &array) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else if (array[n] != 0) {
        return array[n];
    } else {
        array[n] = countWaysTwo(n-1, array) +
                   countWaysTwo(n-2, array) +
                   countWaysTwo(n-3, array);
        return array[n];
    }
    
}

int countPaths(int x, int y) {
    if (x == 0 && y == 0) {
        return 1;
    }
    int p1 = 0;
    if (x > 0) {
        p1 = countPaths(x - 1, y);
    }
    int p2 = 0;
    if (y > 0) {
        p2 = countPaths(x, y - 1);
    }
    return p1 + p2;
}

int countPathsDP(int x, int y, vector<vector<int> > &map) {
	int res = 0;
	if (x == 0 && y == 0) {
		return 1;
	}
	if (map[y][x] != 0) {
		return map[y][x];
	}
	if (x > 0) {
		res += countPathsDP(x - 1, y, map);
	}
	if (y > 0) {
		res += countPathsDP(x, y - 1, map);
	}
	map[y][x] = res;
	return res;
}

void rotate(vector<int>& nums, int k) {
    int length = nums.size();
    if ((k = k % length) == 0) {
        return;
    }
    if (k <= length / 2) {
        for (int i = 0; i < k; i++) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    } else {
        for (int i = 0; i < length - k; i++) {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }
}

int add(int a, int b) {
    int length = 8 * sizeof(int);
    int res = 0;
    int pass = 0;
    for (int i = 0; i < length; i++) {
        int bitA = a >> i & 1;
        int bitB = b >> i & 1;
        int bitRes = bitA ^ bitB ^ pass;
        if (bitRes == 0 && (bitA || bitB || pass)) {
            pass = 1;
        } else {
            pass = 0;
        }
        res = res | bitRes << i;
    }
    if (pass) {
        return -1; // overflow
    } else {
        return res;
    }
}

int add2(int a, int b) {
    if (b == 0) {
        return a;
    }
    int summary = a ^ b;
    int pass = (a & b) << 1;
    return add2(summary, pass);
}

int subtract(int a, int b) {
    int negativeB = add2(~b, 1);
    return add2(a, negativeB);
}

int multiply(int a, int b) {
    int sum = 0;
    int length = 8 * sizeof(int);
    for (int i = 0; i < length; i++) {
        // get the i-th bit of b
        if ((1 << i) & b) {
            sum = add2(sum, a << i);
        }
    }
    return sum;
}

void helperParenthesis(string str, unordered_set<string> &res) {
    for (int i = 0; i < str.length(); i++) {
        string temp = str;
        res.insert(temp.insert(i, "()"));
    }
}

unordered_set<string> nPairsParenthesis(int n) {
    unordered_set<string> res;
    if (n == 0) {
        res.insert("");
        return res;
    }
    if (n == 1) {
        res.insert("()");
        return res;
    }
    unordered_set<string> prevRes = nPairsParenthesis(n - 1);
    for (auto it = prevRes.begin(); it != prevRes.end(); it++) {
        helperParenthesis(*it, res);
    }
    return res;
}

int countWaysDPHelper(int n, vector<int> &array) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (array[n] != 0) {
        return array[n];
    }
    array[n] = countWaysDPHelper(n - 25, array) +
               countWaysDPHelper(n - 10, array) +
               countWaysDPHelper(n -  5, array) +
               countWaysDPHelper(n -  1, array);
    return array[n];
}

int countWaysDP(int n) {
    vector<int> array(n + 1, 0);
    return countWaysDPHelper(n, array);
}

void merge(int a[], int b[], int sizeA, int sizeB) {
    int indexA = sizeA - 1;
    int indexB = sizeB - 1;
    int indexMerged = sizeA + sizeB - 1;
    while (indexB >= 0) {
        if (indexA >= 0 && a[indexA] > b[indexB]) {
            a[indexMerged] = a[indexA];
            indexA--;
        } else {
            a[indexMerged] = b[indexB];
            indexB--;
        }
        indexMerged--;
    }
}

string getKey(string s) {
    char *temp = new char(s.length());
    strcpy(temp, s.c_str());
    sort(temp, temp + s.length());
    string res(temp);
    delete temp;
    return res;
}

void sort(string array[], int n) {
    // build buckets
    map<string, vector<string> > hash;
    for (int i = 0; i < n; i++) {
        string s = array[i];
        string key = getKey(s);
        if (!hash.count(key)) {
            vector<string> stringList;
            hash[key] = stringList;
        }
        hash[key].push_back(s);
    }
    // update the array
    int index = 0;
    map<string, vector<string> >::iterator it;
    for (it = hash.begin(); it != hash.end(); it++) {
        for (string s : it->second) {
            array[index] = s;
            index++;
        }
    }
}

int findChangingPos(int array[], int n, int low, int high) {
    if (low == high - 1) {
        if (array[low] > array[high]) {
            return high;
        } else {
            return -1;
        }
    }
    int mid = (low + high) / 2;
//    cout << "low " << low << endl;
//    cout << "high " << high << endl;
    if (array[low] < array[mid]) {
        return findChangingPos(array, n, mid, high);
    } else {
        return findChangingPos(array, n, low, mid);
    }
}

int find(string array[], int low, int high, string s) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    string midString = array[mid];
    if (midString != "") {
        if (midString < s) {
            // right part
            return find(array, mid + 1, high, s);
        } else if (midString > s) {
            // left part
            return find(array, low, mid - 1, s);
        } else {
            return mid;
        }
    } else {
        int res = -1;
        if ((res = find(array, low, mid - 1, s)) == -1) {
            res = find(array, mid + 1, high, s);
        }
        return res;
    }
}

int calculate(string s) {
    int a = s[0] - '0';
    int b = s[2] - '0';
    switch (s[1]) {
        case '&':
            return a & b;
            
        case '|':
            return a | b;
            
        case '^':
            return a ^ b;
    }
}

int countWays(string s, int expected, map<string, int> &hash) {
    int res = 0;
    // test if s is valid
    if (s == "") {
        return 0;
    }
    if (hash.count(s) != 0) {
        return hash[s];
    }
    // base case
    if (s.length() == 3) {
        if (calculate(s) == expected) {
            return 1;
        } else {
            return 0;
        }
    }
    // iterate through the string and do the calculation
    for (int i = 0; i < s.length() - 2; i+=2) {
        string tempStr = s.substr(i, 3);
        int tempRes = calculate(tempStr);
        string newStr = s.substr(0, i) + to_string(tempRes) + s.substr(i + 3);
        res += countWays(newStr, expected, hash);
    }
    hash[s] = res;
    return res;
}

bool isDivisible(int i, unordered_map<int, bool> &hash) {
    if (hash.count(i) != 0) {
        return hash[i];
    }
    if (i == 1) {
        return true;
    }
    bool res;
    if (i % 3 == 0) {
        res = isDivisible(i / 3, hash);
    } else if (i % 5 == 0) {
        res = isDivisible(i / 5, hash);
    } else if (i % 7 == 0) {
        res = isDivisible(i / 7, hash);
    } else {
        res = false;
    }
    hash[i] = res;
    return res;
}

int computeKth(int k) {
    int count = 0;
    int res = 3 * 5 * 7;
    int i = 1;
    unordered_map<int, bool> hash;
    for (; count <= k - 1; i++) {
        if (isDivisible(i, hash)) {
            cout << "i: "  << i << endl;
            count++;
        }
    }
    return (i - 1) * res;
}

int countKth(int k) {
    if (k < 0) {
        return -1;
    }
    int res = 0;
    queue<int> q3;
    queue<int> q5;
    queue<int> q7;
    q3.push(1);
    int int_max = numeric_limits<int>::max();
    for (int i = 0; i < k; i++) {
        int q3_head = q3.size() > 0 ? q3.front() : int_max;
        int q5_head = q5.size() > 0 ? q5.front() : int_max;
        int q7_head = q7.size() > 0 ? q7.front() : int_max;
        res = min(q3_head, min(q5_head, q7_head));
        if (res == q3_head) {
            q3.pop();
            q3.push(3 * res);
            q5.push(5 * res);
        } else if (res == q5_head) {
            q5.pop();
            q5.push(5 * res);
        } else {
            q7.pop();
        }
        q7.push(7 * res);
    }
    return res;
}

int getBit(int a, int i) {
    return (1 << i & a) >= 1;
}

int setBit(int a, int i) {
    return (1 << i) | a;
}

// 3
int clearBit(int a, int i) {
    int mask = ~(1 << i);
    return a & mask;
}

int clearBitHigh(int a, int i) {
    int mask = (1 << i) - 1;
    return a & mask;
}

//int clearBitLow(int a, int i) {
//    int mask = ~(-1 >>> (31 - i));
//    return a & mask;
//}

int updateBit(int a, int i, int v) {
    return (~(1 << i) & a) | (v << i);
}

string printBinary(double n) {
    string res = "";
    if (n < 0.0 || n >= 1.0) {
        res = "Invalid Input";
        return res;
    }
    stringstream ss;
    int i = 0;
    for (; i < 32; i++) {
        if (n == 0.0) {
            break;
        }
        if (2 * n >= 1.0) {
            ss << 1;
            n = 2 * n - 1.0;
        } else {
            ss << 0;
            n = 2 * n;
        }
    }
    if (i == 32 && n != 0.0) {
        res = "ERROR";
    } else {
        res = ss.str();
    }
    return res;
}

int countZeros(int a) {
    int res = 0;
    while (a != 1) {
        a >>= 1;
        res++;
    }
    return res;
}

int getNextSmallest(int n) {
    if (n == 1) {
        return -1;
    }
    int mask = n ^ (n - 1);
    int LSDs = n & mask;
    int count = 1;
    int extra = 0;
    while ((extra = countZeros(LSDs) - count) < 0) {
        n = n & (~mask);
        count++;
        mask = n ^ (n - 1);
        LSDs = n & mask;
    }
    return (n - 1) & (~((1 << extra) - 1));
}

int findFirstZero(int a) {
    for (int i = 0; i < 8 * sizeof(int); i++) {
        if ((a & (1 << i)) == 0) {
            return i;
        }
    }
    return -1;
}

int getNextBiggest(int n) {
    int index = findFirstZero(n);
    if (index == -1) {
        return -1;
    }
    int LSDs = ((1 << index) - 1) & n;
    int MSDs = n - LSDs;
    LSDs <<= 1;
    return MSDs | LSDs;
}

void printLastKLines(char *fileName, int k) {
    if (k <= 0) {
        cout << "Invalid k" << endl;
        return;
    }
    queue<string> buffer;
    ifstream infile(fileName);
    string line = "";
    while (getline(infile, line)) {
        if (buffer.size() == k) {
            buffer.pop();
        }
        buffer.push(line);
    }
    if (buffer.size() < k) {
        cout << "Not enough lines in the file" << endl;
        return;
    }
    while (buffer.size() > 0) {
        cout << buffer.front() << endl;
        buffer.pop();
    }
}

void *testVoidPtr() {
    void **p2 = (void **)malloc(100);
    return p2;
}

void swap(int a, int b) {
    cout << "a " << a << endl;
    cout << "b " << b << endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a " << a << endl;
    cout << "b " << b << endl;
}

int countFives(int n, vector<int> &array) {
    if (array[n] != -1) {
        return array[n];
    }
    if (n % 5 != 0) {
        array[n] = 0;
        return 0;
    } else {
        int prevCount = countFives(n/5, array);
        array[n] = 1 + prevCount;
        return array[n];
    }
}

int countTrailingZeroes(int n) {
    int res = 0;
    vector<int> array(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        res += countFives(i, array);
    }
    return res;
}

int countTrailingZeroes2(int n) {
    int count = 0;
    for (int i = 5; n / i > 0; i*=5) {
        count += n / i;
    }
    return count;
}

void countHitsAndPseudoHits(string solution, string guess) {
    int hit = 0;
    int pseudo_hit = 0;
    unordered_map<char, int> hash_solution, hash_guess;
    for (int i = 0; i < solution.length(); ++i) {
        char char_solution = solution[i];
        char char_guess = guess[i];
        if (char_solution == char_guess) {
            hit++;
        } else {
            hash_solution[char_solution]++;
            hash_guess[char_guess]++;
        }
    }
    unordered_map<char, int>::iterator it;
    for (it = hash_solution.begin(); it != hash_solution.end(); ++it) {
        pseudo_hit += min(it->second, hash_guess[it->first]);
    }
    cout << "hit " << hit << endl;
    cout << "pseudo_hit " << pseudo_hit << endl;
}

void testMultidimensionalArray(int a[][4]) {
    
}

string units[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string words[] = {"", "Thousand", "Million", "Billion"};

string convert(int n) {
    string res = "";
    if (n >= 1 && n <= 9) {
        return units[n - 1];
    }
    if (n >= 10 && n <= 19) {
        return teens[n - 10];
    }
    if (n >= 20 && n < 100) {
        string space = " ";
        if (n % 10 == 0) {
            space = "";
        }
        res = tens[(n - 20)/10] + space + convert(n % 10);
    }
    if (n >= 100 && n < 1000) {
        string space = " ";
        if (n % 100 == 0) {
            space = "";
        }
        res = convert(n / 100) + " Hundred" + space + convert(n % 100);
    }
    return res;
}

void printEnglishPhrase(int n) {
    string res = "";
    int count = 0;
    while (n != 0) {
        string comma = "";
        if (count != 0 && n % 1000 != 0) {
            comma = ", ";
        }
        res = convert(n % 1000) + " " + words[count] +comma + res;
        count++;
        n /= 1000;
    }
    cout << res << endl;
}
int main(void)
{
//    Student *std = new Student();
//    std->aboutMe();
//    delete std;
//
//    int a = 12;
//    int &b = a;
//    b = 14;
//    cout << a << endl;
//
//    char *p = new char[2];
//    p[0] = 'a';
//    p[1] = 'b';
//    p++;
//    cout << *p << endl;
//
//
//    cout << (-10 % 360) << endl;

//    string str = "abcdef";
//    cout << areAllCharsUnique(str) << endl;

//    char str[] = "abcdef";
//    reverse(str);
//    cout << str << endl;
    
//    string str1 = "hello world";
//    string str2 = "world hello";
//    cout << isPermutation(str1, str2) << endl;
   
//    string str1 = "he llo world    ";
//    replaceWhitespace(str1, 12);
//    cout << str1 << endl;
    
//    string str = "aaa";
//    cout << compress(str) << endl;
    
//    Node n1(10);
//    Node n2(20);
//    n1.appendToTail(20);

//    Node *A1 = new Node(2);
//    A1->appendToTail(3);
//    A1->appendToTail(8);
//    A1 = NULL;
//    A->data = 6;
//    Node *B1 = new Node(2);
//    B1->appendToTail(4);
//    B1->appendToTail(5);
//    B->data = 2;
//    int carry = 0;
//    Node *result = addTwoLists(A1, B1, carry);
//    printList(result);
    
//    string a = "aa";
//    string b = "bb";
//    cout << isIsomorphic(a, b) << endl;
//    
//    vector<char> a1;
//    a1.push_back('A');
//    a1.push_back('B');
//    a1.push_back('C');
//    a1.push_back('E');
//    vector<char> a2;
//    a2.push_back('S');
//    a2.push_back('F');
//    a2.push_back('C');
//    a2.push_back('S');
//    vector<char> a3;
//    a3.push_back('A');
//    a3.push_back('D');
//    a3.push_back('E');
//    a3.push_back('E');
//    vector<vector<char> > board;
//    board.push_back(a3);
//    board.push_back(a2);
//    board.push_back(a1);
//    string word = "ABCB";
//    cout << exist(board, word) << endl;
    
//    vector<char> b1(4, 'a');
//    vector<char> b2(4, 'a');
//    vector<char> b3(4, 'a');
//    vector<vector<char> > board2;
//    board2.push_back(b1);
//    board2.push_back(b2);
//    board2.push_back(b3);
//    string word2 = "aaaaaaaaaaab";
//    cout << exist(board2, word2) << endl;
    
//    vector<char> c(1, 'a');
//    vector<vector<char> > board3;
//    board3.push_back(c);
//    string word3 = "a";
//    cout << exist(board3, word3) << endl;
    
//    int myints[1] = {-1};
//    vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
//    vector<string> res = summaryRanges(fifth);
//    cout << res.size() << endl;
//    cout << res[0] << endl;
//    cout << res[1] << endl;
//    cout << res[2] << endl;
    
//    Result test(NULL, false);
//    cout << test.isInt << endl;

//    test();
    
//    cout << countWays(5) << endl;
    
//    vector<int> array(6, 0);
//    cout << countWaysTwo(5, array) << endl;
//    int y = 20;
//	  int x = 20;
//	  vector<vector<int> > map(y + 1, vector<int>(x + 1));
//    cout << countPathsDP(x, y, map) << endl;
//    cout << countPaths(x, y) << endl;
    
//    vector<int> nums;
//    for (int i = 1; i < 7; i++) {
//        nums.push_back(i);
//    }
//    rotate(nums, 7);
//    for (int i = 0; i < nums.size(); i++) {
//        cout << nums[i] << " ";
//    }
//    cout << endl;

//    int a = 32;
//    int b = 3;
//    cout << add2(a, b) << endl;
    
//    int b = -2;
//    int c = -3;
//    cout << "b = " << b << endl;
//    cout << "c = " << c << endl;
//    cout << "b - c = " << subtract(b, c) << endl;
//    int a = 21;
//    int b = -3;
//    cout << multiply(a, b) << endl;
    
//    int n = 0;
//    unordered_set<string> res = nPairsParenthesis(n);
//    for (auto it = res.begin(); it != res.end(); it++) {
//        cout << *it << endl;
//    }

//    int n = 10;
//    cout << countWaysDP(n) << endl;
    
//    vector<int> row(4, 0);
//    vector<vector<int> > map(5, row);
//    cout << map.size() << endl;
//    cout << map[2][1] << endl;
    
//    int a[10] = {2, 4, 5, 8};
//    int b[5] = {1, 3, 7, 9, 10};
//    merge(a, b, 4, 5);
//    for (int i = 0; i < 9; i++) {
//        cout << a[i] << " ";
//    }
    
//    vector<int> v(50, 1);
//    for (int a : v) {
//        cout << a << " ";
//    }
    
//    string a = "hello";
//    char *b = new char(a.length());
//    strcpy(b, a.c_str());
//    sort(b, b+a.length());
//    cout << b << endl;
    
//    string a = "hello";
//    cout << getKey(a) << endl;
    
//    string test[5] = {"hello", "world", "ellho", "word", "dlorw"};
//    sort(test, 5);
//    for (int i = 0; i < 5; i++) {
//        cout << test[i] << " ";
//    }
//    cout << endl;

//    int array[12] = {15, 16, 19, 20, 25, 26, 3, 4, 5, 7, 10, 14};
//    cout << findChangingPos(array, 12, 0, 11) << endl;
//    for (int i = 0; i < 12; i++) {
//        if (array[i + 1] < array[i]) {
//            cout << i + 1 << endl;
//        }
//    }
    
//    string a = "hello";
//    string b = "hemlo";
//    cout << (b < a) << endl;
//    string array[13] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
//    cout << find(array, 0, 12, "ball") << endl;
    
//    string a = "1&1^0|1|1^0";
//    map<string, int> hash;
//    cout << countWays(a, 0, hash) << endl;

//    cout << -3 / 2 << endl;
//    cout << -8 % 5 << endl;
    
//    cout << ~(-5) + 1 << endl;
    
//    cout << countKth(1213) << endl;
//    cout << computeKth(213) << endl;
    
//    cout << printBinary(0.625) << endl;
//    cout << getNextSmallest(164) << endl;
//    cout << getNextBiggest(25) << endl;

//    char fileName[] = "backup.sh";
//    printLastKLines(fileName, 5);
    
//    int i = 1;
//    int j = ++i;
//    cout << "i " << i << endl;
//    cout << "j " << j << endl;
//    int k = 1;
//    int l = k++;
//    cout << "k " << k << endl;
//    cout << "l " << l << endl;
    
//    void *buffer = malloc(1400);
//    size_t begining = (size_t)buffer;
//    cout << begining << endl;
//    cout << begining % 128 << endl;
    
//    char *str;
//    
//    /* Initial memory allocation */
//    str = (char *) malloc(15);
//    strcpy(str, "tutorialspoint");
//    printf("String = %s,  Address = %u\n", str, str);
//    
//    /* Reallocating memory */
//    str = (char *) realloc(str, 10);
//    strcat(str, ".com");
//    printf("String = %s,  Address = %u\n", str, str);
//    
//    free(str);
    
//    void *p = malloc(100);
//    cout << p << endl;
//    cout << p + 10 << endl;
//    cout << (size_t)p + 10 << endl;
//    size_t array[5] = {1, 2, 3, 4, 5};
//    size_t *second = array + 1;
//    cout << sizeof(size_t) << endl;
//    cout << *second << endl;
//    cout << second[-1] << endl;
    
//    string array[4] = {"hello", "world", "it's", "Qifan"};
//    cout << array << endl;
//    string *second = array + 1;
//    cout << sizeof(*second) << endl;
//    cout << *second << endl;
//    cout << second[-1] << endl;
//    void *p = testVoidPtr();
//    cout << p[0] << endl;
//    cout << p << endl;
    
//    const int a = 5;
//    int array[a] = {1, 2, 3, 4, 5};
    
//    int a = 5;
//    int b = 6;
//    swap(a, b);
    
//    cout << countTrailingZeroes(1000000) << endl;
//    cout << countTrailingZeroes2(1000000) << endl;
    
//    string a = "hello";
//    cout << a[0] << endl;
    
//    string solution = "RGBY";
//    string guess = "YGRR";
//    countHitsAndPseudoHits(solution, guess);
    printEnglishPhrase(2000);
    return 0;
}