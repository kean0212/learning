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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        while (true) {
            if (carry == 0 && temp1 == NULL && temp2 == NULL) {
                break;
            }
            int sum = 0;
            if (temp1) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2) {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            sum += carry;
            carry = sum > 9 ? 1 : 0;
            ListNode* new_tail = new ListNode(sum % 10);
            tail->next = new_tail;
            tail = new_tail;
        }
        return head->next;
    }
};

int main() {
    ListNode l1(0);
    ListNode l2(0);
    Solution s;
    ListNode* res = s.addTwoNumbers(&l1, &l2);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}