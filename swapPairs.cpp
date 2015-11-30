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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        head = second;
        ListNode* last = NULL;
        while (first && second) {
            ListNode* temp = second->next;
            second->next = first;
            first->next = temp;
            if (last) {
                last->next = second;
            }
            last = first;
            if ((first = temp)) {
                second = first->next;
            } else {
                second = NULL;
            }
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    ListNode* res = s.swapPairs(&n1);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}