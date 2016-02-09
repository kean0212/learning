#include <iostream>
#include <unordered_map>

using namespace  std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//class Solution {
//public:
//    RandomListNode *copyRandomList(RandomListNode *head) {
//        if (!head) return NULL;
//        unordered_map<RandomListNode*, RandomListNode*> mapping;
//        RandomListNode* res_head = new RandomListNode(0);
//        RandomListNode* res_tail = res_head;
//        while (head) {
//            if (!mapping.count(head)) {
//                mapping[head] = new RandomListNode(head->label);
//            }
//            if (head->random) {
//                if (!mapping.count(head->random)) {
//                    mapping[head->random] = new RandomListNode(head->random->label);
//                }
//                mapping[head]->random = mapping[head->random];
//            }
//            res_tail->next = mapping[head];
//            res_tail = mapping[head];
//            head = head->next;
//        }
//        return res_head->next;
//    }
//};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* head_dup = head;
        while (head) {
            RandomListNode* temp = head->next;
            head->next = new RandomListNode(head->label);
            head->next->next = temp;
            head = temp;
        }
        head = head_dup;
        while (head) {
            if (head->random)
                head->next->random = head->random->next;
            head = head->next->next;
        }
        RandomListNode* res_head = new RandomListNode(0);
        RandomListNode* res_tail = res_head;
        head = head_dup;
        while (head) {
            res_tail->next = head->next;
            res_tail = head->next;
            head->next = head->next->next;
            head = head->next;
        }
        return res_head->next;
    }
};

int main() {
    Solution s;
    RandomListNode* head = new RandomListNode(-1);
    head->random = head;
    RandomListNode* res = s.copyRandomList(head);
    while (res) {
        cout << res->label << " ";
        res = res->next;
    }
    cout << endl;
}