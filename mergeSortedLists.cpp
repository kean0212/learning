#include <iostream>

using namespace std;

struct  ListNode {
	int val;
	ListNode* next;
	ListNode(int v) : next(NULL) {
		val = v;
	}
};

ListNode* mergeSortedLists(ListNode* head1, ListNode* head2) {
	if (!head1) {
		return head2;
	}
	if (!head2) {
		return head1;
	}
	ListNode* head = NULL;
	ListNode* tail = NULL;
	while (head1 && head2) {
		if (head1->val <= head2->val) {
			if (!head) {
				head = head1;
				tail = head1;
			} else {
				tail->next = head1;
				tail = tail->next;
			}
			head1 = head1->next;
		} else {
			if (!head) {
				head = head2;
				tail = head2;
			} else {
				tail->next = head2;
				tail = tail->next;
			}
			head2 = head2->next;
		}
	}
	if (!head1) {
		tail->next = head2;
	} else {
		tail->next = head1;
	}
	return head;
}

ListNode* sort(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* ptr1 = head;
	ListNode* ptr2 = head;
	while (ptr2 && ptr2->next && ptr2->next->next) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	ptr2 = ptr1->next;
	ptr1->next = NULL;
	ListNode* first_sorted_list = sort(head);
	ListNode* second_sorted_list = sort(ptr2);
	return mergeSortedLists(first_sorted_list, second_sorted_list);
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