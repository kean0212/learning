#include <iostream>

using namespace  std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;
        while (first != NULL && second != NULL) {
            first = first->next;
            second = second->next == NULL ? NULL : second->next->next;
            if (first == second) {
                break;
            }
        }
        if (first == NULL || second == NULL) {
            return NULL;
        }
        second = head;
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
    
};

int main() {
    ListNode n1(3);
    ListNode n2(2);
    ListNode n3(0);
    ListNode n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n3;
    Solution s;
    ListNode* res = s.detectCycle(&n1);
    cout << res->val << endl;
}