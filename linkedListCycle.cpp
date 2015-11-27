#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *slow_ptr = head;
        ListNode *fast_ptr = head->next->next;;
        while (fast_ptr && fast_ptr->next) {
            if (slow_ptr == fast_ptr) {
                return true;
            }
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return false;
    }
};

int main() {
    Solution s;
}
