#include <iostream>

using namespace std;

struct  ListNode {
	int val;
	ListNode* next;
	ListNode(int v) : next(NULL) {
		val = v;
	}
};

ListNode* merge(ListNode* head1, ListNode* head2) {
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
	return head.next;
}

ListNode* sort(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* ptr1 = head;
	ListNode* ptr2 = head->next;
	while (ptr2 && ptr2->next) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	ptr2 = ptr1->next;
	ptr1->next = NULL;
	ListNode* first_sorted_list = sort(head);
	ListNode* second_sorted_list = sort(ptr2);
	return merge(first_sorted_list, second_sorted_list);
}

int main() {
	ListNode n1(5);
	ListNode n2(2);
	ListNode n3(6);
	ListNode n4(3);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	// ListNode* res = sort(&n1);
	ListNode* head = NULL;
	ListNode* res = sort(head);
	while (res) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
}