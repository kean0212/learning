#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head_first = NULL;
        ListNode* tail_first = NULL;
        ListNode* head_second = NULL;
        ListNode* tail_second = NULL;
        while (head) {
            if (head->val < x) {
                if (!head_first) {
                    head_first = head;
                    tail_first = head;
                } else {
                    tail_first->next = head;
                    tail_first = head;
                }
            } else {
                if (!head_second) {
                    head_second = head;
                    tail_second = head;
                } else {
                    tail_second->next = head;
                    tail_second = head;
                }
            }
            head = head->next;
        }
        if (!head_first) {
            return head_second;
        } else {
            tail_first->next = head_second;
            head_second ? tail_second->next = NULL : NULL;
            return head_first;
        }
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(4);
    ListNode n3(2);
    n1.next = &n2;
    n2.next = &n3;
    Solution s;
    ListNode* res = s.partition(&n1, 3);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}