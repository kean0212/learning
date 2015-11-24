#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//class MinStack {
//    struct Node {
//        int val;
//        Node *next;
//        Node(int v) {
//            val = v;
//            next = NULL;
//        }
//    };
//    Node *head = NULL;
//    unordered_map<Node *, int> hash_table; // storing the minimum corresponding to each head
//public:
//    void push(int x) {
//        if (head == NULL) {
//            head = new Node(x);
//            hash_table[head] = x;
//        } else {
//            Node *temp = head;
//            head = new Node(x);
//            head->next = temp;
//            hash_table[head] = min(x, hash_table[temp]);
//        }
//    }
//
//    void pop() {
//        if (head) {
//            Node *temp = head;
//            head = head->next;
//            hash_table.erase(temp);
//            delete(temp);
//        }
//    }
//
//    int top() {
//        return head->val;
//    }
//
//    int getMin() {
//        return hash_table[head];
//    }
//};

class MinStack {
    vector<int> stack;
    vector<int> mins;
public:
    void push(int x) {
        stack.push_back(x);
        if (!mins.empty()) {
            mins.push_back(min(x, mins.back()));
        } else {
            mins.push_back(x);
        }
    }
    
    void pop() {
        if(!stack.empty()) {
            stack.pop_back();
            mins.pop_back();
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return mins.back();
    }
};

int main() {
    MinStack stack;
    stack.push(3);
    stack.push(2);
    cout << stack.top() << endl;
    stack.push(-2);
    cout << stack.getMin() << endl;
    stack.pop();
    stack.pop();
    cout << stack.getMin() << endl;
}
