#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* reverseList(ListNode* l1) {
        ListNode* head = l1;
        ListNode* tail = l1;
        l1 = l1->next;
        while (l1) {
            ListNode* temp = l1->next;
            l1->next = head;
            head = l1;
            l1 = temp;
        }
        tail->next = NULL;
        return head;
    }
    void mergeLists(ListNode* &l1, ListNode* &l2) {
        while (l2) {
            ListNode* temp1 = l1->next;
            l1->next = l2;
            l1 = temp1;
            ListNode* temp2 = l2->next;
            l2->next = l1;
            l2 = temp2;
        }
        if (l1) l1->next = NULL;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        // find the start of the second half
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            slow = slow->next;
        }
        // reverse the second half
        fast = reverseList(slow);
        slow = head;
        // insert the second half to the first one
        mergeLists(slow, fast);
    }
};
int main() {
    Solution s;
    
}