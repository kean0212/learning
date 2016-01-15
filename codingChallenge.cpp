#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Merge two sorted lists in-place
void merge(ListNode* &head1, ListNode* &head2) {
    ListNode head(1);
    ListNode* tail = &head;
    while (head1 && head2) {
        if (head1->val < head2->val) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    tail->next = head1 ? head1 : head2;
}

// Sort the list in-place using merge
void sortList(ListNode* &head) {
    if (!head || !head->next) {
        return;
    }
    ListNode* head1 = head;
    ListNode* head2 = head->next;
    while (head2 && head2->next) {
        head1 = head1->next;
        head2 = head2->next->next;
    }
    head2 = head1->next;
    head1->next = NULL;
    sortList(head);
    sortList(head2);
    merge(head, head2);
}

// Test if a list is sorted in ascending order
// Print FAIL if it's not, otherwise PASS
void test(ListNode* l) {
    if (!l || !l->next) {
        cout << "PASS" << endl;
        return;
    }
    while (l && l->next) {
        if (l->next->val < l->val) {
            cout << "FAIL" << endl;
            return;
        }
    }
    cout << "PASS" << endl;
}

int main() {
    ListNode n1(-4);
    ListNode n2(-3);
    ListNode n3(-2);
    ListNode n4(-1);
    ListNode n5(0);
    ListNode n6(1);
    ListNode n7(2);
    ListNode n8(3);
    ListNode n9(4);
    ListNode n10(4);
    
    // case 1 - empty list
    ListNode* l1 = NULL;
    sortList(l1);
    cout << "Empty List: ";
    test(l1);
    
    // case 2 - ascending list of odd length
    ListNode* l2 = &n1;
    n1.next = &n2;
    n2.next = &n3;
    sortList(l2);
    cout << "Ascending List of Odd Length: ";
    test(l2);
    
    // case 3 - ascending list of even length
    ListNode* l3 = &n1;
    n3.next = &n4;
    sortList(l3);
    cout << "Asending List of Even Length: ";
    test(l3);
    
    // case 4 - descending list of odd length
    ListNode* l4 = &n9;
    n9.next = &n8;
    n8.next = &n7;
    sortList(l4);
    cout << "Descending List of Odd Length: ";
    test(l4);
    
    // case 5 - descending list of even length
    ListNode* l5 = &n9;
    n7.next = &n6;
    sortList(l5);
    cout << "Descending List of Even Lenght: ";
    test(l5);
    
    // case 6 - list with duplicates
    ListNode* l6 = &n9;
    n6.next = &n10;
    sortList(l6);
    cout << "Descending List with Duplicates: ";
    test(l6);
    
    // case 7 - combine all previous situations
    ListNode* l7 = &n8;
    n8.next = &n2;
    n2.next = &n10;
    n10.next = &n3;
    n3.next = &n9;
    n9.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n1;
    n1.next = NULL;
    sortList(l7);
    cout << "Combined Test: ";
    test(l7);
}