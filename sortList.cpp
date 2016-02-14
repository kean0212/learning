#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    void merge(ListNode* &tail, ListNode* head1, ListNode* head2, ListNode* &cur_ptr) {
        ListNode head_res(0);
        ListNode* tail_res = &head_res;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                tail_res->next = head1;
                head1 = head1->next;
            } else {
                tail_res->next = head2;
                head2 = head2->next;
            }
            tail_res = tail_res->next;
        }
        tail_res->next = head1 ? head1 : head2;
        while (tail_res->next) {
            tail_res = tail_res->next;
        }
        tail_res->next = cur_ptr;
        tail->next = head_res.next;
        tail = tail_res;
    }
    // split the list and update the cur_ptr
    void subList(ListNode* &cur_ptr, ListNode* &head, int cur_size) {
        head = cur_ptr;
        for (int i = 0; i < cur_size - 1 && cur_ptr; ++i) {
            cur_ptr = cur_ptr->next;
        }
        if (cur_ptr) {
            ListNode* temp = cur_ptr->next;
            cur_ptr->next = NULL;
            cur_ptr = temp;
        }
    }

public:
    void outputList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur_ptr = head;
        int length = 0;
        while (cur_ptr) {
            length++;
            cur_ptr = cur_ptr->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* head_first, *head_second, *tail;
        for (int cur_size = 1; cur_size < length; cur_size <<= 1) {
            cur_ptr = head;
            tail = &dummy;
            while (cur_ptr) {
                subList(cur_ptr, head_first, cur_size);
//                outputList(head_first);
                subList(cur_ptr, head_second, cur_size);
//                outputList(head_second);
                merge(tail, head_first, head_second, cur_ptr);
//                outputList(head);
            }
        }
        return dummy.next;
    }
};

int main() {
    Solution s;
    ListNode n1(3);
    ListNode n2(1);
    n1.next = &n2;
    ListNode* res = s.sortList(&n1);
    s.outputList(res);
}