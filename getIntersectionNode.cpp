#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while (tempA != NULL || tempB != NULL) {
            if (tempA == tempB) {
                return tempA;
            }
            if (tempA != NULL) {
                lengthA++;
                tempA = tempA->next;
            }
            if (tempB != NULL) {
                lengthB++;
                tempB = tempB->next;
            }
        }
        if (lengthA > lengthB) {
            tempA = headA;
            headA = headB;
            headB = tempA;
        }
        int diff = abs(lengthA - lengthB);
        for (int i = 0; i < diff; ++i) {
            headB = headB->next;
        }
        while (headA != NULL && headB != NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

int main() {
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);
    a1.next = &a2;
    a2.next = &c1;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    c3.next = NULL;
    
    Solution s;
    ListNode *intersection = s.getIntersectionNode(&a1, &b1);
    cout << (intersection == &c1) << endl;
}