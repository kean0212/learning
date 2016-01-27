#include <queue>
#include <iostream>

using namespace std;

//class Stack {
//public:
//    queue<int> q1;
//    queue<int> q2;
//    void transfer(queue<int>& from, queue<int>& to) {
//        int n = from.size();
//        for (int i = 0; i < n - 1; ++i) {
//            to.push(from.front());
//            from.pop();
//        }
//    }
//    // Push element x onto stack.
//    void push(int x) {
//        if (q1.empty()) {
//            q2.push(x);
//        } else {
//            q1.push(x);
//        }
//    }
//
//    // Removes the element on top of the stack.
//    void pop() {
//        if (q1.empty() && q2.empty()) return;
//        if (!q1.empty()) {
//            transfer(q1, q2);
//            q1.pop();
//        } else {
//            transfer(q2, q1);
//            q2.pop();
//        }
//    }
//    // Get the top element.
//    int top() {
//        int res;
//        if (!q1.empty()) {
//            transfer(q1, q2);
//            res = q1.front();
//            q1.pop();
//            q2.push(res);
//        } else {
//            transfer(q2, q1);
//            res = q2.front();
//            q2.pop();
//            q1.push(res);
//        }
//        return res;
//    }
//
//    // Return whether the stack is empty.
//    bool empty() {
//        return q1.empty() && q2.empty();
//    }
//};
class Stack {
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }
    
    // Get the top element.
    int top() {
        return q.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.pop();
    cout << s.empty() << endl;
    cout << s.q1.empty() << endl;
    cout << s.q2.empty() << endl;
}