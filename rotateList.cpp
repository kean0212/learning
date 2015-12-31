#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k <= 0) {
            return head;
        }
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        for (int i = 0; i < k; ++i) {
            if (!ptr2->next) {
                ptr2 = head;
                continue;
            } else {
                ptr2 = ptr2->next;
            }
        }
        if (ptr2 == head) {
            return head;
        }
        while (ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ListNode* new_head = ptr1->next;
        ptr1->next = NULL;
        ptr2->next = head;
        return new_head;
    }
};

int main() {
    Solution s;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    int k = 6;
    ListNode *head = s.rotateRight(&n1, k);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}